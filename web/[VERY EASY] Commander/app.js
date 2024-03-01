const express = require("express");
const { exec } = require("child_process");
const app = express();
const port = 3000;

app.use(express.urlencoded({ extended: true }));

app.get("/", (req, res) => {
  res.sendFile(__dirname + "/index.html");
});

app.get("/vulnerable", (req, res) => {
  const cmd = req.query.cmd;

  const blacklist = [
    "cat",
    "more",
    "tac",
    "nl",
    "head",
    "tail",
    "awk",
    "sed",
  ];
  let safeToRun = true;

  for (const word of blacklist) {
    if (cmd.includes(word)) {
      safeToRun = false;
      res.send("You think it's that easy? Try harder!");
      break;
    }
  }

  if (safeToRun && cmd) {
    exec(cmd, (error, stdout) => {
      if (error) {
        res.send("Error executing command.");
      } else {
        res.send(`<strong>Output:</strong><br><pre>${stdout}</pre>`);
      }
    });
  }
});

app.listen(port, () => {
  console.log(`Server listening at http://localhost:${port}`);
});
