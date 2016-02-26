<?php
  include('connection-mysql.php');
  $sqlselect = "SELECT * FROM alliances";
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
          <li><a href="factions.php">Factions</a></li>
          <li><a href="offensive.php">Offensive Mods</a></li>
          <li><a href="defensive.php">Defensive Mods</a></li>
        </ul>
      </div>
    </div>

    <div class="container">
      <h3>Alliances</h3>
      <table class="table table-striped">
        <tr>
          <th>ID</th>
          <th>Name</th>
          <th>Description</th>
		  <th>Factions Involved</th>
        </tr>
        <?php while($row1 = mysqli_fetch_array($result1)):; ?>
        <tr>
          <td><?php echo $row1[0]; ?></td>
          <td><?php echo $row1[1]; ?></td>
          <td><?php echo $row1[2]; ?></td>
		  <td><?php echo $row1[3]; ?></td>
        </tr>
        <?php endwhile; ?>
      </table>

	<!Add Module Form>
    <form method="post" action="insert_alliance.php">
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
        <button type="submit" class="btn btn-default">Submit</button>
    </form>
	 
	 <!Edit Module Form>
	 <form method="post" action="update_alliance.php">
			<input type="hidden" name="submitted" value="true" />
			<legend>Edit Modules</legend>
			<div class="form-group">
				<label for="name">Name</label>
				<input type="text" name="name" class="form-control" id="name" placeholder="">
			</div>
			<div class="form-group">
				<label for="type">Description</label>
				<input type="text" name="description" class="form-control" id="description" placeholder="">
			</div>
        <button type="submit" class="btn btn-default">Submit</button>
     </form>


    <script src="http://code.jquery.com/jquery.js"></script>
    <script src="js/bootstrap.min.js"></script>
</body>
</html>