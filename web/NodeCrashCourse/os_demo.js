const os = require("os");

//get platform
//macOS - darwin, Windows - win32, 
console.log(os.platform());

//get CPU Arch
console.log(os.arch());

//get CPU Core Info
console.log(os.cpus());

//get free memory
console.log(os.freemem());

//get total memory
console.log(os.totalmem());

//get home dir
console.log(os.homedir());

//uptime
console.log(os.uptime());