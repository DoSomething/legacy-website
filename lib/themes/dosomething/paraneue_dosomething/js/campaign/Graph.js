import $ from 'jquery';
import Chart from 'chart.js';

var lineGraph = function($el, goal, data) {
  Chart.types.Line.extend({
    name: "LineWithGoal",
    initialize: function () {
      Chart.types.Line.prototype.initialize.apply(this, arguments);
    },
    draw: function () {
      Chart.types.Line.prototype.draw.apply(this, arguments);
      var scale = this.scale;

      var y = scale.calculateY(goal);
      this.chart.ctx.beginPath();
      this.chart.ctx.moveTo(60, y);
      this.chart.ctx.lineTo(300, y);
      this.chart.ctx.strokeStyle = '#23b7fb';
      this.chart.ctx.lineWidth = 1;
      this.chart.ctx.setLineDash([5, 15]);
      this.chart.ctx.stroke();
      // clear dashes.
      this.chart.ctx.setLineDash([]);

      this.chart.ctx.textAlign = 'center';
      this.chart.ctx.fillStyle = '#23b7fb';
      this.chart.ctx.fillText(goal.toString(), 30, y);
    }
  });

  // Get context with jQuery - using jQuery's .get() method.
  var ctx = $el.get(0).getContext("2d");

  var myLineChart = new Chart(ctx).LineWithGoal(data, {
    showScale: true,
    scaleOverride: true,
    scaleSteps: 10,
    scaleStepWidth: 1000,
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