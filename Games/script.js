score = 0;
cross = true;

audio = new Audio('gamemusic.mp3')
audiogo = new Audio('gomusic.mp3')
setTimeout(() => {
    audio.play()
}, 1000);
document.onkeydown =function(e){
    console.log("Key code is: ",e.keyCode)
    if(e.keyCode==38){
        hanumana = document.querySelector('.hanumana');
        hanumana.classList.add('animateHanumana');
        setTimeout(()=>{
            hanumana.classList.remove('animateHanumana')
        },900);
    }
    if(e.keyCode==39){
        hanumana = document.querySelector('.hanumana');
        hanumanaX = parseInt(window.getComputedStyle(hanumana,null).getPropertyValue('left'));
        hanumana.style.left = hanumanaX + 112 + "px";
    }
    if(e.keyCode==37){
        hanumana = document.querySelector('.hanumana');
        hanumanaX = parseInt(window.getComputedStyle(hanumana,null).getPropertyValue('left'));
        hanumana.style.left = (hanumanaX - 112 )+ "px";
    }
        
}
setInterval(() => {
    hanumana =document.querySelector('.hanumana')
    gameOver=document.querySelector('.gameOver')
    ravana=document.querySelector('.ravana')

    hx = parseInt(window.getComputedStyle(hanumana,null).getPropertyValue('left'));
    hy = parseInt(window.getComputedStyle(hanumana,null).getPropertyValue('top'));

    rx = parseInt(window.getComputedStyle(ravana,null).getPropertyValue('left'));
    ry = parseInt(window.getComputedStyle(ravana,null).getPropertyValue('top'));

    offsetX = Math.abs(hx-rx)
    offsetY = Math.abs(hy-ry)
    // console.log(offsetX,offsetY)
    if(offsetX < 113 && offsetY < 52){
        gameOver.innerHTML = "Game Over - Reload To Play Again"
        ravana.classList.remove('animateRavana')
        audiogo.play();
        setTimeout(() => {
            audiogo.pause();
            audio.pause();
        }, 1000);
    }
    else if(offsetX < 145 && cross){
        score+=1;
        updateScore(score);
        cross = false;
        setTimeout(() => {
            cross = true;
        }, 1000);
        setTimeout(() => {
            aniDur=parseFloat(window.getComputedStyle(hanumana,null).getPropertyValue('animation-duration'));
            newDur= aniDur - 0.8;
            ravana.style.animationDuration =newDur + 's';
        }, 500);
      
    }
}, 10);
function updateScore(score){
    scoreCount.innerHTML = "Your Score : " + score
}