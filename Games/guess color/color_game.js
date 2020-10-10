var numSquares=6;                                       //order of declaration of variables matters a lot don't declare after calling in a function
var colors=[];
var pickedColor;

var square=document.querySelectorAll(".square");
var colorDisplay=document.getElementById("colorDisplay");
var messageDisplay=document.querySelector("#message");
var h1=document.querySelector("h1");
var resetButton=document.querySelector("#reset");
var easyBTN=document.querySelector("#easyBTN");
var hardBTN=document.querySelector("#hardBTN");
var modeButtons=document.querySelectorAll(".mode");

init();

function init(){
	//mode buttons event listeners	function
	setupmodebuttons();
	//square setup event listener function
	setupsquares();
	reset();
}

function setupmodebuttons(){
	for(i=0;i<modeButtons.length;i++){
		modeButtons[i].addEventListener("click",function(){
			modeButtons[0].classList.remove("selected");
			modeButtons[1].classList.remove("selected");
			this.classList.add("selected");
			this.textContent==="Easy"?numSquares=3:numSquares=6; // ternary operator condition?soln1:soln2
				reset();

		});
	}
}

function setupsquares(){
	for (var i = 0; i < square.length; i++) {
		//add initial colors to squares
		square[i].addEventListener("click",function(){
			//grabs color of clicked square
			var clickedColor=this.style.background;
			//compares to picked color
			if (clickedColor===pickedColor) {
				messageDisplay.textContent="Correct";
				changeColors(clickedColor);
				h1.style.backgroundColor=clickedColor;
				resetButton.textContent="Play Again?";
			}
			else{
				this.style.backgroundColor="#232323";
				messageDisplay.textContent="Try Again";
			}
		});
	}
}


function reset(){
	colors=generateRandomColors(numSquares);
	h1.style.backgroundColor="steelblue";
	//pick a new random color from array
	pickedColor=pickColor();
	//change colorDisplay to match picked color
	colorDisplay.textContent=pickedColor;
	resetButton.textContent="New Colors"; 
	messageDisplay.textContent="";
	//change colors of squares
	for(var i=0;i<square.length;i++){
		if(colors[i]){
			square[i].style.display="block";
			square[i].style.background=colors[i];
		}
		else{
			square[i].style.display="none";
		}
	}
}


resetButton.addEventListener("click",function(){
	reset();
});

function changeColors(color){                  //this function is going to be called when guess is correct
	for (var i = 0; i < square.length; i++) {
		square[i].style.backgroundColor=color;
	}
}

function pickColor(){
	var random=Math.floor(Math.random() * colors.length); 
	//Math.random is used to get random no. between range 0 and 1 and doesnt include 1
	//Math.floor is another function used to chop off decimals
	return colors[random];

}

function generateRandomColors(num){
	//make an array
	var arr=[];
	//add num random colors to array
	for (var i = 0; i <num; i++) {
		arr.push(randomColor());
	}	
	//return that array
	return arr;
}

function randomColor(){
	//pick a red from 0 to 255
	var r=Math.floor(Math.random()*256);    //multiplied by 256 cause Math.random doesnt include 1
	//pick a green from 0 to 255
	var g=Math.floor(Math.random()*256);
	//pick a blue from 0 to 255
	var b=Math.floor(Math.random()*256);
	return  "rgb(" +r +", "+ g +", " + b +")";   //when comparing it only matches if we have those spaces after commas cause dom automatically adds space after commas in the colors it sets so now they can be compared
}
