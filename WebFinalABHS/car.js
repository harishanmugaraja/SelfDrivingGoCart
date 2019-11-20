//var request = require('request')
var mraa=require('mraa')
var pin13=new mraa.Gpio(13);
pin13.dir(mraa.DIR_OUT);
pin13.write(0);
var servo = new mraa.Pwm(6);
servo.enable(true);
servo.write(5);
function half(){
console.log("method ran!");
}
//half();
setInterval(half,100);
