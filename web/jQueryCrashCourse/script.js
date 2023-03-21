//jQuery tutorial
//document object is the webpage
//ready method will be executed when document is loaded

$("document").ready(function(){
    //append will add the content into the tail of object
    $("body").append("<h1 id=\"heading\" class=\"heading\">Hello World</h1>");
    //add the css attribute to all the h1 element
    $("h1").css("background-color","black");
    $("h1").css("color","white");
    //only add this css attribute to the first h1 element
    $("h1:first").css("color","red");
    $("body").append("<h1>GG</h1>");
    //only add this css attribute to the last h1 element
    $("h1:last").css("color","orange");


    //targeting id and class
    $("#heading").append("Hi");
    $(".heading").append("Hi");

    //create variable to store the changes
    let replace = $('<p>');
    replace.append("<b>GG</b><p>");

    //change the content
    //$("#textBox").html(replace);


    //handle the events
    $("#textBox").on("click",whenMouseIsClicked);
    $("#textBox").on("mouseleave",whenMouseLeaves);

    function whenMouseIsClicked(){
        $("#textBox").html("<p>Clicked</p>");
    }

    function whenMouseLeaves(){
        $("#textBox").html("<p>Leaves</p>");
    }
});