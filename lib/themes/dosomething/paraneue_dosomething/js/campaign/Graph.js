import $ from 'jquery';
import Chart from 'chart.js';

var lineGraph = function($el, goal, data) {
  // Extend the line graph to create a new chart type that
  // draws a goal line across the chart.
  Chart.types.Line.extend({
    name: "LineWithGoal",
    initialize: function () {
      Chart.types.Line.prototype.initialize.apply(this, arguments);
    },
    draw: function () {
      Chart.types.Line.prototype.draw.apply(this, arguments);

      var scale = this.scale;
      var goalPoint = scale.calculateY(goal);
      var goalLabel = goal.toString();
      var goalLabelWidth = this.chart.ctx.measureText(goalLabel).width;

      this.chart.ctx.textAlign = 'center';
      this.chart.ctx.fillStyle = '#23b7fb';
      this.chart.ctx.fillText(goalLabel, scale.startPoint + 10, goalPoint);

      this.chart.ctx.beginPath();
      this.chart.ctx.moveTo(scale.startPoint + goalLabelWidth, goalPoint);
      this.chart.ctx.lineTo(scale.width, goalPoint);
      this.chart.ctx.strokeStyle = '#23b7fb';
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
    bezierCurve : false,
    pointDotRadius : 10,
    pointDotStrokeWidth : 3,
    datasetStrokeWidth : 5,
  });
}

export default lineGraph;