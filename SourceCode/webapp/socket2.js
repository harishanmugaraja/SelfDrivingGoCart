var http = require('http').createServer(handler); //require http server, and cr$
var fs = require('fs'); //require filesystem module
var io = require('socket.io')(http) //require socket.io module and pass the htt$

http.listen(8080); //listen to port 8080

function handler (req, res) { //create server
  fs.readFile(__dirname + '/socket2.html', function(err, data) { //read file in$
    if (err) {
      res.writeHead(404, {'Content-Type': 'text/html'}); //display 404 on error
      return res.end("404 Not Found");
    }
    res.writeHead(200, {'Content-Type': 'text/html'}); //write HTML
    res.write(data); //write data from index.html
    console.log("server started!")
    return res.end();
  });
}
