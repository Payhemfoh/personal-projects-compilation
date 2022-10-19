"use strict";
var Controls = /** @class */ (function () {
    function Controls(controlType) {
        this.forward = 0;
        this.left = 0;
        this.right = 0;
        this.reverse = 0;
        switch (controlType) {
            case "KEYS":
                this.addKeyboardListeners();
                break;
            case "DUMMY":
                this.forward = 1;
                break;
        }
    }
    Controls.prototype.addKeyboardListeners = function () {
        var _this = this;
        document.onkeydown = function (event) {
            switch (event.key) {
                case "ArrowLeft":
                    _this.left = 1;
                    break;
                case "ArrowRight":
                    _this.right = 1;
                    break;
                case "ArrowUp":
                    _this.forward = 1;
                    break;
                case "ArrowDown":
                    _this.reverse = 1;
                    break;
            }
        };
        document.onkeyup = function (event) {
            switch (event.key) {
                case "ArrowLeft":
                    _this.left = 0;
                    break;
                case "ArrowRight":
                    _this.right = 0;
                    break;
                case "ArrowUp":
                    _this.forward = 0;
                    break;
                case "ArrowDown":
                    _this.reverse = 0;
                    break;
            }
        };
    };
    return Controls;
}());
