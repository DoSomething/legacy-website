import Chart from 'chart.js';
import $ from 'jquery';
import setting from '../utilities/Setting';

/*
 * Number formatter so we can display the goal as a number with commas.
 */
const numberWithCommas = function(num) {
  return num.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ',');
};

/*
 * Calculates the number of days between two dates.
 */
const dateDiff = function(date1, date2) {
  const oneDay = 24 * 60 * 60 * 1000; // hours*minutes*seconds*milliseconds

  return Math.abs((date1.getTime() - date2.getTime()) / (oneDay));
};

/*
 * Creates an array of days between the start and end date.
 */
const getDays = function(startDate, endDate) {
  const dateArray = [];
  let currentDate = startDate;

  const ExtendedDate = Date;

  ExtendedDate.prototype.addDays = function(days) {
    const d = new ExtendedDate(this.valueOf());
    d.setDate(d.getDate() + days);
    return d;
  };

  while (currentDate <= endDate) {
    dateArray.push(new ExtendedDate(currentDate));
    currentDate = currentDate.addDays(1);
  }

  return dateArray;
};

/*
 * Creates an array of four dates between (and including) the start date and the end date.
 */
const getFourDates = function(startDate, endDate) {
  const numDays = dateDiff(startDate, endDate);
  const interval = Math.floor(numDays / 3);
  const date1 = new Date();
  const date2 = new Date();

  date1.setDate(startDate.getDate() + interval);
  date2.setDate(startDate.getDate() + (interval * 2));

  return [startDate, date1, date2, endDate];
};

/*
 * Creates an array of user friendly date labels from an array of timestamps
 */
const createDateLabels = function(dates) {
  const dateLabels = [];
  const monthNames = ['Jan', 'Feb', 'Mar', 'April', 'May', 'June', 'July', 'Aug', 'Sept', 'Oct', 'Nov', 'Dec'];

  if (dates) {
    dates.forEach(function(date, key) {
      const newDate = new Date(date);
      const month = newDate.getMonth();
      const day = newDate.getDate();

      dateLabels[key] = monthNames[month] + ' ' + day;
    });
  }

  return dateLabels;
};

/*
 * This function builds out an array of quantities for every label on the graph.
 * We need a value for every date, even if it is null.
 */
const createQuantityArray = function(dates, dateLabels, quantities) {
  // Create quantities array.
  const values = [];

  if (dateLabels) {
    dateLabels.forEach(function(value, key) {
      const index = dates.indexOf(value);

      // If we have a quantity for this date,
      // add it to the array in the correct position.
      // Otherwise, make it null.
      if (index > -1) {
        values[key] = quantities[index];
      } else {
        values[key] = null;
      }
    });
  }

  return values;
};

/*
 * Checks to see if we only have one point of data.
 */
const hasOnePoint = function(data) {
  return ((data.quantities) && data.quantities.length === 1) ? true : false;
};

/*
 * Creates the data object that needs to be passed to the graph
 * and adds a property that has an array of 4 dates to be highlighted in the graph.
 */
const createDataObj = function(data) {
  const yellow = '#fcd116';
  const darkYellow = '#E5BC09';
  const white = '#FFFFFF';
  const startDate = new Date(data.highSeason.start);
  const endDate = new Date(data.highSeason.end);

  // Turn the dates we recieve from the backend, and the array of all dates in the high season
  // to readable labels, so we can use them for display and comparison.
  const dates = createDateLabels(data.dates);
  const dateLabels = createDateLabels(getDays(startDate, endDate));

  // Build out the quantities array.
  const quantities = createQuantityArray(dates, dateLabels, data.quantities);

  // Use the highSeason start and end dates to determine the
  // four highlighed dates on the graph and turn those dates into labels.
  let highlightDates = getFourDates(startDate, endDate);
  highlightDates = createDateLabels(highlightDates);

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
      },
    ],
    highlighted: highlightDates,
  };
};

const lineGraph = function($el, progressData) {
  const goal = $el.data('goal');
  const data = createDataObj(progressData);
  const onePoint = hasOnePoint(progressData);

  // Extend the line graph to create a new chart type that
  // draws a goal line across the chart and highlights certain points
  // in the dataset with a point dot.
  Chart.types.Line.extend({
    name: 'lineWithGoal',

    initialize: function() {
      const helpers = Chart.helpers;
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
        },
      });

      // Iterate through each of the datasets.
      helpers.each(data.datasets, function(dataset) {
        // Empty dataset where we will put the new points we create.
        const datasetObject = {
          label: dataset.label || null,
          fillColor: dataset.fillColor,
          strokeColor: dataset.strokeColor,
          pointColor: dataset.pointColor,
          pointStrokeColor: dataset.pointStrokeColor,
          points: [],
        };
        // Build this into a property of the chart.
        this.datasets.push(datasetObject);


        // Iterate through each of the labels and create a data point for each one.
        // For each point, specify if we want it's label to display or not.
        helpers.each(data.labels, function(label, index) {
          let displayPointDot;

          // If this is one of the highlighted dates, show a dot for that point.
          if (data.highlighted.indexOf(label) > -1) {
            displayPointDot = true;
          } else {
            data.labels[index] = '';
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
            y: this.scale.endPoint,
          });
          point.save();
        }, this);
      }, this);

      // Trigger draw method.
      this.render();
    },


    // Add rendering functionality that finds where the goal point
    // lands on the graph, and draws a goal line at the point, across the graph.
    draw: function() {
      // Calculate where the goal line/label should place on the graph.
      const scale = this.scale;
      const goalPoint = scale.calculateY(goal);
      const goalLabel = numberWithCommas(goal);
      const goalLabelWidth = this.chart.ctx.measureText(goalLabel).width;
      const lineColor = '#0081BC';

      // Reset label rotation since we only show 4,
      // but there could be up to a months worth of labels so they rotate automatically.
      this.scale.xLabelRotation = 0;
      this.scale.xScalePaddingLeft = 25; // @TODO - Can this be calculated programatically.
      this.scale.xScalePaddingRight = 30;

      Chart.types.Line.prototype.draw.apply(this, arguments);

      // Place the goal number on the graph as a string.
      this.chart.ctx.textAlign = 'center';
      this.chart.ctx.fillStyle = lineColor;
      this.chart.ctx.fillText(goalLabel, scale.startPoint + 30, goalPoint);

      // Draw a dashed line after the goal number.
      this.chart.ctx.beginPath();
      this.chart.ctx.moveTo(scale.startPoint + goalLabelWidth + 5, goalPoint);
      this.chart.ctx.lineTo(scale.width - this.scale.xScalePaddingRight, goalPoint);
      this.chart.ctx.strokeStyle = lineColor;
      this.chart.ctx.lineWidth = 1;
      if (this.chart.ctx.setLineDash) {
        this.chart.ctx.setLineDash([5, 15]);
      }
      this.chart.ctx.stroke();

      // clear dashes.
      if (this.chart.ctx.setLineDash) {
        this.chart.ctx.setLineDash([]);
      }

      // Draw a grid line at each of the highlighted data points.
      Chart.helpers.each(this.scale.xLabels, function(label, index) {
        if (data.highlighted.indexOf(label) > -1) {
          // Check to see if line/bar here and decide where to place the line
          const linePos = this.scale.calculateX(index - (this.scale.offsetGridLines ? 0.5 : 0)) + Chart.helpers.aliasPixel(this.scale.lineWidth);

          ctx.beginPath();

          ctx.lineWidth = this.scale.gridLineWidth;
          ctx.strokeStyle = this.scale.gridLineColor;

          ctx.moveTo(linePos, this.scale.endPoint);
          ctx.lineTo(linePos, this.scale.startPoint - 3);
          ctx.stroke();
          ctx.closePath();

          ctx.lineWidth = this.scale.lineWidth;
          ctx.strokeStyle = this.scale.lineColor;
        }
      }, this);

      // If we only have one point, then just draw that point on the graph.
      if (onePoint) {
        Chart.helpers.each(this.datasets[0].points, function(point) {
          if (point.value !== null) {
            ctx.beginPath();

            ctx.arc(point.x, point.y, point.radius, 0, Math.PI * 2);
            ctx.closePath();

            ctx.strokeStyle = point.strokeColor;
            ctx.lineWidth = point.strokeWidth;

            ctx.fillStyle = point.fillColor;

            ctx.fill();
            ctx.stroke();
          }
        }, this);
      }
    },
  });

  // Actually instantiate the new graph and add it to the DOM.
  const ctx = $el.get(0).getContext('2d');

  // Calculate the point to scale the graph around.
  const maxDataPoint = Math.max.apply(null, data.datasets[0].data);
  const scaleMax = (goal > maxDataPoint) ? goal : maxDataPoint;

  new Chart(ctx).lineWithGoal(data, {
    showScale: true,
    scaleOverride: true,
    // Y-axis scale configuration.
    scaleSteps: 10,
    scaleStepWidth: scaleMax / 10,
    scaleStartValue: 0,
    scaleLineWidth: 1,
    scaleShowLabels: false,
    scaleFontFamily: '"Proxima Nova", "Helvetica Neue", "Helvetica", "Arial", sans-serif',
    scaleFontStyle: 'Bold',
    scaleFontColor: '#DDD',
    scaleLineColor: 'rgba(255,255,255,.1)',
    scaleFontSize: 14,
    showTooltips: false,
    scaleShowHorizontalLines: false,
    scaleShowVerticalLines: false,
    responsive: true,
    bezierCurve: false,
    pointDotRadius: 10,
    pointDotStrokeWidth: 3,
    datasetStrokeWidth: 5,
    pointDot: false,
  });
};

function init($chart = $('.js-progress-chart')) {
  if (!$chart.length) return;

  const progressData = setting('dosomethingCampaign.goals');

  lineGraph($chart, progressData);
}

export default { lineGraph, init };
