const express = require("express");
const path = require("path");
const app = express();

app.get("/", (req, res) => {
  res.redirect("/page?path=index.html");
});

app.get("/page", (req, res) => {
  let path = req.query.path;
  console.log("path : ", path);

  //Handle queryless request
  if (!path) {
    res.redirect("/page?path=index.html");
    return;
  }

  path = decodeURIComponent(path);
  path = preventTraversal(path);
  console.log("path after: ", path);

  res.sendFile(prepare(path), (err) => {
    if (err) {
      if (!res.headersSent) {
        try {
          res.send(strip(req.query.path) + " not found");
        } catch {
          res.end();
        }
      }
    }
  });
});

//Prevent directory traversal attack
function preventTraversal(dir) {
  if (dir.includes("../")) {
    dir = dir.replaceAll("../", "");
  }

  //In case people want to test locally on windows
  if (dir.includes("..\\")) {
    dir = dir.replaceAll("..\\", "");
  }
  return dir;
}

//Get absolute path from relative path
function prepare(dir) {
  return path.resolve("./public/" + dir);
}

app.listen(3333, () => {
  console.log("listening on 0.0.0.0:3333");
});
