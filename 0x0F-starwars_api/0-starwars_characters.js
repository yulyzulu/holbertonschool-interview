#!/usr/bin/node

const request = require('request');
const id = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + id;

request(url, function (err, res, body) {
  if (err) throw err;
  const data = JSON.parse(body);
  const urls = data.characters;
  printCharacters(urls, 0);
});

const printCharacters = (urls, index) => {
  if (index === urls.length) {
    return;
  }
  request(urls[index], function (err, res, body) {
    if (err) throw err;
    console.log(JSON.parse(body).name);
    printCharacters(urls, index + 1);
  });
};
