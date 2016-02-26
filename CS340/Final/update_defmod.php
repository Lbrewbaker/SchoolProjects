<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');

    $name = $_POST['name'];
	$moduletype = $_POST['moduletype'];
    $description = $_POST['description'];

    if ($name != "") {
		$sqlupdate = "UPDATE defensivemods SET name='$name' WHERE name='$name'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
	 if ($deftype != "") {
		$sqlupdate = "UPDATE defensivemods SET deftype='$deftype' WHERE name='$name'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }

    if ($description != "") {
		$sqlupdate = "UPDATE defensivemods SET description='$description' WHERE name='$name'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
}

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/defensive.php");
?> 