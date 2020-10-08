import React, { useEffect, useRef } from "react";
import lottie from "lottie-web";

function App() {
  const container = useRef(null);

  useEffect(() => {
    lottie.loadAnimation({
      container: container.current,
      renderer: "svg",
      loop: true,
      autoplay: true,
      animationData: require("./success.json"),
    });
  }, []);

  return (
    <div className="App">
      <h1>React Lottie Demo</h1>
      <div
        className="container"
        ref={container}
        style={{
          width: "200x",
          height: "200px",
        }}
      ></div>
    </div>
  );
}

export default App;
