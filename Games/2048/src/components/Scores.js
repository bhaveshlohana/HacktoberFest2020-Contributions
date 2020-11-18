import React from "react";

function Scores(props) {
  return (
    <div className="scores">
      <div className="score score--current">{props.score}</div>
      <div className="score score--best">{props.best}</div>
    </div>
  );
}

export default Scores;
