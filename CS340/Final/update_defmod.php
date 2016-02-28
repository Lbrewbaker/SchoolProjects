<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');

	$deffmodid = $_POST['deffmodid'];
	$name = $_POST['name'];
	$moduletype = $_POST['moduletype'];
    $description = $_POST['description'];
	$fact_id = $_POST['fact_id'];

    if ($name != "") {
		$sqlupdate = "UPDATE defensivemods SET name='$name' WHERE deffmodid='$deffmodid'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
	 if ($deftype != "") {
		$sqlupdate = "UPDATE defensivemods SET deftype='$deftype' WHERE deffmodid='$deffmodid'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }

    if ($description != "") {
		$sqlupdate = "UPDATE defensivemods SET description='$description' WHERE deffmodid='$deffmodid'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
		if ($fact_id != "") {
		$sqlupdate = "UPDATE defensivemods SET fact_id='$fact_id' WHERE deffmodid='$deffmodid'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
}

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/defensive.php");
?> 