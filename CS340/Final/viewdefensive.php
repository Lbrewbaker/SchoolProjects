<?php

	include('connection-mysql.php');

	// run sql query to pull all related entries from other tables
	$sqldefquery = "SELECT DISTINCT  d.name, d.deftype, d.description, f.name
	FROM defensivemods AS d 
	LEFT JOIN factions AS f ON d.fact_id=f.factionid
	GROUP BY d.deftype";
	$def_query = mysqli_query($dbcon, $sqldefquery);

  
?>



<!DOCTYPE html>
<html>
  <head>
    <title>CS340 Final</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="css/bootstrap.min.css" rel="stylesheet" media="screen">
  </head>
  <body>
    <div class="navbar navbar-inverse">
      <div class="navbar-inner">
        <a class="brand" href="index.html">CS340 Final</a>
			<ul class="nav navbar-nav navbar-right">
			<li><a href="browse.php">Browse</a></li>
			</ul>
      </div>
    </div>

    <div class="container">
      <h3>Viewing Defensive Modules</h3>
      <table class="table table-striped">
        <tr>
			<th>Name</th>
			<th>Type</th>
			<th>Description</th>
			<th>Primary Faction</th>
        </tr>
		<?php while($defdata = mysqli_fetch_array($def_query)):; ?> 
        <tr>
			<td><?php echo $defdata[0]; ?></td>
			<td><?php echo $defdata[1]; ?></td>
			<td><?php echo $defdata[2]; ?></td>
			<td><?php echo $defdata[3]; ?></td>
        </tr>
       <?php endwhile; ?>
      </table>

    </div> 

    <script src="http://code.jquery.com/jquery.js"></script>
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>