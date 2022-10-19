
class Maps{
    x:number;
    width:number;
    height:number;
    
    left:number;
    right:number;
    top:number;
    bottom:number;

    walls:Coor[][];
    constructor(x:number,width:number,height:number){
        this.x = x;
        this.width = width;
        this.height = height;
        this.walls = [];

        this.left = x-width/2;
        this.right= x+width/2;

        this.top = (window.innerHeight-height)/2;
        this.bottom = height+this.top;

        const topLeft = {x:this.left,y:this.top};
        const topRight = {x:this.right,y:this.top}
        const bottomLeft = {x:this.left,y:this.bottom}
        const bottomRight = {x:this.right,y:this.bottom}

        this.walls = [
            [topLeft,bottomLeft],
            [topRight,bottomRight],
            [topLeft,topRight],
            [bottomLeft,bottomRight]
        ];
    }

    public addborder(pointA:Coor,pointB:Coor){
        this.walls.push([{x:this.left + pointA.x,y:this.top+pointA.y},{x:this.left+pointB.x,y:this.top+pointB.y}])
    }

    public draw(ctx:CanvasRenderingContext2D){
        ctx.lineWidth = 5;
        ctx.strokeStyle="black";

        ctx.setLineDash([]);
        this.walls.forEach(val=>{
            ctx.beginPath();
            ctx.moveTo(val[0].x,val[0].y);
            ctx.lineTo(val[1].x,val[1].y);
            ctx.stroke();
        })
    }
}

class Vision{
    rayCount:number;
    rayLength:number;
    raySpread: number;
    rayAngles: number[];
    rays:Coor[][];
    readings:(Intersection | null)[];
    char:Character;

    constructor(char:Character){
        this.rayCount=70;
        this.rayLength=100;
        this.raySpread = Math.PI/2;

        this.rays = [];
        this.rayAngles = [];
        this.readings = [];
        this.char = char;
    }

    private castRays(){
        this.rays=[];
        this.rayAngles=[];
        for(let i =0;i<this.rayCount;++i){
            const rayAngle=lerp(
                this.raySpread/2,
                -this.raySpread/2,
                this.rayCount==1?0.5:i/(this.rayCount - 1)
            )+ this.char.angle;
            this.rayAngles.push(rayAngle);

            const start:Coor = {x:this.char.x,y:this.char.y}
            const end:Coor = {
                x:this.char.x - Math.sin(rayAngle)*this.rayLength,
                y:this.char.y - Math.cos(rayAngle) * this.rayLength,
            }

            this.rays.push([start,end]);
        }
    }

    public update(borders:Coor[][]){
        this.castRays();
        this.readings=[];
        for(let i=0;i<this.rays.length;++i){
            this.readings.push(
                this.getReading(this.rays[i],borders)
            )
        }
    }

    private getReading(ray:Coor[],borders:Coor[][]):Intersection|null{
        let touches:Intersection[] = [];
        for(let i=0;i<borders.length;++i){
            const touch=getIntersection(
                ray[0],
                ray[1],
                borders[i][0],
                borders[i][1]
            )
            if(touch){
                touches.push(touch);
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
                ctx.strokeStyle="yellow";
            }
            else{
                ctx.strokeStyle="darkblue";
            }
            ctx.beginPath();
            ctx.lineWidth=2;
            
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

class Character{
    x:number
    y:number
    angle:number
    stepAngle:number
    vision:Vision

    constructor(x:number,y:number){
        this.x = x;
        this.y = y;
        this.angle = 0;
        this.vision = new Vision(this);
        this.stepAngle = 0.02;
    }

    public update(borders:Coor[][]){
        if(this.vision)
            this.vision.update(borders);
    }

    public draw(ctx:CanvasRenderingContext2D){
        ctx.fillStyle="yellow";
        ctx.lineWidth = 1;
        ctx.beginPath();
        ctx.arc(this.x, this.y, 5, 0, 2 * Math.PI);
        ctx.fill();
        ctx.stroke();
        this.vision.draw(ctx);
    }

    public draw3d(ctx3d:CanvasRenderingContext2D){
        
        const { offsetLeft, offsetTop, width, height} = ctx3d.canvas;
        const Xmargin = 30
        const Ymargin = 100

        ctx3d.strokeStyle="white";
        ctx3d.lineWidth = 7;
        ctx3d.setLineDash([])

        for(let i=0;i<this.vision.rayCount;++i){
            
            if(this.vision.readings[i]){
                const lineHeight = height/2
                const x = lerp(Xmargin,width-Xmargin,i/this.vision.rayCount);
                const bias = Math.cbrt(this.vision.readings[i]!.offset * Math.cos(this.angle - this.vision.rayAngles[i]))
                ctx3d.beginPath();
                ctx3d.moveTo(
                    x,lineHeight*bias
                );
                ctx3d.lineTo(
                    x,lineHeight/bias
                )
                ctx3d.stroke();
            }
            
        }
    }

    public moveTo(x:number,y:number){
        this.x = x;
        this.y = y;
    }

    public turn(left:(1|0)=1){
        this.angle += (this.stepAngle * left)
        if(left){
            this.angle += this.stepAngle;
        }
        else{
            this.angle -= this.stepAngle;
        }
    }
}


const canvas=<HTMLCanvasElement>document.getElementById("canvas")
const canvas3d =<HTMLCanvasElement>document.getElementById("canvas3d")
canvas.onclick! = e =>{
    char.moveTo(e.x-canvas.offsetLeft,e.y-canvas.offsetTop)
}
document.onkeydown! = e=>{
    switch(e.key){
        case 'a':
        case 'A':
            char.turn(1);
            break;
        case 'd':
        case 'D':
            char.turn(0);
            break;
        case 'w':
        case 'W':
            char.moveTo(char.x -Math.sin(char.angle)*5, char.y - Math.cos(char.angle)*5);
            break;
        case 's':
        case 'S':
            char.moveTo(char.x +Math.sin(char.angle)*5, char.y + Math.cos(char.angle)*5);
            break;
    }
}
canvas!.width = 500;
canvas3d!.width = 500;

const ctx = <CanvasRenderingContext2D>canvas.getContext("2d");
const ctx3d = <CanvasRenderingContext2D>canvas3d.getContext("2d");
const map = new Maps(canvas.width/2,canvas.width * 0.9, (window.innerHeight*0.9)/2)
map.addborder({x:50,y:50},{x:100,y:300});
map.addborder({x:100,y:300},{x:250,y:200});
map.addborder({x:250,y:200},{x:50,y:50});
const char = new Character(20,20);

/*
    animation function
*/
function animate(time:number = 0){
    canvas!.height = window.innerHeight;
    canvas3d!.height = window.innerHeight;

    char.update(map.walls);
    map.draw(ctx)
    char.draw(ctx);
    char.draw3d(ctx3d);
    requestAnimationFrame(animate);
}

animate();