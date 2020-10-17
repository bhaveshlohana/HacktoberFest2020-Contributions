const { Command } = require("discord.js-commando");

module.exports = class extends Command {
  constructor(client) {
    super(client, {
      aliases: ["n"],
      name: "skip",
      group: "music",
      memberName: "skip",
      description: "Lompati lagu",
      guildOnly: true,
    });
  }

  run(message) {
    const serverQueue = message.client.queue.get(message.guild.id);
    if (serverQueue && serverQueue.playing) {
      serverQueue.connection.dispatcher.end();
      message.react("⏩");
    }
  }
};
