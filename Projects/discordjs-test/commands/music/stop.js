const { Command } = require("discord.js-commando");

module.exports = class extends Command {
  constructor(client) {
    super(client, {
      aliases: ["s"],
      name: "stop",
      group: "music",
      memberName: "stop",
      description: "Nyetop musik",
      guildOnly: true,
    });
  }

  run(message) {
    // ngecek aku ada di voice channel apa ngga
    const { channel } = message.member.voice;
    if (!channel)
      return message.channel.send("Kamu belum gabung voice channel, nak...");

    // ngecek ada lagu di queue ngga
    const serverQueue = message.client.queue.get(message.guild.id);
    if (!serverQueue) {
      return message.channel.send("Mau nyetop apa aku...");
    } else {
      serverQueue.songs = [];
    }

    // stop lagu
    serverQueue.connection.dispatcher.end();
    message.react("⏹");
  }
};
