var mraa = require('mraa');
var xml = require('xmlhttprequest').XMLHttpRequest;
var pwmPin = new mraa.Pwm(5);
var pwmPin2 = new mraa.Pwm(3);
pwmPin.period_us(20);
pwmPin.pulsewidth_us(10);
pwmPin.enable(true);
pwmPin2.period_us(20);
pwmPin2.pulsewidth_us(10);
pwmPin2.enable(true);
write = function(pin,num){pin.write(num)};
//pwmPin.write(1);
//function loop(){pwmPin.write(0);}
//pwmPin.write(0);
//setTimeout(function(){pwmPin.write(1);},1000);
//setTimeout(function(){pwmPin.enable(false);},10000);
//setTimeout(function(){pwmPin2.write(1);},1000);
//setTimeout(function(){pwmPin2.enable(false);},10000);
var xhr= new xml();
xhr.onreadystatechange=function(){
	console.log(this.responseText);
	if(this.responseText=='right'){
		console.log('right');
		write(pwmPin,0);
		write(pwmPin2,1);
	}
	else if(this.responseText=='left'){
		console.log('left');
		write(pwmPin,1);
		write(pwmPin2,0);
	}
	else if(this.responseText=='up'){
		console.log('up');
		write(pwmPin,1);
		write(pwmPin2,1);
	}
	else if(this.responseText=='none'){
		console.log('none');
		write(pwmPin,0);
		write(pwmPin2,0);
	}
	
}
setInterval(function(){
	xhr.open("GET","https://ctf.sites.tjhsst.edu/control",false);
	xhr.send();
},1500);

