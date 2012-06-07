casper.test.comment('Making sure our test site is loaded correctly');

casper.start('http://localhost:8080/', function() {
  this.test.assertHttpStatus(200, 'Testing site is up');
});

casper.run(function() {
    this.test.done();
});
