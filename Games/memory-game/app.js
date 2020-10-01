document.addEventListener('DOMContentLoaded', () => {
  //card options
  const cardArray = [
    {
      name: 'Black_Widow',
      img: 'images1/blackwidow.png'
    },
    {
      name: 'cap',
      img: 'images1/cap.png'
    },
    {
      name: 'deadpool',
      img: 'images1/deadpool.png'
    },
    {
      name: 'hawkeye',
      img: 'images1/hawkeye.png'
    },
    {
      name: 'ironman',
      img: 'images1/ironman.png'
    },
    {
      name: 'spidey',
      img: 'images1/spidey.png'
    },
    {
      name: 'Black_Widow',
      img: 'images1/blackwidow.png'
    },
    {
      name: 'cap',
      img: 'images1/cap.png'
    },
    {
      name: 'deadpool',
      img: 'images1/deadpool.png'
    },
    {
      name: 'hawkeye',
      img: 'images1/hawkeye.png'
    },
    {
      name: 'ironman',
      img: 'images1/ironman.png'
    },
    {
      name: 'spidey',
      img: 'images1/spidey.png'
    }
  ]

  cardArray.sort(() => 0.5 - Math.random())

  const grid = document.querySelector('.grid')
  const resultDisplay = document.querySelector('#result')
  var cardsChosen = []
  var cardsChosenId = []
  const cardsWon = []

  //create your board
  function createBoard() {
    for (let i = 0; i < cardArray.length; i++) {
      var card = document.createElement('img')
      card.setAttribute('src', 'images1/q.png')
      card.setAttribute('data-id', i)
      card.addEventListener('click', flipCard)
      grid.appendChild(card)
    }
  }

  //check for matches
  function checkForMatch() {
    var cards = document.querySelectorAll('img')
    const optionOneId = cardsChosenId[0]
    const optionTwoId = cardsChosenId[1]
    
    if(optionOneId == optionTwoId) {
      cards[optionOneId].setAttribute('src', 'images1/q.png')
      cards[optionTwoId].setAttribute('src', 'images1/q.png')
      alert('You have clicked the same image!')
    }
    else if (cardsChosen[0] === cardsChosen[1]) {
      alert('You found a match')
      cards[optionOneId].setAttribute('src', 'images1/blank.png')
      cards[optionTwoId].setAttribute('src', 'images1/blank.png')
      cards[optionOneId].removeEventListener('click', flipCard)
      cards[optionTwoId].removeEventListener('click', flipCard)
      cardsWon.push(cardsChosen)
    } else {
      cards[optionOneId].setAttribute('src', 'images1/q.png')
      cards[optionTwoId].setAttribute('src', 'images1/q.png')
      alert('Sorry, try again')
    }
    cardsChosen = []
    cardsChosenId = []
    resultDisplay.textContent = cardsWon.length
    if  (cardsWon.length === cardArray.length/2) {
      resultDisplay.textContent = 'Congratulations! You found them all!'
    }
  }

  //flip your card
  function flipCard() {
    var cardId = this.getAttribute('data-id')
    cardsChosen.push(cardArray[cardId].name)
    cardsChosenId.push(cardId)
    this.setAttribute('src', cardArray[cardId].img)
    if (cardsChosen.length ===2) {
      setTimeout(checkForMatch, 500)
    }
  }

  createBoard()
})
