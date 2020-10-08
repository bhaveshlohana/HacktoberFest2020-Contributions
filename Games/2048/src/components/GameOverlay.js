import React from "react";

function GameOverlay(props) {
  return (
    <div>
      <div
        className={
          props.status === "over"
            ? "game-overlay game-overlay--over active"
            : "game-overlay game-overlay--over"
        }
      >
        <h1 className="game-overlay__message">Game Over!</h1>
        <button className="game-overlay__try-again" onClick={props.tryAgain}>
          Try Again
        </button>
      </div>
      <div
        className={
          props.status === "won"
            ? "game-overlay game-overlay--won active"
            : "game-overlay game-overlay--won"
        }
      >
        <h1 className="game-overlay__message">You win!</h1>
        <button
          className="game-overlay__keep-going"
          onClick={() => {
            props.setStatus("continue");
          }}
        >
          Keep going
        </button>
        <button className="game-overlay__try-again" onClick={props.tryAgain}>
          Try Again
        </button>
      </div>
    </div>
  );
}

export default GameOverlay;
