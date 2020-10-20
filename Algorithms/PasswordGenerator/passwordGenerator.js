alert("The Password Generator");
passlen = prompt("Input password length");

var pass = ""
for (var i = 1; i <= passlen; i++){
  var car = Math.floor(Math.random() * 94) + 33;
	pass += String.fromCharCode(car);
}

alert("Your password is "+pass);
