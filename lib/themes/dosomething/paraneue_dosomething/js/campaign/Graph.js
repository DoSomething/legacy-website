import Chart from 'chart.js';

var lineGraph = function($el, goal, data) {

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
          //@TODO - Programmatically find these points and clean this up.
          if (label === "JAN 1" || label === "JAN 10" || label === "JAN 21" || label === "JAN 31") {
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
      var goalLabel = goal.toString();
      var goalLabelWidth = this.chart.ctx.measureText(goalLabel).width;
      var lineColor = "#0081BC";

      // Place the goal number on the graph as a string.
      this.chart.ctx.textAlign = "center";
      this.chart.ctx.fillStyle = lineColor;
      this.chart.ctx.fillText(goalLabel, scale.startPoint + 10, goalPoint);

      // Draw a dashed line after the goal number.
      this.chart.ctx.beginPath();
      this.chart.ctx.moveTo(scale.startPoint + goalLabelWidth, goalPoint);
      this.chart.ctx.lineTo(scale.width - this.scale.xScalePaddingRight, goalPoint);
      this.chart.ctx.strokeStyle = lineColor;
      this.chart.ctx.lineWidth = 1;
      this.chart.ctx.setLineDash([5, 15]);
      this.chart.ctx.stroke();

      // clear dashes.
      this.chart.ctx.setLineDash([]);

      // Draw a grid line at each of the highlighted data points.
      Chart.helpers.each(this.scale.xLabels, function(label, index) {
        if (label === "JAN 1" || label === "JAN 10" || label === "JAN 21" || label === "JAN 31") {
          // var xPos = this.scale.calculateX(index) + Chart.helpers.aliasPixel(this.scale.lineWidth);
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

export default lineGraph;
