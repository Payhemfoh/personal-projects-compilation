"use strict";
//network canvas
var network_canvas = document.getElementById("networkCanvas");
network_canvas.width = 500;
var networkCtx = network_canvas.getContext("2d");
//car canvas
var canvas = document.getElementById("canvas");
canvas.width = 400;
var ctx = canvas.getContext("2d");
var road = new Road(canvas.width / 2, canvas.width * 0.9, 6);
/*
    AI CARS
*/
var N = 100;
var cars = generateCars(N);
var bestCar = cars[0];
if (localStorage.getItem("bestBrain")) {
    for (var i = 0; i < cars.length; ++i) {
        cars[i].brain = JSON.parse(localStorage.getItem("bestBrain"));
        if (i != 0) {
            NeuralNetwork.mutate(cars[i].brain, 0.2);
        }
    }
}
function save() {
    localStorage.setItem("bestBrain", JSON.stringify(bestCar.brain));
}
function discard() {
    localStorage.removeItem("bestBrain");
}
function findBestCar(cars) {
    return cars.find(function (c) { return c.y == Math.min.apply(Math, cars.map(function (c) { return c.y; })); });
}
/*
    Traffic (to be appended)
*/
var traffic = [
    new Car(road.getLaneCenter(1), -100, 30, 50, "DUMMY", 2),
    new Car(road.getLaneCenter(0), -300, 30, 50, "DUMMY", 3),
    new Car(road.getLaneCenter(2), -300, 40, 50, "DUMMY", 1.8),
    new Car(road.getLaneCenter(0), -500, 30, 50, "DUMMY", 2),
    new Car(road.getLaneCenter(1), -700, 30, 60, "DUMMY", 2.3),
    new Car(road.getLaneCenter(0), -1200, 30, 50, "DUMMY", 2),
    new Car(road.getLaneCenter(2), -900, 30, 50, "DUMMY", 3),
    new Car(road.getLaneCenter(2), -600, 30, 50, "DUMMY", 2.2),
    new Car(road.getLaneCenter(1), -1000, 30, 50, "DUMMY", 2),
];
function generateCars(N) {
    var cars = [];
    for (var i = 0; i < N; ++i) {
        cars.push(new Car(road.getLaneCenter(1), 100, 30, 50, "AI"));
    }
    return cars;
}
/*
    animation function
*/
function animate(time) {
    if (time === void 0) { time = 0; }
    for (var i = 0; i < traffic.length; ++i)
        traffic[i].update(road.borders, []);
    for (var i = 0; i < cars.length; ++i)
        cars[i].update(road.borders, traffic);
    bestCar = findBestCar(cars);
    canvas.height = window.innerHeight;
    network_canvas.height = window.innerHeight;
    ctx.save();
    ctx.translate(0, -bestCar.y + canvas.height * 0.7);
    road.draw(ctx);
    for (var i = 0; i < traffic.length; ++i)
        traffic[i].draw(ctx, "red");
    ctx.globalAlpha = 0.2;
    for (var i = 0; i < cars.length; ++i)
        cars[i].draw(ctx, "blue");
    ctx.globalAlpha = 1;
    bestCar.draw(ctx, "blue", true);
    ctx.restore();
    networkCtx.lineDashOffset = -time / 30;
    Visualizer.drawNetwork(networkCtx, bestCar.brain);
    requestAnimationFrame(animate);
}
animate();
