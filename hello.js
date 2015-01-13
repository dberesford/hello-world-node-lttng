var addon = require('bindings')('hello');

setInterval(function() {
  console.log(addon.hello()); // 'world'
}, 1);
