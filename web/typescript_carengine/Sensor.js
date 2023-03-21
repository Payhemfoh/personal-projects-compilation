"use strict";
var Sensor = /** @class */ (function () {
    function Sensor(car) {
        this.car = car;
        this.rayCount = 5;
        this.rayLength = 150;
        this.raySpread = Math.PI / 2;
        this.rays = [];
        this.readings = [];
    }
    Sensor.prototype.castRays = function () {
        this.rays = [];
        for (var i = 0; i < this.rayCount; ++i) {
            var rayAngle = lerp(this.raySpread / 2, -this.raySpread / 2, this.rayCount == 1 ? 0.5 : i / (this.rayCount - 1)) + this.car.angle;
            var start = { x: this.car.x, y: this.car.y };
            var end = {
                x: this.car.x - Math.sin(rayAngle) * this.rayLength,
                y: this.car.y - Math.cos(rayAngle) * this.rayLength,
            };
            this.rays.push([start, end]);
        }
    };
    Sensor.prototype.update = function (roadBorders, traffic) {
        this.castRays();
        this.readings = [];
        for (var i = 0; i < this.rays.length; ++i) {
            this.readings.push(this.getReading(this.rays[i], roadBorders, traffic));
        }
    };
    Sensor.prototype.getReading = function (ray, roadBorders, traffic) {
        var _a;
        var touches = [];
        for (var i = 0; i < roadBorders.length; ++i) {
            var touch = getIntersection(ray[0], ray[1], roadBorders[i][0], roadBorders[i][1]);
            if (touch) {
                touches.push(touch);
            }
        }
        for (var i = 0; i < traffic.length; ++i) {
            for (var j = 0; j < traffic[i].polygon.length; ++j) {
                var touch = getIntersection(ray[0], ray[1], traffic[i].polygon[j], traffic[i].polygon[j + 1 % traffic[i].polygon.length]);
                if (touch) {
                    touches.push(touch);
                }
            }
        }
        if (touches.length == 0) {
            return null;
        }
        else {
            var offsets = touches.map(function (e) { return e.offset; });
            var minOffset_1 = Math.min.apply(Math, offsets);
            return (_a = touches.find(function (e) { return e.offset == minOffset_1; })) !== null && _a !== void 0 ? _a : null;
        }
    };
    Sensor.prototype.draw = function (ctx) {
        var _a, _b, _c, _d;
        for (var i = 0; i < this.rays.length; ++i) {
            var end = this.rays[i][1];
            if (this.readings[i]) {
                end = { x: (_b = (_a = this.readings[i]) === null || _a === void 0 ? void 0 : _a.x) !== null && _b !== void 0 ? _b : -1, y: (_d = (_c = this.readings[i]) === null || _c === void 0 ? void 0 : _c.y) !== null && _d !== void 0 ? _d : -1 };
            }
            ctx.beginPath();
            ctx.lineWidth = 2;
            ctx.strokeStyle = "yellow";
            ctx.moveTo(this.rays[i][0].x, this.rays[i][0].y);
            ctx.lineTo(end.x, end.y);
            ctx.stroke();
            ctx.beginPath();
            ctx.lineWidth = 2;
            ctx.strokeStyle = "black";
            ctx.moveTo(this.rays[i][1].x, this.rays[i][1].y);
            ctx.lineTo(end.x, end.y);
            ctx.stroke();
        }
    };
    return Sensor;
}());
