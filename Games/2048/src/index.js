import React, { useState } from "react";
import ReactDOM from "react-dom";
import Header from "./components/Header";
import Game from "./components/Game";
import GameOverlay from "./components/GameOverlay";
import Footer from "./components/Footer";

import "./styles/header.css";
import "./styles/game.css";
import "./styles/game-overlay.css";
import "./styles/footer.css";

function App() {
  const [score, setScore] = useState(0);
  const [best, setBest] = useState(localStorage.getItem("Best") || 0);
  const [game, setGame] = useState(0);
  const [status, setStatus] = useState("running");

  const resetGame = () => {
    setScore(0);
    setGame(game + 1);
    setStatus("running");
  };

  const cacheBest = score => {
    localStorage.setItem("Best", score);
    setBest(score);
  };

  return (
    <div className="App">
      <Header score={score} best={best} resetGame={resetGame} />
      <GameOverlay tryAgain={resetGame} status={status} setStatus={setStatus} />
      <Game
        key={game}
        score={score}
        setScore={setScore}
        best={best}
        setBest={cacheBest}
        status={status}
        setStatus={setStatus}
      />
      <Footer />
    </div>
  );
}

const rootElement = document.getElementById("root");
ReactDOM.render(<App />, rootElement);
