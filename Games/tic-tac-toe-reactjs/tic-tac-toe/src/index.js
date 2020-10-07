/* Tutorial from: https://reactjs.org/tutorial/tutorial.html
 This tutorial teaches you how to create a simple tic-tac-toe game using React
 */

import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';

/* Square Class */
//The Square component renders a single <button>
/*class Square extends React.Component {
  //a constructor to the class to initialize the state
//  constructor (props){
//    super(props);
//      this.state = {
//          value: null,
//      };
//    }
    
  render() {
    return (
            <button className="square"
            onClick={() => this.props.onClick()}>
        {this.props.value}
      </button>
    );
  }
}*/

function Square(props) {
    return (
            <button className="square" onClick={props.onClick}>
            {props.value}
            </button>
            );
}

/* Board Class */
//Board renders 9 squares
class Board extends React.Component {
    //constructor for board - filled with nulls
    /* Should look as below when filled
     [
       'O', null, 'X',
       'X', 'X', 'O',
       'O', null, null,
     ]
     */
//    constructor(props) {
//        super(props);
//        this.state = {
//            squares: Array(9).fill(null),
//            xIsNext: true,
//        };
//    }
    
//    handleClick(i) {
//        const squares = this.state.squares.slice();
//        if(calculateWinner(squares) || squares[i]){
//            return; //this will exit and ignore clicks if there is a winner
//        }
//        squares[i] = this.state.xIsNext ? 'X' : 'O';
//        this.setState({
//            squares:squares,
//            xIsNext: !this.state.xIsNext,
//        });
//    }
    
  renderSquare(i) {
    //return <Square />;
      return <Square
      value={this.props.squares[i]}
      onClick= {() => this.props.onClick(i)}/>;
  }

  render() {
//      const winner = calculateWinner(this.state.squares);   //check for winner
//      let status;
//      if(winner){//if winner, change text to display winner
//          status = 'Winner: ' + winner;
//      }
//      else {//else continue game
//          status = 'Next player: ' + (this.state.xIsNext ? 'X' : 'O');
//      }

    return (
      <div>
       
        <div className="board-row">
          {this.renderSquare(0)}
          {this.renderSquare(1)}
          {this.renderSquare(2)}
        </div>
        <div className="board-row">
          {this.renderSquare(3)}
          {this.renderSquare(4)}
          {this.renderSquare(5)}
        </div>
        <div className="board-row">
          {this.renderSquare(6)}
          {this.renderSquare(7)}
          {this.renderSquare(8)}
        </div>
      </div>
    );
  }
}

/* Game Class*/
//Game component renders a board with placeholder values
class Game extends React.Component {
    constructor(props){
        super(props);
        this.state = {
        history: [{
            squares: Array(9).fill(null),
        }],
            stepNumber: 0,
            xIsNext: true,
        };
    }
    
    handleClick(i) {
        const history = this.state.history.slice(0, this.state.stepNumber + 1);
        const current = history[history.length - 1];
        const squares = current.squares.slice();
        if (calculateWinner(squares) || squares[i]){
            return;
        }
        squares[i] = this.state.xIsNext ? 'X' : 'O';
        this.setState({
        history: history.concat([{
            squares: squares,
        }]),
            stepNumber: history.length,
        xIsNext: !this.state.xIsNext,
        });
    }
    
    jumpTo(step){
        this.setState({
            stepNumber: step,
            xIsNext: (step % 2)=== 0,
        });
    }
    
  render() {
      const history = this.state.history;
      const current = history[this.state.stepNumber];
      const winner = calculateWinner(current.squares);
      
      const moves = history.map((step,move) => {
          const desc = move ?
          'Go to move #' + move :
          'Go to start';
          return (
                  <li key={move}>
                  <button onClick = {() => this.jumpTo(move)}>{desc}</button>
                  </li>
                  )
      });
      
      let status;
      if (winner){
          status = 'Winner: ' + winner;
      } else {
          status = 'Next player: ' + (this.state.xIsNext ? 'X' : 'O');
      }
      
    return (
      <div className="game">
        <div className="game-board">
          <Board
            squares = {current.squares}
            onClick = {(i) => this.handleClick(i)}
          />
        </div>
        <div className="game-info">
            <div>{status}</div>
          <ol>{moves}</ol>
        </div>
      </div>
    );
  }
}

/* Given an array of 9 squares, this function will check for a winner and return 'X', 'O', or null as appropriate. */
function calculateWinner(squares) {
  const lines = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
  ];
  for (let i = 0; i < lines.length; i++) {
    const [a, b, c] = lines[i];
    if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
      return squares[a];
    }
  }
  return null;
}

// ========================================

ReactDOM.render(
  <Game />,
  document.getElementById('root')
);
