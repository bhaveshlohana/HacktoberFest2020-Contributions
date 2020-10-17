const { Command } = require("discord.js-commando");
const { Util } = require("discord.js");
const ytdl = require("ytdl-core");

module.exports = class extends Command {
  constructor(client) {
    super(client, {
      aliases: ["p"],
      name: "play",
      group: "music",
      memberName: "play",
      description: "Ngeplay musik pake link",
      guildOnly: true,
    });
  }

  async run(message) {
    // info lagu
    const info = await ytdl.getInfo(message.argString);
    // ngambil data queue
    const serverQueue = message.client.queue.get(message.guild.id);
    //channel user saat ini
    const { channel } = message.member.voice;
    // objek data lagu
    const song = {
      id: info.videoDetails.videoId,
      title: Util.escapeMarkdown(info.videoDetails.title),
      url: info.videoDetails.video_url,
    };

    // kalo ada queue, tambahin
    if (serverQueue) {
      serverQueue.songs.push(song);
      message.react(`✅`);
      return;
    }

    // kalo gaada, di construct
    const queueConstruct = {
      textChannel: message.channel,
      voiceChannel: channel,
      connection: null,
      songs: [],
      volume: 5,
      playing: true,
    };

    // set queue di server ini
    message.client.queue.set(message.guild.id, queueConstruct);
    // tambahin lagu di queue
    queueConstruct.songs.push(song);

    // fungsi untuk play
    const play = async (song) => {
      // liat queue
      const queue = message.client.queue.get(message.guild.id);

      //kalo gaada queue leave aja
      if (!song) {
        queue.voiceChannel.leave();
        message.client.queue.delete(message.guild.id);
        return;
      }

      // buat dispatcher buat ngeplay
      const dispatcher = queue.connection
        .play(ytdl(song.url), {
          quality: "highestaudio",
        })
        .on("finish", () => {
          queue.songs.shift();
          play(queue.songs[0]);
        })
        .on("error", (error) => console.error(error));

      // set algoritma volume
      dispatcher.setVolumeLogarithmic(queue.volume / 5);
      message.react("🎶");
    };

    try {
      const connection = await channel.join();
      queueConstruct.connection = connection;
      play(queueConstruct.songs[0]);
    } catch (error) {
      message.client.queue.delete(message.guild.id);
      await channel.leave();
    }
  }
};
