#!/usr/bin/node

const id = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + id;
const request = require('request');

request(url, function (err, res, body) {
  if (err) {
    console.log(err);
  }
  const data = JSON.parse(body);
  const character = data.characters;
  for (const i in character) {
    const url2 = character[i];
    request(url2, function (err, res, body) {
      if (err) {
        console.log(err);
      }
      const dataChar = JSON.parse(body);
      console.log(dataChar.name);
    });
  }
});
