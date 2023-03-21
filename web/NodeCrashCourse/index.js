const http = require("http");
const path = require("path");
const fs = require("fs");

//create the http server object to handle the request
const server = http.createServer(
    (request,response) => {
        /*
        if(request.url === "/"){
            fs.readFile(path.join(__dirname,"public","index.html"),(err,content)=>{
                if(err)throw err;
                response.writeHead(200,{"Content-Type":"text/html"})
                response.end(content);
            });
            
        }else if(request.url === "/about"){
                fs.readFile(path.join(__dirname,"public","about.html"),(err,content)=>{
                    if(err)throw err;
                    response.writeHead(200,{"Content-Type":"text/html"})
                    response.end(content);
                });
        }else if(request.url === "/api/users"){
            //fetch data from database
            const users = [
                {name:"Bom",age:40},
                {name:"John",age:12}
            ]
            response.writeHead(200,{"Content-Type":"application/json"});
            response.end(JSON.stringify(users));
        }
        */
       //Build file path
        let filePath = path.join(__dirname,'public', request.url === '/' ? 
        'index.html' : request.url);

        //Extension of file
        let extname = path.extname(filePath);

        //Initial content type
        let contentType = 'text/html';

        //check extname and set content type
        switch(extname){
            case ".js":
                contentType = "text/javascript";
                break;
            case ".css":
                filePath = path.join(__dirname,request.url);
                contentType = "text/css";
                break; 
            case ".json": 
                contentType = "application/json";
                break;
            case ".png":
                contentType = "image/png";
                break; 
            case ".jpg":
                contentType = "image/jpg";
                break;    
        }
        
        //Read File
            fs.readFile(filePath,(err,data)=>{
                if(err) {
                    if(err.code == "ENOENT"){
                        //page not found
                        fs.readFile(path.join(__dirname,
                            'public','404.html'),
                            (err,data)=>{
                                if(err) throw err;
                                response.writeHead(200,{"Content-Type":"text/html"});
                                response.end(data,'utf8');
                            })
                    }else{
                        //server error
                        response.writeHead(500);
                        response.end("Server Error: "+err.code);
                    }
                }
                else{
                    response.writeHead(200,{"Content-Type":contentType});
                    response.end(data,'utf8');
                }
        })
    }
);

//find the port number in environment then assign 8080 if not found
const PORT = process.env.PORT || 8080;

//deploy the server
server.listen(PORT,()=>{console.log("Server:"+PORT+" is listening...")});