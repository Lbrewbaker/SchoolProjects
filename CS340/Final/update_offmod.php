<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');

    $name = $_POST['name'];
	$weapontype = $_POST['weapontype'];
    $description = $_POST['description'];

    if ($name != "") {
		$sqlupdate = "UPDATE offensivemods SET name='$name' WHERE name='$name'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
	 if ($weapontype != "") {
		$sqlupdate = "UPDATE offensivemods SET weapontype='$weapontype' WHERE name='$name'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }

    if ($description != "") {
		$sqlupdate = "UPDATE offensivemods SET description='$description' WHERE name='$name'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
}

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/offensive.php");
?> 