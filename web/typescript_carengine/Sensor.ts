class Sensor{
    car:Car;
    rayCount:number;
    rayLength:number;
    raySpread: number;
    rays:Coor[][];
    readings:(Intersection | null)[];

    constructor(car:Car){
        this.car = car;
        this.rayCount=5;
        this.rayLength=150;
        this.raySpread = Math.PI/2;

        this.rays = [];
        this.readings = [];
    }

    private castRays(){
        this.rays=[];
        for(let i =0;i<this.rayCount;++i){
            const rayAngle=lerp(
                this.raySpread/2,
                -this.raySpread/2,
                this.rayCount==1?0.5:i/(this.rayCount - 1)
            )+ this.car.angle;

            const start:Coor = {x:this.car.x,y:this.car.y}
            const end:Coor = {
                x:this.car.x - Math.sin(rayAngle)*this.rayLength,
                y:this.car.y - Math.cos(rayAngle) * this.rayLength,
            }

            this.rays.push([start,end]);
        }
    }

    public update(roadBorders:Coor[][],traffic:Car[]){
        this.castRays();
        this.readings=[];
        for(let i=0;i<this.rays.length;++i){
            this.readings.push(
                this.getReading(this.rays[i],roadBorders,traffic)
            )
        }
    }

    private getReading(ray:Coor[],roadBorders:Coor[][],traffic:Car[]):Intersection|null{
        let touches:Intersection[] = [];
        for(let i=0;i<roadBorders.length;++i){
            const touch=getIntersection(
                ray[0],
                ray[1],
                roadBorders[i][0],
                roadBorders[i][1]
            )
            if(touch){
                touches.push(touch);
            }
        }
        
        for(let i=0;i<traffic.length;++i){
            for(let j=0;j<traffic[i].polygon.length;++j){
                const touch=getIntersection(
                    ray[0],
                    ray[1],
                    traffic[i].polygon[j],
                    traffic[i].polygon[j+1%traffic[i].polygon.length]
                )
                if(touch){
                    touches.push(touch);
                }
            }
        }

        if(touches.length == 0){
            return null;
        }
        else{
            const offsets = touches.map((e:Intersection)=>e.offset);
            const minOffset = Math.min(...offsets);
            return touches.find((e:Intersection)=>e.offset == minOffset)??null;
        }
    }

    public draw(ctx:CanvasRenderingContext2D){
        
        for(let i=0;i<this.rays.length;++i){
            let end = this.rays[i][1];
            if(this.readings[i]){
                end = {x:this.readings[i]?.x??-1,y:this.readings[i]?.y??-1};
            }
            ctx.beginPath();
            ctx.lineWidth=2;
            ctx.strokeStyle="yellow";
            ctx.moveTo(
                this.rays[i][0].x,
                this.rays[i][0].y
            );
            ctx.lineTo(
                end.x,
                end.y
            )
            ctx.stroke();

            ctx.beginPath();
            ctx.lineWidth=2;
            ctx.strokeStyle="black";
            ctx.moveTo(
                this.rays[i][1].x,
                this.rays[i][1].y
            );
            ctx.lineTo(
                end.x,
                end.y
            )
            ctx.stroke();
        }
    }
}