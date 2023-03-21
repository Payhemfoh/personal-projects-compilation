let userScore = 0;
let computerScore = 0;
let userScore_span = document.getElementById("user-score");
let computerScore_span = document.getElementById("computer-score");
let scoreBoard_div = document.querySelector(".score-board");
let result_p = document.querySelector(".result");
let rock_div = document.getElementById("rock");
let paper_div = document.getElementById("paper");
let scissor_div = document.getElementById("scissor");

function getComChoice() : ('r'|'s'|'p'){
    const choices:('r'|'s'|'p')[] = ['r','p','s'];
    let randomNumber = Math.floor(Math.random()*3);
    return choices[randomNumber];
}

function convertChoice(choice:('p'|'r'|'s')):string{
    const list={
        'p':"paper",
        'r':"rock",
        's':"scissor"
    }
    return list[choice];
}

function win(usr:string,com:string):void{
    ++userScore;
    userScore_span===null? void 0 : userScore_span.innerHTML = userScore.toString();
    computerScore_span===null? void 0:computerScore_span.innerHTML = computerScore.toString();
    result_p===null? void 0:result_p.innerHTML="<center>"+usr+"(user) beats "+com+"(com). You win!</center>";
    let element = document.getElementById(usr);
    element?.classList.add("green-glow");
    setTimeout(()=>element?.classList.remove("green-glow"),300);
}

function lose(usr:string,com:string):void{
    ++computerScore;
    userScore_span===null? void 0 : userScore_span.innerHTML = userScore.toString();
    computerScore_span===null? void 0:computerScore_span.innerHTML = computerScore.toString();
    result_p===null? void 0:result_p.innerHTML="<center>"+usr+"(user) loses to "+com+"(com). You lose!</center>";
    let element = document.getElementById(usr);
    element?.classList.add("red-glow");
    setTimeout(()=>element?.classList.remove("red-glow"),300);
}

function draw(choice : string):void{
    userScore_span===null? void 0 : userScore_span.innerHTML = userScore.toString();
    computerScore_span===null? void 0:computerScore_span.innerHTML = computerScore.toString();
    result_p===null? void 0:result_p.innerHTML="<center>Draw! Same choice("+choice+")!</center>";
    let element = document.getElementById(choice);
    element?.classList.add("grey-glow");
    setTimeout(()=>element?.classList.remove("grey-glow"),300);
}

function game(choice : ('r'|'s'|'p')) : void{
    const comChoice : ('r'|'s'|'p') = getComChoice();
    //draw
    if(choice === comChoice){
        draw(convertChoice(choice));
    }
    switch(choice+comChoice){
        case "rs":
        case "pr":
        case "sp":
           //user win
           win(convertChoice(choice),convertChoice(comChoice));
           break;
        case "sr":
        case "rp":
        case "ps":
            //com win
            lose(convertChoice(choice),convertChoice(comChoice));
            break; 
    }
}

function main() : void{
    rock_div?.addEventListener("click",()=>game("r"));
    paper_div?.addEventListener("click",()=>game("p"));
    scissor_div?.addEventListener("click",()=>game("s"));
}

main();