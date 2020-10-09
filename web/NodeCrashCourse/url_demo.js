const url = require("url");

const myUrl = new URL("https://www.google.com:322/reading.html?search=Happy");

//serialized URL
console.log(myUrl.href);
console.log(myUrl.toString());

//get host (root domain)
console.log(myUrl.host);

//get host name
console.log(myUrl.hostname);

//pathname
console.log(myUrl.pathname);

//serialized query
console.log(myUrl.search);

//params object
console.log(myUrl.searchParams);

//add param
myUrl.searchParams.append("key","32");
console.log(myUrl.searchParams);

//loop through params
myUrl.searchParams.forEach((value,name)=>console.log(name +":"+value));