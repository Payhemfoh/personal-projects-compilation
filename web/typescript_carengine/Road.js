"use strict";
var Road = /** @class */ (function () {
    function Road(x, width, laneCount) {
        if (laneCount === void 0) { laneCount = 3; }
        this.x = x;
        this.width = width;
        this.laneCount = laneCount;
        this.left = x - width / 2;
        this.right = x + width / 2;
        var infinity = 1000000;
        this.top = -infinity;
        this.bottom = infinity;
        var topLeft = { x: this.left, y: this.top };
        var topRight = { x: this.right, y: this.top };
        var bottomLeft = { x: this.left, y: this.bottom };
        var bottomRight = { x: this.right, y: this.bottom };
        this.borders = [
            [topLeft, bottomLeft],
            [topRight, bottomRight]
        ];
    }
    Road.prototype.getLaneCenter = function (laneIndex) {
        var laneWidth = this.width / this.laneCount;
        return this.left + laneWidth / 2 +
            Math.min(laneIndex, this.laneCount - 1) *
                laneWidth;
    };
    Road.prototype.draw = function (ctx) {
        ctx.lineWidth = 5;
        ctx.strokeStyle = "white";
        for (var i = 1; i < this.laneCount; ++i) {
            var x = lerp(this.left, this.right, i / this.laneCount);
            ctx.setLineDash([20, 20]);
            ctx.beginPath();
            ctx.moveTo(x, this.top);
            ctx.lineTo(x, this.bottom);
            ctx.stroke();
        }
        ctx.setLineDash([]);
        this.borders.forEach(function (val) {
            ctx.beginPath();
            ctx.moveTo(val[0].x, val[0].y);
            ctx.lineTo(val[1].x, val[1].y);
            ctx.stroke();
        });
    };
    return Road;
}());
