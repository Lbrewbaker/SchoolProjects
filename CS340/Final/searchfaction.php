<?php

	include('connection-mysql.php');
	$sqlselect = "SELECT * FROM factions";
	$result1 = mysqli_query($dbcon, $sqlselect);  

	// run sql query to get ID from name submission
	$faction_name = $_POST["name"];
	$sqlfactionid = "SELECT factionid FROM factions WHERE name='$faction_name'";
	$id_query = mysqli_query($dbcon, $sqlfactionid);
	$faction_id = mysqli_fetch_array($id_query);
	
	/*
	$sqloffinfoquery = "SELECT DISTINCT o.name
	FROM factions as FROM
	LEFT JOIN offensivemods AS o ON f.factionid = o.fact_id,
	WHERE f.factionid = '$faction_id[0]'";
	$off_query = mysqli_query($dbcon, $sqlfactquery);
	$off_data = mysqli_fetch_array($off_query):;

	*/
	
	

	
	// run sql query to pull all related entries from other tables
	$sqlfactquery = "SELECT DISTINCT  f.name, f.description, o.weapontype, d.deftype, a.name
	FROM factions AS f 
	LEFT JOIN offensivemods AS o ON f.factionid=o.fact_id 
	LEFT JOIN defensivemods AS d ON f.factionid=d.fact_id 
	LEFT JOIN alliances AS a ON f.factionid=a.primary_faction";
	$faction_query = mysqli_query($dbcon, $sqlfactquery);

  

  
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
      <h3>Information for <?php echo $faction_name; ?></h3>
      <table class="table table-striped">
        <tr>
			<th>Name</th>
			<th>Description</th>
			<th>Offensive Specialty</th>
			<th>Deffensive Speciality</th>
			<th>Primary Alliance</th>
        </tr>
		<?php while($factiondata = mysqli_fetch_array($faction_query)):; ?> 
        <tr>
			<td><?php echo $factiondata[0]; ?></td>
			<td><?php echo $factiondata[1]; ?></td>
			<td><?php echo $factiondata[2]; ?></td>
			<td><?php echo $factiondata[3]; ?></td>
			<td><?php echo $factiondata[4]; ?></td>
        </tr>
       <?php endwhile; ?>
      </table>

    </div> 

    <script src="http://code.jquery.com/jquery.js"></script>
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>