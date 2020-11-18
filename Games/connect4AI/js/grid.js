class Grid {
  // class methods
  constructor() {
    this.maxY = 6;
    this.maxX = 7;
    this.grid = [];
    for(let y=0;y<this.maxY;y++){
      this.grid[y] = new Array(this.maxX);
    }
    this.emptyGrid()
  }
  setElement(who,y,x) {
    this.grid[y][x] = who;
  }
  getElement(y,x){
    if(y<this.maxY && y>=0 && x<this.maxX && x >=0)
      return this.grid[y][x];
    return -1;
  }
  emptyGrid() {
    for(let y=0;y<this.maxY;y++){
      for(let x=0;x<this.maxX;x++){
        this.grid[y][x] = 0;
      }
    }
  }
  getFirstEmpty(x) {
    for(var y=this.maxY-1;y>=0;y--){
      if(this.grid[y][x]==0){
        //this.setElement(y,x);
        return y;
      }
    }
    return -1;
  }
  checkWinner(){
    for(var y=0;y<this.maxY;y++){
      for(var x=0;x<this.maxX;x++){
        if(this.isWinning(y,x)){
          return this.getElement(y,x);
        }
      }
    }
    return -1;
  }
  isWinning(y,x){
    if(this.getElement(y,x) != 0){
      if(
        this.getElement(y,x)==this.getElement(y,x+1) &&
        this.getElement(y,x)==this.getElement(y,x+2) &&
        this.getElement(y,x)==this.getElement(y,x+3)
      ){
        return true;
      }
      if(
        this.getElement(y,x)==this.getElement(y+1,x) &&
        this.getElement(y,x)==this.getElement(y+2,x) &&
        this.getElement(y,x)==this.getElement(y+3,x)
      ){
        return true;
      }
      if(
        this.getElement(y,x)==this.getElement(y+1,x+1) &&
        this.getElement(y,x)==this.getElement(y+2,x+2) &&
        this.getElement(y,x)==this.getElement(y+3,x+3)
      ){
        return true;
      }
      if(
        this.getElement(y,x)==this.getElement(y+1,x-1) &&
        this.getElement(y,x)==this.getElement(y+2,x-2) &&
        this.getElement(y,x)==this.getElement(y+3,x-3)
      ){
        return true;
      }
    }
    return false;
  }
}
