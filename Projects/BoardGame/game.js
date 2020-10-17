var score=0;
let variableNumberToBeFound = 5;
function content(elem)
{
	//elem.style.backgroundColor="red";
	var p=document.getElementById("para");
	if(elem.innerText==variableNumberToBeFound)
	{
		score++;
	}
	p.innerHTML='Your Score:'+ ' ' + score;
	initlization();
}
function display(){
	alert(score);
}
function getVariableNumber(){
	if(ts == 60){
		variableNumberToBeFound = randomNumber(0, 8);
	}
	document.getElementById("addingVariableNumber").innerHTML= "Number to be searched is " + variableNumberToBeFound.toString();
}
var ts=60*1;
var minutes=parseInt(ts/60);
var seconds=parseInt(ts%60);
function CheckTime(){
	document.getElementById("timer").innerHTML='Time Left: '+ minutes+ ' : ' + seconds;
	if(ts<=0){
		document.getElementById("timer").innerHTML='TIME OVER';
		over();		
	}	
	else{
		ts=ts-1;
		minutes=parseInt(ts/60);
		seconds=parseInt(ts%60);
		setTimeout("CheckTime()",1000);
	}
}
	setTimeout("CheckTime()",1000);

var blocks;
var myTable;
var nums = [];

function initlization() {
  myTable = document.getElementsByTagName("table")[0];
  shuffle(); //need to shuffle initially 
  getVariableNumber();
  document.getElementById("finalScores").style.display = "none";
}
function randomNumber(min, max) {  
    min = Math.ceil(min); 
    max = Math.floor(max); 
    return Math.floor(Math.random() * (max - min + 1)) + min;
} 

function shuffle() {
  //need to get all tds each time the table is shuffled
  blocks = document.getElementsByTagName("td");
  tableSize = blocks.length;
  shuffledArray(0, tableSize);
  for (var i = 0; i < tableSize; i++) {
    blocks[i].innerHTML = '<span draggable="true">' + nums[i] + '</span>';
  }
}
function shuffledArray( from,  to) {
for(i=from; i<to;i++){
    nums[i-from]=i;
    }
for (var i = to-from; i; i--) {
    j= Math.floor(Math.random() *i);

    [nums[i - 1], nums[j]] = [nums[j], nums[i - 1]];
    }
}
function over()
{
	document.getElementById("displayScore").innerHTML = "Final Score : " + score;	
	document.getElementById("finalScores").style.display = "block";
}
