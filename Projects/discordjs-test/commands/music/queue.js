const { Command } = require("discord.js-commando");

module.exports = class extends Command {
  constructor(client) {
    super(client, {
      aliases: ["q"],
      name: "queue",
      group: "music",
      memberName: "queue",
      description: "Liat Playlist",
      guildOnly: true,
    });
  }

  run(message) {
    const serverQueue = message.client.queue.get(message.guild.id);
    if (!serverQueue) return message.channel.send("Playlist kamu kosong.");
    return message.channel.send(`
      Playlist kamu : \n${serverQueue.songs
        .map((song) => `- ${song.title}`)
        .join("\n")}
      \nYang kamu setel sekarang : ${serverQueue.songs[0].title}
		`);
  }
};
