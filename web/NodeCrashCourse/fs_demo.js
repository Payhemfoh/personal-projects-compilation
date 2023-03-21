const fs = require("fs");
const path = require("path");

/*
//create folder
fs.mkdir(path.join(__dirname,'/test'),(err)=>{
    if(err) 
    throw err;
    console.log("Folder created...");
});
*/

/*
//create and write to file
//will overwrite what ever in file
fs.writeFile(path.join(__dirname,'/test','hello.txt'),"Hello World",(err)=>{
    if(err) 
    throw err;
    console.log("File Written created...");
});

//appendFile will not overwrite
fs.appendFile(path.join(__dirname,'/test','hello.txt'),"I love Node.js",(err)=>{
    if(err) 
    throw err;
    console.log("File Appended created...");
});
*/

//readFile
fs.readFile(path.join(__dirname,'/test','hello.txt'),'utf8',(err,data)=>{
    if(err) 
    throw err;
    console.log(data);
});

//rename file
fs.rename(path.join(__dirname,'/test','hello.txt'),path.join(__dirname,'/test','world.txt'),(err)=>{
    if(err) 
    throw err;
    console.log("File Renamed created...");
});