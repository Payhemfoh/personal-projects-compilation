var userScore = 0;
var computerScore = 0;
var userScore_span = document.getElementById("user-score");
var computerScore_span = document.getElementById("computer-score");
var scoreBoard_div = document.querySelector(".score-board");
var result_p = document.querySelector(".result");
var rock_div = document.getElementById("rock");
var paper_div = document.getElementById("paper");
var scissor_div = document.getElementById("scissor");
function getComChoice() {
    var choices = ['r', 'p', 's'];
    var randomNumber = Math.floor(Math.random() * 3);
    return choices[randomNumber];
}
function convertChoice(choice) {
    var list = {
        'p': "paper",
        'r': "rock",
        's': "scissor"
    };
    return list[choice];
}
function win(usr, com) {
    ++userScore;
    userScore_span === null ? void 0 : userScore_span.innerHTML = userScore.toString();
    computerScore_span === null ? void 0 : computerScore_span.innerHTML = computerScore.toString();
    result_p === null ? void 0 : result_p.innerHTML = "<center>" + usr + "(user) beats " + com + "(com). You win!</center>";
    var element = document.getElementById(usr);
    element === null || element === void 0 ? void 0 : element.classList.add("green-glow");
    setTimeout(function () { return element === null || element === void 0 ? void 0 : element.classList.remove("green-glow"); }, 300);
}
function lose(usr, com) {
    ++computerScore;
    userScore_span === null ? void 0 : userScore_span.innerHTML = userScore.toString();
    computerScore_span === null ? void 0 : computerScore_span.innerHTML = computerScore.toString();
    result_p === null ? void 0 : result_p.innerHTML = "<center>" + usr + "(user) loses to " + com + "(com). You lose!</center>";
    var element = document.getElementById(usr);
    element === null || element === void 0 ? void 0 : element.classList.add("red-glow");
    setTimeout(function () { return element === null || element === void 0 ? void 0 : element.classList.remove("red-glow"); }, 300);
}
function draw(choice) {
    userScore_span === null ? void 0 : userScore_span.innerHTML = userScore.toString();
    computerScore_span === null ? void 0 : computerScore_span.innerHTML = computerScore.toString();
    result_p === null ? void 0 : result_p.innerHTML = "<center>Draw! Same choice(" + choice + ")!</center>";
    var element = document.getElementById(choice);
    element === null || element === void 0 ? void 0 : element.classList.add("grey-glow");
    setTimeout(function () { return element === null || element === void 0 ? void 0 : element.classList.remove("grey-glow"); }, 300);
}
function game(choice) {
    var comChoice = getComChoice();
    //draw
    if (choice === comChoice) {
        draw(convertChoice(choice));
    }
    switch (choice + comChoice) {
        case "rs":
        case "pr":
        case "sp":
            //user win
            win(convertChoice(choice), convertChoice(comChoice));
            break;
        case "sr":
        case "rp":
        case "ps":
            //com win
            lose(convertChoice(choice), convertChoice(comChoice));
            break;
    }
}
function main() {
    rock_div === null || rock_div === void 0 ? void 0 : rock_div.addEventListener("click", function () { return game("r"); });
    paper_div === null || paper_div === void 0 ? void 0 : paper_div.addEventListener("click", function () { return game("p"); });
    scissor_div === null || scissor_div === void 0 ? void 0 : scissor_div.addEventListener("click", function () { return game("s"); });
}
main();
