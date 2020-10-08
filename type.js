var easy_word=["the","of","and","a","to","in","is","you","that","it","for","on","are","as","with","his","they","i","at","sea","shore","shine","cloud","earth","here","me","he","was","going"];
var count=0;
var correct=0;
var incorrect=0;


$(window).keypress(function(e){
    if(e.which==32){
        var word=document.getElementById("container1").nodeValue;
        if(easy_word[count].trim()==word.trim()){
            $("#"+count).toggleClass("right");
            correct++;
        }
        else{
            $("#"+count).toggleClass("wrong"); 
            incorrect++;
        }
        count++;
        document.getElementById("container1").value="";

    }
});
document.getElementById("container1").onclick=function(){
    var timeleft=30;
    var wpm;
    var downloadTimer=setInterval(function(){
        document.getElementById("countdown").innerhtml=timeleft;
        timeleft -=1;
        if(timeleft<=2){
            clearInterval(downloadTimer);
            document.getElementById("countdown").innerHTML="Time-up"
            if(timeleft==-2){
                wpm=correct/0.5;
                document.getElementById("result").innerHTML+="\nCorrectwords:"+correct;
                document.getElementById("result").innerHTML+="\n\nIncorrectwords:"+incorrect
                document.getElementById("result").innerHTML+="\n\nWordsperMinute:"+wpm;
            }
        }
    } ,1000);
}
$(".restart").click(function(){
    location.reload();
})