class AI{
  constructor(){
    this.evaluationTable = [[3, 4, 5, 7, 5, 4, 3],
                            [4, 6, 8, 10, 8, 6, 4],
                            [5, 8, 11, 13, 11, 8, 5],
                            [5, 8, 11, 13, 11, 8, 5],
                            [4, 6, 8, 10, 8, 6, 4],
                            [3, 4, 5, 7, 5, 4, 3]];
   this.id = 2;
   this.opponentId = 1;
   this.depth = 4;
  }
  listMove(g){
    var listOfMove = [];
    for(var i=0;i<g.maxX;i++){
      if(g.getFirstEmpty(i) != -1){
        listOfMove.push(i);
      }
    }
    return listOfMove;
  }
  bestMove(g){
    var t_score, score = -Infinity;
    var move;
    var listOfMove = this.listMove(g);
    console.log(listOfMove, listOfMove.length);
    for(var i=0;i<listOfMove.length;i++){
      let y = g.getFirstEmpty(listOfMove[i]);
      g.setElement(this.id,y,listOfMove[i]);
      t_score = this.minimax(g,this.depth,false);
      if(t_score > score){
        score = t_score;
        move = listOfMove[i];
      }
      g.setElement(0,y,listOfMove[i]);
    }
    return move;
  }
  minimax(g, depth, isMaximizing){
    var winner = g.checkWinner();
    if(winner == 2){
      return 1000;
    }
    else if(winner == 1){
      return -1000;
    }
    if(depth == 0){
      return this.evaluatePosition(g);
    }
    var t_score;
    var score;
    var listOfMove = this.listMove(g);
    if(isMaximizing){
      score = -Infinity;
      for(var i=0;i<listOfMove.length;i++){
        let y = g.getFirstEmpty(listOfMove[i]);
        g.setElement(this.id,y,listOfMove[i]);
        t_score = this.minimax(g,depth-1,false);
        score = max(t_score,score);
        g.setElement(0,y,listOfMove[i]);
      }
    }
    else{
      score = +Infinity;
      for(var i=0;i<listOfMove.length;i++){
        let y = g.getFirstEmpty(listOfMove[i]);
        g.setElement(this.opponentId,y,listOfMove[i]);
        t_score = this.minimax(g,depth-1,true);
        score = min(t_score,score);
        g.setElement(0,y,listOfMove[i]);
      }
    }
    return score;
  }
  evaluatePosition(g){
    var winner = g.checkWinner();
    if(winner==2){
      //console.log("1 won");
      return 1000;
    }
    else if(winner == 1){
      //console.log("2 Won")
      return -1000;
    }
    var el;
    var sum = 0;
    for(var y=0;y<g.maxY;y++){
      for(var x=0;x<g.maxX;x++){
        el = g.getElement(y,x);
        if(el==2){
          sum+=this.evaluationTable[y][x];
        }
        else if(el==1){
          sum-=this.evaluationTable[y][x];
        }
      }
    }
    return sum;
  }
}
