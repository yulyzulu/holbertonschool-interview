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
  const charactersFilm = [];
  for (const i in character) {
    const url2 = character[i];
    console.log(url2);
    request(url2, function (err, res, body) {
      if (err) {
        console.log(err);
      }
      const dataChar = JSON.parse(body).name;
      console.log(dataChar);
      // charactersFilm.push(dataChar.name);
      // printCharacter(dataChar.name);
    });
  }
  const printCharacter = (character) => {
    console.log(character);
  };
});
