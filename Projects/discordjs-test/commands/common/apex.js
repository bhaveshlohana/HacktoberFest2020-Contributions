const { Command } = require("discord.js-commando");
const Apex = require("apex-api");
const apex = new Apex("c9b1e33f-df66-4870-bee0-97593e3e3093");

module.exports = class extends Command {
  constructor(client) {
    super(client, {
      name: "apex",
      group: "common",
      memberName: "apex",
      description: "Munculin data apex",
    });
  }

  run(message) {
    apex.user(message.argString, "PC").then((data) => {
      var res = data.data.metadata;
      var apexData = `Username: ${res.platformUserHandle}\nLevel: ${res.level}\nRank : ${res.rankName}
        `;
      message.channel.send(res.rankImage);
      return message.channel.send(apexData);
    });
  }
};
