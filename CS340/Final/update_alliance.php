<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');
	
	$allianceid = $_POST['allianceid'];
    $name = $_POST['name'];
    $description = $_POST['description'];
	$ally_id = $_POST['ally_id'];

    if ($name != "") {
		$sqlupdate = "UPDATE alliances SET name='$name' WHERE allianceid='$allianceid'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }

    if ($description != "") {
		$sqlupdate = "UPDATE alliances SET description='$description' WHERE allianceid='$allianceid'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
	if ($ally_id != "") {
		$sqlupdate = "UPDATE alliances SET ally_id='$ally_id' WHERE allianceid='$allianceid'";
		$insert = $dbcon->query($sqlupdate);

		if(!$insert) {
			die("Error: {$dbcon->errno} : {$dbcon->error}");      
		}
    }
	
}

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/alliances.php");
?> 