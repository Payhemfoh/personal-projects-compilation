class Controls{
    forward :number;
    left:number;
    right:number;
    reverse:number;
    
    constructor(controlType:string){
        this.forward=0;
        this.left=0;
        this.right=0;
        this.reverse=0;
        switch(controlType){
            case "KEYS":
                this.addKeyboardListeners();
                break;
            case "DUMMY":
                this.forward=1;
                break;
        }
        
    }

    private addKeyboardListeners(){
        document.onkeydown=(event)=>{
            switch(event.key){
                case "ArrowLeft":
                    this.left = 1;
                    break;
                case "ArrowRight":
                    this.right = 1;
                    break;
                case "ArrowUp":
                    this.forward = 1;
                    break;
                case "ArrowDown":
                    this.reverse = 1;
                    break;
            }
        }

        document.onkeyup=(event)=>{
            switch(event.key){
                case "ArrowLeft":
                    this.left = 0;
                    break;
                case "ArrowRight":
                    this.right = 0;
                    break;
                case "ArrowUp":
                    this.forward = 0;
                    break;
                case "ArrowDown":
                    this.reverse = 0;
                    break;
            }
        }
    }
}

