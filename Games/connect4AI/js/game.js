class Game {
  // class methods
  constructor() {
    this.grid = new Grid();
    // this.human turn must be random
    this.humanTurn = 1;
    this.AI = new AI();

  }
  move(x) {
    var y = this.grid.getFirstEmpty(x);
    if(y==-1)
      return 0;
    if(this.humanTurn){
      this.grid.setElement(1,y,x);
      this.humanTurn = 0;
      this.checkWinner();
      this.AImove();
      this.checkWinner();
    }


  }
  AImove(){
      var x = this.AI.bestMove(this.grid);
      var y = this.grid.getFirstEmpty(x);
      this.grid.setElement(2,y,x);
      this.humanTurn = 1;
  }
  checkWinner() {
    var winner = this.grid.checkWinner();
    if(winner==1){
      alert("YOU WON\nRealod page to play again");
      console.log("1 won");
    }
    else if(winner == 2){
      alert("AI WON\nRealod page to play again");
      console.log("2 Won")
    }
  }
  method3() {  }

}
