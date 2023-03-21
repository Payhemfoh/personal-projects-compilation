//network canvas
const network_canvas=<HTMLCanvasElement>document.getElementById("networkCanvas")
network_canvas!.width = 500;

const networkCtx = network_canvas.getContext("2d");


//car canvas
const canvas=<HTMLCanvasElement>document.getElementById("canvas")
canvas!.width = 400;

const ctx= <CanvasRenderingContext2D> canvas.getContext("2d");
const road = new Road(canvas.width/2,canvas.width * 0.9,6);


/*
    AI CARS
*/
let N=100;
const cars = generateCars(N);
let bestCar = cars[0];
if(localStorage.getItem("bestBrain")){
    for(let i=0;i<cars.length;++i){
        cars[i].brain = JSON.parse(
            <string>localStorage.getItem("bestBrain")
        );
        if(i!=0){
            NeuralNetwork.mutate(<NeuralNetwork>cars[i].brain,0.2);
        }
    }
    
}
function save(){
    localStorage.setItem("bestBrain",
    JSON.stringify(bestCar.brain));
}

function discard(){
    localStorage.removeItem("bestBrain");
}

function findBestCar(cars:Car[]):Car{
    return <Car>cars.find(
    (c:Car)=>c.y==Math.min(
        ...cars.map((c:Car)=>c.y)
        ));
}

/*
    Traffic (to be appended)
*/
const traffic = [
    new Car(road.getLaneCenter(1),-100,30,50,"DUMMY",2),
    new Car(road.getLaneCenter(0),-300,30,50,"DUMMY",3),
    new Car(road.getLaneCenter(2),-300,40,50,"DUMMY",1.8),
    new Car(road.getLaneCenter(0),-500,30,50,"DUMMY",2),
    new Car(road.getLaneCenter(1),-700,30,60,"DUMMY",2.3),
    new Car(road.getLaneCenter(0),-1200,30,50,"DUMMY",2),
    new Car(road.getLaneCenter(2),-900,30,50,"DUMMY",3),
    new Car(road.getLaneCenter(2),-600,30,50,"DUMMY",2.2),
    new Car(road.getLaneCenter(1),-1000,30,50,"DUMMY",2),
]

function generateCars(N:number){
    const cars:Car[]=[];
    for(let i=0;i<N;++i){
        cars.push(new Car(road.getLaneCenter(1),100,30,50,"AI"));
    }
    return cars;
}


/*
    animation function
*/
function animate(time:number = 0){
    for(let i=0;i<traffic.length;++i)
        traffic[i].update(road.borders,[])

    for(let i=0;i<cars.length;++i)
        cars[i].update(road.borders,traffic);

    
    bestCar = findBestCar(cars);

    canvas!.height = window.innerHeight;
    network_canvas!.height = window.innerHeight;

    ctx.save();
    ctx.translate(0,-bestCar!.y + canvas.height * 0.7);

    road.draw(ctx);
    for(let i=0;i<traffic.length;++i)
        traffic[i].draw(ctx,"red");
    
    ctx.globalAlpha=0.2;
    for(let i=0;i<cars.length;++i)
        cars[i].draw(ctx,"blue");
    ctx.globalAlpha=1;

    bestCar!.draw(ctx,"blue",true);
    ctx.restore();

    networkCtx!.lineDashOffset=-time/30;
    Visualizer.drawNetwork(<CanvasRenderingContext2D>networkCtx,<NeuralNetwork>bestCar!.brain);
    requestAnimationFrame(animate);
}

animate();


