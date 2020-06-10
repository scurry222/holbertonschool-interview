#!/usr/bin/node
const request = require('request');
let characters;
const dict = {};
request.get('http://swapi.co/api/films/' + process.argv[2], function (err, res, body) {
  if (res.statusCode === 200) {
    characters = JSON.parse(body).characters;
    for (const url of characters) {
      request.get(url, function (err1, res1, body1) {
        if (res1.statusCode === 200) {
          savedData(url, JSON.parse(body1).name);
        } else if (err1) {
          console.log(err1);
        }
      });
    }
  } else if (err) {
    console.log(err);
  }
});
function savedData (url, name) {
  dict[url] = name;
  if (Object.entries(dict).length === characters.length) {
    for (const url of characters) {
      console.log(dict[url]);
    }
  }
}