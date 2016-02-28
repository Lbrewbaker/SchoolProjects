<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');

    $name = $_POST['name'];
	$weapontype = $_POST['weapontype'];
    $description = $_POST['description'];
	$fact_id = $_POST['fact_id'];
	
	//query to get faction id
	$sql_fact_id = mysqli_query($dbcon, "SELECT factionid FROM factions WHERE name='$name'");
	//figure out how to get the faction name to insert into the display table.
	

    $sqlinsert = "INSERT INTO offensivemods (name, weapontype, description, fact_id) VALUES ('$name', '$weapontype', '$description', '$fact_id')";
    $insert = $dbcon->query($sqlinsert);

    if(!$insert) {
      die("Error: {$dbcon->errno} : {$dbcon->error}");      
    }
  }

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/offensive.php");
?>  