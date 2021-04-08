#!/usr/bin/node

const id = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + id;
const request = require('request');

request(url, function (err, res, body) {
  if (err) throw err;
  const data = JSON.parse(body);
  const characters = data.characters;
  printCharacter(characters, 0);
});

const printCharacter = (urls, index) => {
  if (urls.lenght === index) {
    return;
  }
  request(urls[index], function (err, res, body) {
    if (err) throw err;
    const dataChar = JSON.parse(body).name;
    console.log(dataChar);
    printCharacter(urls, index + 1);
  });
};
