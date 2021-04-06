#!/usr/bin/node


const id = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + id;
const request = require('request');

request(url, function(err, res, body) {
  if (err) {
    console.log(err);
  }
  const str = JSON.parse(body);
  str.characters.map (person => {
    let path = person.split('/');
    
    console.log(path[path.length - 2]);
  })
});
