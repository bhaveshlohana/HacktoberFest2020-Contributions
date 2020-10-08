const config = require("./config/config");
const twit = require("twit");
const T = twit(config);

console.log("Bot iniciado - " + new Date());

retweet = () => {
  let params = {
    // Here you place the words that you want Twitter to query
    q: "PLACE HERE THE WORD YOU WANT TO QUERY",
    // Here is the limit of tweets it will return
    count: 20,
  };
  T.get("search/tweets", params, (err, data, response) => {
    if (!err) {
      for (let dat of data.statuses) {
        let retweetId = dat.id_str;
        // The Bot retweets every tweet that was returned by the query
        T.post("statuses/retweet/:id", { id: retweetId }, (err) => {
          err
            ? console.log("Somenthing went wrong! => " + err)
            : console.log("Retweeted " + retweetId);
        });
      }
    }
  });
};
// Every two minutes it will run the retweet function
setInterval(retweet, 120000);
