const EventEmitter = require("events");
const uuid = require("uuid");

//uuid create a random universal id
//console.log(uuid.v4());

class Logger extends EventEmitter{
    log(msg){
        //call event
        this.emit("message",{id:uuid.v4(),msg:msg});
    }
}

//module.exports = Logger;

const l = new Logger();

l.on("message",data=>console.log("Called Listener:",data));

l.log("Hello World");
l.log("Hello");
l.log("Hi");