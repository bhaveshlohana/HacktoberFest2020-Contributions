var gamePattern=[];
var colourArray=["green","red","yellow","blue"];
var userPattern=[];
var level=0;
var started=false;
function checkSolution(currLevel){
    if( userPattern[currLevel] === gamePattern[currLevel] ){
        
        console.log("success");

        if(userPattern.length===gamePattern.length)
        {
            setTimeout(function () {
                nextSequence();
              }, 1000);
      
        }
    }else{
        startOver();
    }    
}

function nextSequence(){    
    userPattern=[];
    level++;

    $("#level-title").text("Level "+level);
    
    var randomNumbers=Math.floor(Math.random()*4);
    var randomChosenColour=colourArray[randomNumbers];
    gamePattern.push(randomChosenColour);
    $("#"+randomChosenColour).fadeIn(100).fadeOut(100).fadeIn(100);
    playSound(randomChosenColour);

}

$(".btn").on("click",function(){
    var userChosenColor=$(this).attr("id");
    playSound(userChosenColor);
    userPattern.push(userChosenColor);
    onClickAnimation(userChosenColor);
    checkSolution(userPattern.length-1);
});

function playSound(file){
    var audio=new Audio("sounds/"+ file+".mp3" );
    audio.play();

}

function onClickAnimation(userChosenColor){

    $("#"+userChosenColor).addClass("pressed");

    setTimeout(function() { 
        $("#"+userChosenColor).removeClass("pressed");
        },100);
}

function startOver(){
    $("body").addClass("game-over");        
    setTimeout(function(){
        $("body").removeClass("game-over");
    },2000)
    setTimeout(function(){
        $("h1").text("Game Over!. Press Any Key to restart");
    },1000);
    level=0
    gamePattern=[];
    started=false;
}

$(document).on("keypress",function(){ 
    if(!started){
        $("#level-title").text("Level "+level);
        started=true;
        nextSequence();
    }
    });
