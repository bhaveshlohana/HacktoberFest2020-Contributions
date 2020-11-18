import React from "react";

function Footer(props) {
  return (
    <div className="footer">
      <p className="footer__how-to-play">
        <span className="footer__emphasized-text">HOW TO PLAY:</span>
        Use your
        <span className="footer__emphasized-text">arrow keys</span>
        to move the tiles. When two tiles with the same number touch, they
        <span className="footer__emphasized-text">merge into one!</span>
      </p>
      <p className="footer__attribution">
        React Clone of 2048. Originally created by
        <a className="footer__link" href="http://gabrielecirulli.com/">
          Gabriele Cirulli.
        </a>
        Based on
        <a
          className="footer__link"
          href="https://itunes.apple.com/us/app/1024!/id823499224"
        >
          1024 by Veewo Studio
        </a>
        and conceptually similar to
        <a className="footer__link" href="http://asherv.com/threes/">
          Threes by Asher Vollmer.
        </a>
      </p>
    </div>
  );
}

export default Footer;
