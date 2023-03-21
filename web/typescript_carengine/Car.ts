class Car{
    x:number;
    y:number;
    width:number;
    height:number;
    speed:number;
    acceleration:number;
    maxSpeed:number;
    friction:number;
    stepAngle:number;
    angle:number;
    damaged:boolean;
    useBrain:boolean;
    controls:Controls;
    sensor:Sensor|null;
    brain:NeuralNetwork|null;
    polygon:Coor[];

    constructor(x:number,y:number,width:number,height:number,controlType:string,maxSpeed:number=3){
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;

        this.speed = 0;
        this.acceleration = 0.2;
        this.maxSpeed = maxSpeed;
        this.friction = 0.07;
        this.stepAngle = 0.02;
        this.angle = 0;
        this.damaged=false;

        
        this.controls=new Controls(controlType);
        this.useBrain = controlType == "AI";

        if(controlType!="DUMMY"){
            this.sensor = new Sensor(this);
            this.brain = new NeuralNetwork([
                this.sensor.rayCount,6,4
            ]);
        }
        else{
            this.sensor = null;
            this.brain = null;
        }

        this.polygon = [];
    }

    private createPolygon():Coor[]{
        const points:Coor[]=[];
        const rad=Math.hypot(this.width,this.height)/2;
        const tetha = Math.atan2(this.width,this.height);
        points.push({
            x:this.x-Math.sin(this.angle-tetha)*rad,
            y:this.y-Math.cos(this.angle-tetha)*rad
        });
        points.push({
            x:this.x-Math.sin(this.angle+tetha)*rad,
            y:this.y-Math.cos(this.angle+tetha)*rad
        });
        points.push({
            x:this.x-Math.sin(Math.PI+this.angle-tetha)*rad,
            y:this.y-Math.cos(Math.PI+this.angle-tetha)*rad
        });
        points.push({
            x:this.x-Math.sin(Math.PI+this.angle+tetha)*rad,
            y:this.y-Math.cos(Math.PI+this.angle+tetha)*rad
        });
        return points;
    }

    private move(){
        if(this.controls.forward==1){
            this.speed += this.acceleration;
        }
        if(this.controls.reverse==1){
            this.speed -= this.acceleration;
        }

        if(this.speed > this.maxSpeed){
            this.speed = this.maxSpeed;
        }
        else if(this.speed < - this.maxSpeed/2){
            this.speed = -this.maxSpeed/2;
        }

        if(Math.abs(this.speed)<this.friction){
            this.speed = 0;
        }
        else if(this.speed >0){
            this.speed -= this.friction;
        }
        else if(this.speed < 0){
            this.speed += this.friction;
        }
        

        if(this.speed != 0){
            const flip = this.speed > 0 ? 1 : -1;
        
            if(this.controls.left==1){
                this.angle += this.stepAngle * flip;
            }
            if(this.controls.right==1){
                this.angle -= this.stepAngle * flip;
            }
        }
        
        this.x -=Math.sin(this.angle)*this.speed;
        this.y -=Math.cos(this.angle)*this.speed;
    }

    public update(roadBorders:Coor[][],traffic:Car[]){
        if(!this.damaged){ 
            this.move();
            this.polygon=this.createPolygon();
            this.damaged=this.assessDamage(roadBorders,traffic);
        }

        if(this.sensor){
            this.sensor.update(roadBorders,traffic);
            const offsets=this.sensor.readings.map(
                s=>s==null?0:1-s.offset
            )
            this.brainReaction(offsets);
            
        }
    }

    private brainReaction(offsets:number[]){
        const outputs=NeuralNetwork.feedForward(offsets,<NeuralNetwork>this.brain);
            
        if(this.useBrain){
            this.controls.forward = outputs[0];
            this.controls.left = outputs[1];
            this.controls.right = outputs[2];
            this.controls.reverse = outputs[3];
        }
    }

    private assessDamage(roadBorders:Coor[][],traffic:Car[]):boolean{
        for(let i=0;i<roadBorders.length;++i){
            if(polysIntersect(this.polygon,roadBorders[i])){
                return true;
            }
        }
        for(let i=0;i<traffic.length;++i){
            if(polysIntersect(this.polygon,traffic[i].polygon)){
                return true;
            }
        }
        return false;
    }

    public draw(ctx:CanvasRenderingContext2D,color:string,drawSensor:boolean=false){
        if(this.damaged){
            ctx.fillStyle="grey";
        }
        else{
            ctx.fillStyle=color;
        }
        ctx.beginPath();
        if(this.polygon.length>0){
            ctx.moveTo(this.polygon[0].x,this.polygon[0].y);
            for(let i=1;i<this.polygon.length;++i){
                ctx.lineTo(this.polygon[i].x,this.polygon[i].y);
            }
        }
        ctx.fill();
        if(this.sensor && drawSensor)
            this.sensor.draw(ctx);
    }
}