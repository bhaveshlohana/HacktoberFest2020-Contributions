const { CommandoClient } = require("discord.js-commando");

module.exports = class extends CommandoClient {
  constructor(config) {
    super(config);

    this.queue = new Map();
  }
};
