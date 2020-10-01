let loader = document.getElementById("loader");
const scoreboard = document.getElementById("scoreboard");
const scoreList = document.getElementById("score-list");

let client = null, contractInstance = null;
let secretKey = '2c1ddec81682446ad1a23f29a4280c334f85dbf5e0ae795f9f80932bc496017111a058aa0882614f1dfeab4c92059fc0b1ec67eae4cf66cef49852e7a8548ae5';
let publicKey = 'ak_8mF1W1LRCXJgUMf75YDD7rFEo3mZL4PFHAbKBYsieVouP2NC9';
let contractAddress = "ct_2NLwz2oD712d8hAUj7Ppg2ofhAmyPFTEweCAQzmNHMy1FgjME4";
let contractSource=`
contract AEQuiz =

  record question =
    { question : string,
      correct : string,
      incorrect : list(string) }
    
  record score =
    { username : string,
      score : int }

  record state =
    { questions : map(string, question),
      scores : map(string, (string * int)) }

  entrypoint init() = 
    { questions = {},
      scores = {} }

  function checkQuestion(question: string) : bool =
    Map.member(question, state.questions)

  entrypoint getQuestions() =
    state.questions

  entrypoint getScores() =
    state.scores

  stateful entrypoint addScore(username : string, score : int) =
    let newScore = (username, score)

    put(state{scores[username] = newScore})

  stateful entrypoint addQuestion(question' : string, correct' : string, incorrect1 : string, incorrect2 : string,  incorrect3 : string) =
    require(!checkQuestion(question'), "Question Already Exist")
    let newQuestion = {question = question', correct = correct', incorrect = [incorrect1, incorrect2, incorrect3]}

    put(state{questions[question'] = newQuestion})

  stateful entrypoint deleteQuestion(question' : string)=
    require(checkQuestion(question'), "Question Not Found")
    let newQuestions = Map.delete(question', state.questions)

    put(state{questions = newQuestions})
`

async function getClientInstance(secretKey, publicKey){
  const NODE_URL = 'https://sdk-testnet.aepps.com';
  const ACCOUNT = Ae.MemoryAccount({ keypair: { secretKey: secretKey, publicKey: publicKey } });
  const nodeInstance = await Ae.Node({ url: NODE_URL })
  const sdkInstance = await Ae.Universal({
    compilerUrl: 'https://compiler.aepps.com',
    nodes: [ { name: 'testnet', instance: nodeInstance } ],
    accounts: [ ACCOUNT ]
  });
  return sdkInstance;
}

window.addEventListener("load", async function () {
  client = await getClientInstance(secretKey, publicKey);
  contractInstance = await client.getContractInstance(contractSource,{contractAddress});

  contractInstance.methods.getScores().then(function(scores){
    let allScores = scores.decodedResult;
    scoreList.innerHTML = allScores.map(score => {
      return `<li class="high-score">${score[1][0]} - ${score[1][1]}</li>`;
    });

    scoreboard.classList.remove("hidden");
    loader.classList.add("hidden");
  }).catch(function(error){
    console.error(error.decodedError)
    loader.classList.add("hidden");
  });
})
