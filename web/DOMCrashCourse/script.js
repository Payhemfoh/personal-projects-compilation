//get the node in document by id
let heading = document.getElementById("heading");
console.log(heading);
//display the datatype of the node(object)
console.log(typeof heading);

//display the content of the node
/*
const list = document.getElementById("list");
console.log(list.textContent);
console.log(list.innerHTML);

//change the content of the node
list.textContent="Hi there";
console.log(list.textContent);
console.log(list.innerHTML);

list.innerHTML="<li>DOM</li>";
console.log(list.textContent);
console.log(list.innerHTML);

list.textContent="<li>Gay</li>";
console.log(list.textContent);
console.log(list.innerHTML);

list.innerHTML="Hi there";
console.log(list.textContent);
console.log(list.innerHTML);
*/

//Query selector
//return the first element match the specified CSS
//if not found, will return null
let list2 = document.querySelector("ul");
console.log(list2);

list2 = document.querySelector("#list");
console.log(list2);

list2 = document.querySelector('.list_class');
console.log(list2);

//query selector all
//return all the elements that match specified CSS
//return array-like object but not array
let list3 = document.querySelectorAll("li");
console.log(list3);
//error if use array method
//list3.push("Hi");

let listItem = document.querySelectorAll(".list_item");
console.log(listItem);

//change the css property directly(inline styling)
let heading2 = document.getElementById("heading");
heading.style.color="red";
//use Capital instead of space or dash
heading.style.backgroundColor="black";

let listItem2 = document.querySelectorAll("li");
console.log(listItem2);
//change the second li
//listItem2[1].style.backgroundColor="red";

//change all li
for(let i=0;i<listItem2.length;++i){
    listItem2[i].style.backgroundColor="royalblue";
}


//change css property using css text (remove all default inline styles and add new styles)
listItem2[0].style.cssText='background-color:black;color:white;font-size:25px';

//class property
heading2.style.cssText="";
heading2.className = "changeBG";
//the first class is replaced
//heading2.className="changeFT";

//to add both class at same time
heading2.className+=" changeFT";


//classList property
console.log(heading2.classList);
//add new class into classList
heading2.classList.add("changeCL");
//remove class from classList
heading2.classList.remove("changeCL");


//Event
//actions happen on web page
//select the button and heading
let heading3 = document.querySelector("#heading");
let btn = document.querySelector(".btn");

//when user click the button, the text will be printed
/*
btn.onclick = () => console.log("Clicked");

btn.onmouseover = () => heading3.style.cssText = `background-color:brown;
color:white;`;

btn.onmouseout = () => heading3.style.cssText = `background-color:transparent;color:black;`;
*/

//add event as html attribute
//const clickButton = () => console.log("Clicked");

//add event listener
//btn.addEventListener("click",()=>heading3.style.cssText = "background-color:brown;color:white;");


//event object
//created automatically when event occur
btn.addEventListener('click',(e)=>console.log(e));
//can get the event target by e.target



//get, set, check, remove attribute of element
const paragraph = document.querySelector(".paragraph");
//get value of HTML element attribute
console.log(paragraph.getAttribute("id"));
console.log(paragraph.getAttribute("class"));
//return null because the title attribute is not exist
console.log(paragraph.getAttribute("title"));

//set the new value to HTML element attribute
paragraph.setAttribute("style","background-color:black;color:white;");

//remove attribute of element
paragraph.removeAttribute("style");

//check if attribute is present
console.log(paragraph.hasAttribute("style"));
console.log(paragraph.hasAttribute("class"));



//DOM navigation
const listItem3 = document.getElementById("list_item2");
//get the parent
console.log(listItem3.parentElement);
console.log(listItem3.parentNode.parentNode);

//get the child
const list4 = document.querySelector(".list");
console.log(list4.childNodes);
console.log(list4.children);
console.log(list4.firstChild);  //lastChild
console.log(list4.firstElementChild);   //lastElementChild

//access to sibling
console.log(listItem3.previousSibling);
console.log(listItem3.nextSibling);

console.log(listItem3.previousElementSibling);
console.log(listItem3.nextElementSibling);


//create elements
const newElement = document.createElement("li");
const newText = document.createTextNode("Blog");
console.log(newText);
console.log(newElement);

newElement.appendChild(newText);
console.log(newElement);
list4.appendChild(newElement);
console.log(list4);

//change position of new element
list4.insertBefore(newElement,list4.children[1]);

//remove the new element
list4.removeChild(newElement);
