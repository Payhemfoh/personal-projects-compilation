"use strict";
var Visualizer = /** @class */ (function () {
    function Visualizer() {
    }
    Visualizer.drawNetwork = function (ctx, network) {
        var margin = 50;
        var left = margin;
        var top = margin;
        var width = ctx.canvas.width - (margin * 2);
        var height = ctx.canvas.height - (margin * 4);
        var levelHeight = height / network.levels.length;
        ctx.setLineDash([7, 3]);
        for (var i = network.levels.length - 1; i >= 0; --i) {
            var levelTop = top + lerp(height - levelHeight, 0, network.levels.length == 1 ? 0.5 : i / (network.levels.length - 1));
            Visualizer.drawLevel(ctx, network.levels[i], left, levelTop, width, levelHeight, i == network.levels.length - 1 ? ['^', '<', '>', '|'] : []);
        }
    };
    Visualizer.drawLevel = function (ctx, level, left, top, width, height, outputLabels) {
        var right = left + width;
        var bottom = top + height;
        var inputs = level.inputs, outputs = level.outputs, weights = level.weights, biases = level.biases;
        var nodeRadius = 15;
        for (var i = 0; i < inputs.length; ++i) {
            for (var j = 0; j < outputs.length; ++j) {
                ctx.beginPath();
                ctx.moveTo(Visualizer.getNodeX(inputs, i, left, right), bottom);
                ctx.lineTo(Visualizer.getNodeX(outputs, j, left, right), top);
                ctx.lineWidth = 2;
                ctx.strokeStyle = getRGBA(weights[i][j]);
                ctx.stroke();
            }
        }
        for (var i = 0; i < inputs.length; ++i) {
            var x = this.getNodeX(inputs, i, left, right);
            ctx.beginPath();
            ctx.arc(x, bottom, nodeRadius, 0, Math.PI * 2);
            ctx.fillStyle = "black";
            ctx.fill();
            ctx.beginPath();
            ctx.arc(x, bottom, nodeRadius * 0.6, 0, Math.PI * 2);
            ctx.fillStyle = getRGBA(inputs[i]);
            ctx.fill();
        }
        for (var i = 0; i < outputs.length; ++i) {
            var x = this.getNodeX(outputs, i, left, right);
            ctx.beginPath();
            ctx.arc(x, top, nodeRadius, 0, Math.PI * 2);
            ctx.fillStyle = "black";
            ctx.fill();
            ctx.beginPath();
            ctx.arc(x, top, nodeRadius * 0.6, 0, Math.PI * 2);
            ctx.fillStyle = getRGBA(outputs[i]);
            ctx.fill();
            ctx.beginPath();
            ctx.arc(x, top, nodeRadius * 0.8, 0, Math.PI * 2);
            ctx.strokeStyle = getRGBA(biases[i]);
            ctx.setLineDash([3, 3]);
            ctx.stroke();
            ctx.setLineDash([7, 3]);
            if (outputLabels[i]) {
                ctx.beginPath();
                ctx.textAlign = "center";
                ctx.textBaseline = "middle";
                ctx.fillStyle = "black";
                ctx.strokeStyle = "white";
                ctx.font = (nodeRadius * 1.5) + "px Arial";
                ctx.lineWidth = 0.5;
                ctx.strokeText(outputLabels[i], x, top);
            }
        }
    };
    Visualizer.getNodeX = function (nodes, index, left, right) {
        return lerp(left, right, nodes.length == 1 ?
            0.5 :
            index / (nodes.length - 1));
    };
    return Visualizer;
}());
