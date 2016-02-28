<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');

	$offmodid = $_POST['offmodid'];
    $name = $_POST['name'];
	$weapontype = $_POST['weapontype'];
    $description = $_POST['description'];
	$fact_id = $_POST['fact_id'];
	
	//query to get faction id
	$sql_fact_id = mysqli_query($dbcon, "SELECT factionid FROM factions WHERE offmodid='$offmodid'");
	

    if ($name != "") {
		$sqlupdate = "UPDATE offensivemods SET name='$name' WHERE offmodid='$offmodid'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
	 if ($weapontype != "") {
		$sqlupdate = "UPDATE offensivemods SET weapontype='$weapontype' WHERE offmodid='$offmodid'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }

    if ($description != "") {
		$sqlupdate = "UPDATE offensivemods SET description='$description' WHERE offmodid='$offmodid'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
    if ($fact_id != "") {
		$sqlupdate = "UPDATE offensivemods SET fact_id='$fact_id' WHERE offmodid='$offmodid'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
}

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/offensive.php");
?> 