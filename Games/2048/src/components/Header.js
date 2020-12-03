import React from "react";
import Scores from "./Scores";

function Header(props) {
  return (
    <div className="header">
      <div className="header__row">
        <h1 className="header__title">2048</h1>
        <Scores score={props.score} best={props.best} />
      </div>
      <div className="header__row">
        <p className="header__intro">
          Join the numbers and get to the
          <strong>2048 tile!</strong>
        </p>
        <button className="restart" onClick={props.resetGame}>
          New Game
        </button>
      </div>
    </div>
  );
}

export default Header;
