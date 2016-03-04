<?php

	include('connection-mysql.php');

	// run sql query to pull all related entries from other tables
	$sqlalliquery = "SELECT DISTINCT  a.name, a.description, f.name, d.name
	FROM factionwar AS a 
	LEFT JOIN factions AS f ON a.primary_faction=f.factionid
	LEFT JOIN factions as d ON a.secondary_faction = d.factionid
	GROUP BY a.name";
	$ally_query = mysqli_query($dbcon, $sqlalliquery);

  
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
      <h3>Viewing Factional Warfare Information</h3>
      <table class="table table-striped">
        <tr>
			<th>Name</th>
			<th>Description</th>
			<th>Primary Faction</th>
			<th>Secondary Faction</th>
        </tr>
		<?php while($allydata = mysqli_fetch_array($ally_query)):; ?> 
        <tr>
			<td><?php echo $allydata[0]; ?></td>
			<td><?php echo $allydata[1]; ?></td>
			<td><?php echo $allydata[2]; ?></td>
			<td><?php echo $allydata[3]; ?></td>
        </tr>
       <?php endwhile; ?>
      </table>

    </div> 

    <script src="http://code.jquery.com/jquery.js"></script>
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>