<?php
  include('connection-mysql.php');
  $sqlselect = "SELECT a.facwarid, a.name, a.description, f.name, d.name
  FROM factionwar AS a
  INNER JOIN factions AS f ON  a.primary_faction = f.factionid
  INNER JOIN factions AS d ON  a.secondary_faction = d.factionid";
  $result1 = mysqli_query($dbcon, $sqlselect);  
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
          <li><a href="offensive.php">Offensive Mods</a></li>
          <li><a href="defensive.php">Defensive Mods</a></li>
        </ul>
      </div>
    </div>

    <div class="container">
      <h3>Factional Warfare</h3>
      <table class="table table-striped">
        <tr>
          <th>ID</th>
          <th>Name</th>
          <th>Description</th>
		  <th>Primary Faction</th>
		  <th>Secondary Faction</th>
        </tr>
        <?php while($row1 = mysqli_fetch_array($result1)):; ?>
        <tr>
			  <td><?php echo $row1[0]; ?></td>
			  <td><?php echo $row1[1]; ?></td>
			  <td><?php echo $row1[2]; ?></td>
			  <td><?php echo $row1[3]; ?></td>
			  <td><?php echo $row1[4]; ?></td>
        </tr>
        <?php endwhile; ?>
      </table>

	<!Add Module Form>
	<div class = "addform">
    <form method="post" action="insert_facwar.php">
			<input type="hidden" name="submitted" value="true" />
			<legend>Add Modules</legend>
			<div class="form-group">
				<label for="name">Name</label>
				<input type="text" name="name" class="form-control" id="name" placeholder="">
			</div>
			<div class="form-group">
				<label for="type">Description</label>
				<input type="text" name="description" class="form-control" id="description" placeholder="">
			</div>
			<div class="form-group">
				<label for="type">Primary Faction</label>
				<input type="text" name="prim_id" class="form-control" id="prim_id" placeholder="">
			</div>
			<div class="form-group">
				<label for="type">Secondary Faction</label>
				<input type="text" name="sec_id" class="form-control" id="sec_id" placeholder="">
			</div>
        <button type="submit" class="btn btn-default">Submit</button>
    </form>
	 </div>
	 
	 <!Edit Module Form>
	 <div class = "editform">
	 <form method="post" action="update_facwar.php">
			<input type="hidden" name="submitted" value="true" />
			<legend>Edit Modules</legend>
			<div class="form-group">
				<label for="name">ID</label>
				<input type="text" name="allianceid" class="form-control" id="allianceid" placeholder="">
			</div>
			<div class="form-group">
				<label for="name">Name</label>
				<input type="text" name="name" class="form-control" id="name" placeholder="">
			</div>
			<div class="form-group">
				<label for="type">Description</label>
				<input type="text" name="description" class="form-control" id="description" placeholder="">
			</div>
			<div class="form-group">
				<label for="type">Faction</label>
				<input type="text" name="fac_id" class="form-control" id="fac_id" placeholder="">
			</div>
        <button type="submit" class="btn btn-default">Submit</button>
     </form>
	 </div>


    <script src="http://code.jquery.com/jquery.js"></script>
    <script src="js/bootstrap.min.js"></script>
</body>
</html>