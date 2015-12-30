var express = require('express');
var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var bodyParser = require('body-parser');

//i put the mysql here because I couldn't get it to work in a second file.
var mysql = require('mysql');

var pool = mysql.createPool({
	connectionLimit: 10,
	host: 	'localhost',
	user: 	'student',
	password: 	'default',
	database: 	'student'
});

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.use('/static', express.static('public'));
app.set('port', 9001);

app.get('/',function(req,res,next){
	var context = {};
	pool.query('SELECT * FROM workouts', function(err, rows, fields){
			if(err){
				next(err);
				return;
			}
		context.results = rows;
		context.results.forEach(function(current,index,array){
			if (current.lbs === 0){
				current.lbs = "kgs";
			}
			else{
				current.lbs = "lbs";
			}
		});
		res.render('home', context);
	});
});

app.post('/',function(req,res,next){
	var context = {};

	if(req.body['workout']){
		if (req.body.name && req.body.reps && req.body.weight && req.body.date && req.body.units){
			pool.query("INSERT INTO workouts (name, reps, weight, date, lbs) VALUES (?, ?, ?, ?, ?)",
					  [req.body.name, req.body.reps, req.body.weight,
				       req.body.date, req.body.units], function(err, result){
					if(err){
						next(err);
						return;
					}
				var addedId = result.insertId;

				pool.query('SELECT * FROM workouts WHERE id=?', [addedId], function(err, rows, fields){
				if(err){
					next(err);
					return;
				}
					var data = rows[0];

					if (data.lbs === 0){
						data.lbs = "kgs";
					} else {
						data.lbs = "lbs";
					}

					res.type('text/plain');
					data = JSON.stringify(data);
					res.send(data);
				});
			});
		}
	}

	if(req.body['del']){
		pool.query("DELETE FROM workouts WHERE id=?", [req.body.id], function(err, result){
			if(err){
				next(err);
				return;
			}
			var data = {};
			data.id = req.body.id;
			data = JSON.stringify(data);
			res.type('text/plain');
			res.send(data);
		});
	}

	if(req.body['edit']){
		pool.query({sql: 'SELECT * FROM workouts WHERE id=?', typeCast: function(field,next){
			if (field.type === 'DATE') {
				return (field.string());
			}
			return next();
		}},
		[req.body.id], function(err, rows, fields){
			if(err){
				next(err);
				return;
			}
			context.toEdit = rows;
			res.render('home', context);
		});
	}

	if(req.body['edited']){
		pool.query("UPDATE workouts SET name=?, reps=?, weight=?, date=?, lbs=? WHERE id=?",
			      [req.body.name, req.body.reps, req.body.weight, req.body.date, req.body.units,
			       req.body.id], function(err, result){
	      	if(err){
	      		next(err);
	      		return;
	      	}
			pool.query('SELECT * FROM workouts', function(err, rows, fields){
				if(err){
					next(err);
					return;
				}
				context.results = rows;
				context.results.forEach(function(current,index,array){
					if (current.lbs === 0){
						current.lbs = "kgs";
					}
					else{
						current.lbs = "lbs";
					}
				});
				res.render('home', context);
			});
		});
	}
});

app.get('/reset',function(req,res,next){
  var context = {};
  pool.query("DROP TABLE IF EXISTS workouts", function(err){
    var createString = "CREATE TABLE workouts("+
    "id INT PRIMARY KEY AUTO_INCREMENT,"+
    "name VARCHAR(255) NOT NULL,"+
    "reps INT,"+
    "weight INT,"+
    "date DATE,"+
    "lbs BOOLEAN)";
    pool.query(createString, function(err){
      context.results = "Table reset successfully";
      res.render('reset',context);
    })
  });
});

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