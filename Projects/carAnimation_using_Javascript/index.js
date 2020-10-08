$(document).ready(function(){
    alert('To Play Sound Click on The car. Caution: Click the car ONLY FOR 1 TIME!!!');
  });
$(".btn").on("click", function () {
    var audio = document.createElement('audio');
    audio.setAttribute('src', 'sound.mp3');
    audio.loop = true;
    audio.play();
});
