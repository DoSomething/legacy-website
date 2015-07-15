/* eslint-disable */

/* ----------------------------------------------------------
 * @TODO: ^ Enable linting by removing `eslint-disable`! ^
 * ----------------------------------------------------------
 * Linting is disabled in this file. Remove this line and
 * clean this file up according to our coding standards next
 * time it is touched.
 */

import Chart from 'chart.js';
import $ from 'jquery';
import setting from '../utilities/Setting';

/*
 * Number formatter so we can display the goal as a number with commas.
 */
var numberWithCommas = function (num) {
  return num.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");
};

/*
 * Calculates the number of days between two dates.
 */
var dateDiff = function(date1, date2) {
  var oneDay = 24*60*60*1000; // hours*minutes*seconds*milliseconds
  var firstDate = date1;
  var secondDate = date2;
  return Math.abs((firstDate.getTime() - secondDate.getTime())/(oneDay));
};

/*
 * Creates an array of days between the start and end date.
 */
var getDays = function(startDate, endDate) {
  Date.prototype.addDays = function(days) {
    var d = new Date(this.valueOf());
    d.setDate(d.getDate() + days);
    return d;
  };

  var dateArray = [];
  var currentDate = startDate;

  while (currentDate <= endDate) {
    dateArray.push( new Date (currentDate) );
    currentDate = currentDate.addDays(1);
  }

  return dateArray;
};

/*
 * Creates an array of four dates between (and including) the start date and the end date.
 */
var getFourDates = function(startDate, endDate) {
  var numDays = dateDiff(startDate, endDate);
  var interval = Math.floor(numDays / 3);

  var date1 = new Date();
  date1.setDate(startDate.getDate() + interval);

  var date2 = new Date();
  date2.setDate(startDate.getDate() + (interval * 2));

  return [startDate, date1, date2, endDate];
};

/*
 * Creates an array of user friendly date labels from an array of timestamps
 */
var createDateLabels = function(dates) {
  var dateLabels = [];
  var monthNames = ["Jan", "Feb", "Mar", "April", "May", "June", "July", "Aug", "Sept", "Oct","Nov", "Dec"];

  dates.forEach(function(date, key) {
    date = new Date(date);
    var month = date.getMonth();
    var day = date.getDate();

    dateLabels[key] = monthNames[month] + " " + day;
  });

  return dateLabels;
};

/*
 * This function builds out an array of quantities for every label on the graph.
 * We need a value for every date, even if it is null.
 */
var createQuantityArray = function(dates, dateLabels, quantities) {
  // Create quantities array.
  var values = [];

  dateLabels.forEach(function(value, key) {
    var index = dates.indexOf(value);

    // If we have a quantity for this date,
    // add it to the array in the correct position.
    // Otherwise, make it null.
    if (index > -1) {
      values[key] = quantities[index];
    }
    else {
      values[key] = null;
    }
  });

  return values;
};

/*
 * Creates the data object that needs to be passed to the graph
 * and adds a property that has an array of 4 dates to be highlighted in the graph.
 */
var createDataObj = function(data) {
  var yellow = "#fcd116";
  var darkYellow = "#E5BC09";
  var white = "#FFFFFF";

  // Use the highSeason start and end dates to determine the
  // four highlighed dates on the graph and turn those dates into labels.
  var startDate = new Date(data.highSeason.start.date);
  var endDate = new Date(data.highSeason.end.date);
  var highlightDates = getFourDates(startDate, endDate);
  highlightDates = createDateLabels(highlightDates);

  // Turn the dates we recieve from the backend, and the array of all dates in the high season
  // to readable labels, so we can use them for display and comparison.
  var dates = createDateLabels(JSON.parse(data.dates));
  var dateLabels = createDateLabels(getDays(startDate, endDate));

  // Build out the quantities array.
  var quantities = createQuantityArray(dates, dateLabels, JSON.parse(data.quantities));

  return {
    labels: dateLabels,
    datasets: [
      {
        fillColor: yellow,
        strokeColor: darkYellow,
        pointColor: white,
        pointStrokeColor: darkYellow,
        pointHighlightFill: yellow,
        pointHighlightStroke: white,
        data: quantities,
      }
    ],
    highlighted: highlightDates,
  };
};

var LineGraph = function($el, progressData) {
  var goal = $el.data('goal');
  var data = createDataObj(progressData);

  // Extend the line graph to create a new chart type that
  // draws a goal line across the chart and highlights certain points
  // in the dataset with a point dot.
  Chart.types.Line.extend({
    name: "LineWithGoal",

    initialize: function (data) {
      var helpers = Chart.helpers;
      this.datasets = [];

      // Extend the default point class, so we can pass options to the constructor,
      // For example, if this particular point should be displayed with a dot or not
      this.PointClass = Chart.Point.extend({
        strokeWidth: this.options.pointDotStrokeWidth,
        radius: this.options.pointDotRadius,
        display: false,
        hitDetectionRadius: this.options.pointHitDetectionRadius,
        ctx: this.chart.ctx,
        inRange: function(mouseX) {
          return (Math.pow(mouseX - this.x, 2) < Math.pow(this.radius + this.hitDetectionRadius, 2));
        }
      });

      // Iterate through each of the datasets.
      helpers.each(data.datasets, function(dataset) {
        // Empty dataset where we will put the new points we create.
        var datasetObject = {
          label: dataset.label || null,
          fillColor: dataset.fillColor,
          strokeColor: dataset.strokeColor,
          pointColor: dataset.pointColor,
          pointStrokeColor: dataset.pointStrokeColor,
          points: []
        };
        // Build this into a property of the chart.
        this.datasets.push(datasetObject);


        // Iterate through each of the labels and create a data point for each one.
        // For each point, specify if we want it's label to display or not.
        helpers.each(data.labels, function(label, index) {
          var displayPointDot;

          // If this is one of the highlighted dates, show a dot for that point.
          if (data.highlighted.indexOf(label) > -1) {
            displayPointDot = true;
          }
          else {
            data.labels[index] = "";
            displayPointDot = false;
          }

          // Add point to dataset.
          datasetObject.points.push(new this.PointClass({
            value: dataset.data[index],
            label: data.labels[index],
            datasetLabel: dataset.label,
            strokeColor: dataset.pointStrokeColor,
            fillColor: dataset.pointColor,
            highlightFill: dataset.pointHighlightFill || dataset.pointColor,
            highlightStroke: dataset.pointHighlightStroke || dataset.pointStrokeColor,
            display: displayPointDot,
          }));
        }, this);

        this.buildScale(data.labels);

        // Figure out where each of the points land on the canvas.
        this.eachPoints(function(point, index) {
          helpers.extend(point, {
            x: this.scale.calculateX(index),
            y: this.scale.endPoint
          });
          point.save();
        }, this);

      }, this);

      // Trigger draw method.
      this.render();
    },


    // Add rendering functionality that finds where the goal point
    // lands on the graph, and draws a goal line at the point, across the graph.
    draw: function () {
      // Reset label rotation since we only show 4,
      // but there could be up to a months worth of labels so they rotate automatically.
      this.scale.xLabelRotation = 0;
      this.scale.xScalePaddingLeft = 25; // @TODO - Can this be calculated programatically.
      this.scale.xScalePaddingRight = 30;

      Chart.types.Line.prototype.draw.apply(this, arguments);

      // Calculate where the goal line/label should place on the graph.
      var scale = this.scale;
      var goalPoint = scale.calculateY(goal);
      var goalLabel = numberWithCommas(goal);
      var goalLabelWidth = this.chart.ctx.measureText(goalLabel).width;
      var lineColor = "#0081BC";

      // Place the goal number on the graph as a string.
      this.chart.ctx.textAlign = "center";
      this.chart.ctx.fillStyle = lineColor;
      this.chart.ctx.fillText(goalLabel, scale.startPoint + 30, goalPoint);

      // Draw a dashed line after the goal number.
      this.chart.ctx.beginPath();
      this.chart.ctx.moveTo(scale.startPoint + goalLabelWidth + 5, goalPoint);
      this.chart.ctx.lineTo(scale.width - this.scale.xScalePaddingRight, goalPoint);
      this.chart.ctx.strokeStyle = lineColor;
      this.chart.ctx.lineWidth = 1;
      this.chart.ctx.setLineDash([5, 15]);
      this.chart.ctx.stroke();

      // clear dashes.
      this.chart.ctx.setLineDash([]);

      // Draw a grid line at each of the highlighted data points.
      Chart.helpers.each(this.scale.xLabels, function(label, index) {
        if (data.highlighted.indexOf(label) > -1) {
          // Check to see if line/bar here and decide where to place the line
          var linePos = this.scale.calculateX(index - (this.scale.offsetGridLines ? 0.5 : 0)) + Chart.helpers.aliasPixel(this.scale.lineWidth);

          ctx.beginPath();

          ctx.lineWidth = this.scale.gridLineWidth;
          ctx.strokeStyle = this.scale.gridLineColor;

          ctx.moveTo(linePos,this.scale.endPoint);
          ctx.lineTo(linePos,this.scale.startPoint - 3);
          ctx.stroke();
          ctx.closePath();

          ctx.lineWidth = this.scale.lineWidth;
          ctx.strokeStyle = this.scale.lineColor;
        }
      },this);
    }
  });

  // Actually instantiate the new graph and add it to the DOM.
  var ctx = $el.get(0).getContext("2d");

  new Chart(ctx).LineWithGoal(data, {
    showScale: true,
    scaleOverride: true,
    scaleSteps: 10,
    scaleStepWidth: goal / 10,
    scaleStartValue: 0,
    scaleLineWidth: 1,
    scaleShowLabels: false,
    scaleFontFamily: "'Proxima Nova', 'Helvetica Neue', 'Helvetica', 'Arial', sans-serif",
    scaleFontStyle: "Bold",
    scaleFontColor: "#DDD",
    scaleLineColor: "rgba(255,255,255,.1)",
    scaleFontSize: 14,
    showTooltips: false,
    scaleShowHorizontalLines: false,
    scaleShowVerticalLines: false,
    responsive: true,
    bezierCurve : false,
    pointDotRadius : 10,
    pointDotStrokeWidth : 3,
    datasetStrokeWidth : 5,
    pointDot: false,
  });
};

function init($chart = $(".js-progress-chart")) {
  if (!$chart.length) return;

  var progressData = setting('dosomethingCampaign.goals');
  new LineGraph($chart, progressData);
}

export default { LineGraph, init };
