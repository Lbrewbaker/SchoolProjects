<!DOCTYPE html>
<html>
  <head>
    <title>CS340 Final Project - Faction Search</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!-- Bootstrap -->
    <link href="css/bootstrap.min.css" rel="stylesheet" media="screen">
  </head>
  <body>
    <div class="navbar navbar-inverse">
      <div class="navbar-inner">
        <a class="brand" href="index.html">CS340 Final</a>
      </div>
    </div>

    <div class="container">
      <h3>EVE Online Database</h3>

		<form method="post" action="viewfactions.php">
			<input type="hidden" name="submitted" value="true" />
			<legend>View Factions
			<button type="submit" class="btn btn-default">View &raquo;</button>
			</legend>
		</form>
	  
		<form method="post" action = "viewoffensive.php">
			<input type = "hidden" name = "submitted" value = "true" />
			<legend> View Offensive Modules
			<button type = "submit" class = "btn btn-default">View &raquo;</button>
			</legend>
		</form>

		<form method="post" action = "viewdefensive.php">
			<input type = "hidden" name = "submitted" value = "true" />
			<legend> View Defensive Modules
			<button type = "submit" class = "btn btn-default">View &raquo;</button>
			</legend>
		</form>
		<form method="post" action = "viewfactionwarfare.php">
			<input type = "hidden" name = "submitted" value = "true" />
			<legend> View Factional Warfare
			<button type = "submit" class = "btn btn-default">View &raquo;</button>
			</legend>
		</form>
		
    </div> 

    <script src="http://code.jquery.com/jquery.js"></script>
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>