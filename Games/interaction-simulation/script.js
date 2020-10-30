const treatOptions = [
  "Bake a cake and send some",
  "Go shopping together",
  "Organize hangout with old friends",
  "Send funny memes",
  "Send money",
];

const annoyOptions = [
  "*Never break eye contact*",
  "*Never make eye contact*",
  "Drum on every available surface",
  "Invite to an Opera then sing along there",
  "Speak in Morse Code",
];

const app = new Vue({
  el: "#app",
  data: {
    name: "",
    goodChoice: "",
    annoyingChoice: "",
    message: "I'm bored.",
    happiness: 50,
    reverse: false,
  },
  created() {
    this.getChoices();
  },
  methods: {
    random(min, max) {
      return Math.floor(Math.random() * max + min);
    },
    getChoices() {
      this.goodChoice = treatOptions[this.random(0, treatOptions.length)];
      this.annoyingChoice = annoyOptions[this.random(0, annoyOptions.length)];

      this.reverse = !this.reverse;
    },
    treat() {
      this.happiness += this.random(10, 20);

      if (this.happiness >= 100) {
        this.happiness = 100;
        this.message = `You're awesome, ${this.name || "Mr. Stranger"}!`;
      } else if (this.happiness >= 50) {
        this.message = `'Huh? ${this.name || "This stranger"} seems nice..'`;
      } else {
        this.message = "'Okay, cool.'";
      }

      this.getChoices();
    },
    annoy() {
      this.happiness -= this.random(10, 20);

      if (this.happiness <= 0) {
        this.happiness = 0;
        this.message = `Leave me alone, ${this.name || "stranger"}!`;
      } else if (this.happiness <= 50) {
        this.message = "'Uhh.. someone get me outta here.'";
      } else {
        this.message = `'${this.name || "This stranger"} is kinda annoying..'`;
      }

      this.getChoices();
    },
    restart() {
      this.message = "I'm bored.";
      this.happiness = 50;

      this.getChoices();
    },
  },
  computed: {
    great() {
      return this.happiness == 100;
    },
    good() {
      return this.happiness > 66 && this.happiness < 100;
    },
    neutral() {
      return this.happiness > 33 && this.happiness <= 66;
    },
    bad() {
      return this.happiness > 0 && this.happiness <= 33;
    },
    upset() {
      return this.happiness == 0;
    },
  },
});
