import $ from 'jquery';
import Chart from 'chart.js';

var lineGraph = function($el, goal, data) {

  // Extend the line graph to create a new chart type that
  // draws a goal line across the chart.
  Chart.types.Line.extend({
    name: "LineWithGoal",
    initialize: function (data) {
      var helpers = Chart.helpers;
      this.datasets = [];

      // Extend the default point class, so we can pass options to the constructor,
      // For example, if this particular point show be displayed with a dot or not
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

      //Iterate through each of the datasets, and build this into a property of the chart
      helpers.each(data.datasets, function(dataset, index) {

        var datasetObject = {
          label: dataset.label || null,
          fillColor: dataset.fillColor,
          strokeColor: dataset.strokeColor,
          pointColor: dataset.pointColor,
          pointStrokeColor: dataset.pointStrokeColor,
          points: []
        };

        this.datasets.push(datasetObject);


        helpers.each(data.labels, function(label, index) {
          //@TODO - figure out how to programmatically find these points
          if (label === "JAN 1" || label === "JAN 10" || label == "JAN 21") {
            var displayPoint = true;
          }
          else {
            var displayPoint = false;
          }

          datasetObject.points.push(new this.PointClass({
            value: dataset.data[index],
            label: data.labels[index],
            datasetLabel: dataset.label,
            strokeColor: dataset.pointStrokeColor,
            fillColor: dataset.pointColor,
            highlightFill: dataset.pointHighlightFill || dataset.pointColor,
            highlightStroke: dataset.pointHighlightStroke || dataset.pointStrokeColor,
            display: displayPoint,
          }));
        }, this);

        // helpers.each(dataset.data, function(dataPoint, index) {
        //   //Add a new point for each piece of data, passing any required data to draw.
        //   if (dataPoint === 3900 || dataPoint === 6300) {
        //     var displayPoint = true;
        //   }
        //   else {
        //     displayPoint = false;
        //   }

        //     datasetObject.points.push(new this.PointClass({
        //         value: dataPoint,
        //         label: data.labels[index],
        //         datasetLabel: dataset.label,
        //         strokeColor: dataset.pointStrokeColor,
        //         fillColor: dataset.pointColor,
        //         highlightFill: dataset.pointHighlightFill || dataset.pointColor,
        //         highlightStroke: dataset.pointHighlightStroke || dataset.pointStrokeColor,
        //         display: displayPoint,
        //     }));
        // }, this);

        this.buildScale(data.labels);

        this.eachPoints(function(point, index) {
          helpers.extend(point, {
            x: this.scale.calculateX(index),
            y: this.scale.endPoint
          });
          point.save();
        }, this);

      }, this);

      this.render();
    },

    draw: function () {
      Chart.types.Line.prototype.draw.apply(this, arguments);

      var scale = this.scale;
      var goalPoint = scale.calculateY(goal);
      var goalLabel = goal.toString();
      var goalLabelWidth = this.chart.ctx.measureText(goalLabel).width;

      this.chart.ctx.textAlign = 'center';
      this.chart.ctx.fillStyle = '#0081BC';
      this.chart.ctx.fillText(goalLabel, scale.startPoint + 10, goalPoint);

      this.chart.ctx.beginPath();
      this.chart.ctx.moveTo(scale.startPoint + goalLabelWidth, goalPoint);
      this.chart.ctx.lineTo(scale.width, goalPoint);
      this.chart.ctx.strokeStyle = '#0081BC';
      this.chart.ctx.lineWidth = 1;
      this.chart.ctx.setLineDash([5, 15]);
      this.chart.ctx.stroke();
      // clear dashes.
      this.chart.ctx.setLineDash([]);
    }
  });

  // Get context.
  var ctx = $el.get(0).getContext("2d");

  new Chart(ctx).LineWithGoal(data, {
    animation: false,
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
    responsive: true,
    bezierCurve : false,
    pointDotRadius : 10,
    pointDotStrokeWidth : 3,
    datasetStrokeWidth : 5,
    // pointDot : true,
  });
}

export default lineGraph;
