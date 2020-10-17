const { Command } = require("discord.js-commando");

module.exports = class extends Command {
  constructor(client) {
    super(client, {
      name: "join",
      group: "music",
      memberName: "join",
      description: "Liat Playlist",
      guildOnly: true,
    });
  }

  async run(message) {
    if (message.member.voice.channel) {
      await message.member.voice.channel.join();
    } else {
      message.reply("You need to join a voice channel first!");
    }
  }
};
