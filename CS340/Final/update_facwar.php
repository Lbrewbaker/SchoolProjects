<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');
	
	$allianceid = $_POST['allianceid'];
    $name = $_POST['name'];
    $description = $_POST['description'];
	$fac_id = $_POST['fac_id'];

    if ($name != "") {
		$sqlupdate = "UPDATE factionwar SET name='$name' WHERE facwarid='$fac_id'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }

    if ($description != "") {
		$sqlupdate = "UPDATE factionwar SET description='$description' WHERE facwarid='$fac_id'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
	if ($fac_id != "") {
		$sqlupdate = "UPDATE factionwar SET fac_id='$fac_id' WHERE facwarid='$fac_id'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
}

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/faction_warfare.php");
?> 