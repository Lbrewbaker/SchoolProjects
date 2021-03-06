var express = require('express');
var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({extended: false}));
app.use(bodyParser.json());
app.engine('handlebars', handlebars.engine);

//sets the port to 9001
app.set('view engine', 'handlebars');
app.set('port', 9001 );


//handles post requests and creates an asynchronos request for post requests
app.post('/', function(req, res) {
    var context = fillContext('GET', req, false);
    context.post = fillContext('POST', req, true);
    context.isPost = true;
    res.render('postPage', context);
});


//handles get requests
app.get('/', function(req, res) {
    var context = fillContext('GET', req, false);
	context.isPost = false;
    res.render('postPage', context);
});


//function to fill context based on what parameters the user sends.
function fillContext(type, req, isPost) {
    var params = [];
    if (isPost) {
        reqType = req.body;
    }
    else {
        reqType = req.query;
    }
    for (var param in reqType) {
        params.push({'name':param, 'value': reqType[param]});
    }
    console.log(params);
    console.log(req.body);
    var context = {};
    context.params = params;
    context.type = type;
    return context;
}

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.type('plain/text');
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});
