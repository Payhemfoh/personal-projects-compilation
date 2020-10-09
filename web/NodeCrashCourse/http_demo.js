const http = require("http");

//create server object
http.createServer((request,response)=>{
    //Write response when get request
    response.write("Hello World");
    response.end();
}).listen(8080,()=>console.log("Server is listening..."));