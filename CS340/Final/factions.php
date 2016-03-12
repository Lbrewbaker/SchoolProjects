<?php
  include('connection-mysql.php');
  $sqlselect = "SELECT * FROM factions";
  $result1 = mysqli_query($dbcon, $sqlselect);  
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
		  <li><a href="manage.html">Manage</a></li>
          <li><a href="offensive.php">Offensive Mods</a></li>
          <li><a href="defensive.php">Defensive Mods</a></li>
          <li><a href="faction_warfare.php">Factional Warfare</a></li>
        </ul>
      </div>
    </div>

    <div class="container">
      <h3>Factions</h3>
      <table class="table table-striped">
        <tr>
			<th>ID</th>
			<th>Name</th>
			<th>Description</th>
        </tr>
        <?php while($row1 = mysqli_fetch_array($result1)):; ?>
        <tr>
			<td><?php echo $row1[0]; ?></td>
			<td><?php echo $row1[1]; ?></td>
			<td><?php echo $row1[2]; ?></td>
        </tr>
        <?php endwhile; ?>
      </table>


	<!Add Faction Form>
	<div class = "addform">
    <form method="post" action="insert_faction.php">
			<input type="hidden" name="submitted" value="true" />
			<legend>Add Faction</legend>
			<div class="form-group">
				<label for="factionnameinput">Name</label>
				<input type="text" name="name" class="form-control" id="factionnameinput" placeholder="">
			</div>
			<div class="form-group">
				<label for="description">Description</label>
				<input type="text" name="description" class="form-control" id="description" placeholder="">
				</div>
        <button type="submit" class="btn btn-default">Submit</button>
    </form>
	</div>
	 
	 <!Edit Faction Form>
	 <div class = "editform">
	 <form method="post" action="update_faction.php">
			<input type="hidden" name="submitted" value="true" />
			<legend>Edit</legend>
			<div class="form-group">
				<label for="name">ID</label>
				<input type="text" name="factionid" class="form-control" id="factionid" placeholder="">
			</div>
			<div cla
			<div class="form-group">
				<label for="factionnameinput">Name</label>
				<input type="text" name="name" class="form-control" id="factionnameinput" placeholder="">
			</div>
			<div class="form-group">
				<label for="description">Description</label>
				<input type="text" name="description" class="form-control" id="description" placeholder="">
				</div>
        <button type="submit" class="btn btn-default">Edit</button>
     </form>
	 </div>

    </div> 

    <script src="http://code.jquery.com/jquery.js"></script>
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>