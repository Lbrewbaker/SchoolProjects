<?php
include('connection-mysql.php');

$sqlselect = "SELECT o.offmodid, o.name, o.weapontype, o.description, f.name
  FROM offensivemods as o
  INNER JOIN factions AS f on o.fact_id = f.factionid
  GROUP BY o.offmodid";
$result = mysqli_query($dbcon, $sqlselect);  


?>

<!DOCTYPE html>
<html>
<head>
	<title>CS340 Final</title>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<!-- Bootstrap -->
	<link href="css/bootstrap.min.css" rel="stylesheet" media="screen">
</head>

<body>
<div class="navbar navbar-inverse">
	<div class="navbar-inner">
		<a class="brand" href="index.html">CS340 Final</a>
				<ul class="nav navbar-nav navbar-right">
				<li><a href="manage.html">Manage</a></li>
				<li><a href="factions.php">Factions</a></li>
				<li><a href="defensive.php">Defensive Mods</a></li>
				<li><a href="faction_warfare.php">Factional Warfare</a></li>
			</ul>
	</div>
</div>

<div class="container">
<h3>Offensive Modules</h3>
<table class="table table-striped">
	<tr>
	<th>ID</th>
	<th>Name</th>
	<th>Type</th>
	<th>Description</th>
	<th>Factions</th>
	</tr>
		<?php while($row = mysqli_fetch_array($result)):; ?>
		<tr>
		<td><?php echo $row[0]; ?></td>
		<td><?php echo $row[1]; ?></td>
		<td><?php echo $row[2]; ?></td>
		<td><?php echo $row[3]; ?></td>
		<td><?php echo $row[4]; ?></td>
	</tr>
	<?php endwhile; ?>
</table>

<!Add Module Form>
<div class = "addform">
	<form method="post" action="insert_offmod.php" float = "left">
		<input type="hidden" name="submitted" value="true" />
		<legend>Add Modules</legend>
			<div class="form-group">
				<label for="name">Name</label>
				<input type="text" name="name" class="form-control" id="name" placeholder="">
			</div>
			<div class="form-group">
				<label for="weapontype">Type</label>
				<input type="text" name="weapontype" class="form-control" id="weapontype" placeholder="">
			</div>
			<div class="form-group">
				<label for="type">Description</label>
				<input type="text" name="description" class="form-control" id="description" placeholder="">
			</div>
			<div class="form-group">
				<label for="type">Faction</label>
				<input type="text" name="fact_id" class="form-control" id="fact_id" placeholder="">
			</div>
		<button type="submit" class="btn btn-default">Submit</button>
	</form>
</div>

<!Edit Module Form>
<div class = "editform">
	<form method="post" action="update_offmod.php" float = "right">
		<input type="hidden" name="submitted" value="true" />
		<legend>Edit Modules</legend>
			<div class="form-group">
				<label for="name">ID</label>
				<input type="text" name="offmodid" class="form-control" id="offmodid" placeholder="">
			</div>
			<div class="form-group">
				<label for="name">Name</label>
				<input type="text" name="name" class="form-control" id="name" placeholder="">
			</div>
			<div class="form-group">
				<label for="type">Type</label>
				<input type="text" name="weapontype" class="form-control" id="weapontype" placeholder="">
			</div>
			<div class="form-group">
				<label for="type">Description</label>
				<input type="text" name="description" class="form-control" id="description" placeholder="">
			</div>
			<div class="form-group">
				<label for="type">Faction</label>
				<input type="text" name="fact_id" class="form-control" id="fact_id" placeholder="">
			</div>
		<button type="submit" class="btn btn-default">Submit</button>
	</form>
</div>


<script src="http://code.jquery.com/jquery.js"></script>
<script src="js/bootstrap.min.js"></script>
</body>
</html>