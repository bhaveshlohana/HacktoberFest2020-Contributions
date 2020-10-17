const { Command } = require("discord.js-commando");
const { MessageAttachment } = require("discord.js");

module.exports = class extends Command {
  constructor(client) {
    super(client, {
      name: "avatar",
      group: "common",
      memberName: "avatar",
      description: "Munculin avatar",
    });
  }

  run(message) {
    var avatar;
    if (!message.mentions.users.first()) {
      message.channel.send("Mention orangnya dong...");
    } else {
      var user = message.mentions.users.first();
      avatar = new MessageAttachment(user.avatarURL());
      return message.channel.send(avatar);
    }
  }
};
