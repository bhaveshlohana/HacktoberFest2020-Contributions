var width = 700;
var height = 600;
var size = 100;
var game;

function setup() {
  var w = 700;
  var h = 600;
  createCanvas(w, h);
  game = new Game();
}

function draw() {
  background(220);
  for(var y=0;y<height/size;y++){
    for(var x=0;x<width/size;x++){
      el = game.grid.getElement(y,x);
      if(el==1){
        fill(0,255,0);
        rect(x*size,y*size,size,size);
      }
      if(el==2){
        fill(255,0,0);
        rect(x*size,y*size,size,size);
      }
      if(el==0){
        fill(255)
        if(mouseX > x*size && mouseX < x*size + size && mouseY > y*size && mouseY < y*size + size)
          fill(100);
          rect(x*size,y*size,size,size);
      }
    }
  }
}

function mouseClicked() {
  let x = Math.floor(mouseX/100);
  let y = Math.floor(mouseY/100);
  game.move(x);
  //game.checkWinner()


}
