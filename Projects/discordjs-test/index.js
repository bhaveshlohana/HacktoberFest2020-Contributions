const path = require("path");
const MusicClient = require("./MusicClient");
require("dotenv").config();

const client = new MusicClient({
  commandPrefix: process.env.DISCORD_PREFIX,
  owner: process.env.DISCORD_OWNER,
});

client.registry
  .registerDefaultTypes()
  .registerGroups([
    ["common", "Common used commands"],
    ["music", "Music commands"],
  ])
  .registerDefaultGroups()
  .registerDefaultCommands()
  .registerCommandsIn(path.join(__dirname, "commands"));

client.once("ready", () => {
  console.log(`Logged in as ${client.user.tag}! (${client.user.id})`);
  client.user.setActivity("with !help");
});

//autoroles
client.on("guildMemberAdd", async (member) => {
  var role = member.guild.roles.cache.find((r) => r.name === "Pendaftar");
  await member.roles.add(role.id);
});

client.on("error", console.error);

client.login(process.env.DISCORD_TOKEN);
