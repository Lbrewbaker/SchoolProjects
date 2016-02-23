<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');

    $factionid = $_POST['factionid'];
    $name = $_POST['name'];
    $description = $_POST['description'];

    if ($name != "") {
      $sqlupdate = "UPDATE factions SET name='$name' WHERE name='$name'";
      $insert = $dbcon->query($sqlupdate);

      if(!$insert) {
        die("Error: {$dbcon->errno} : {$dbcon->error}");      
      }
    }

    if ($description != "") {
      $sqlupdate = "UPDATE factions SET description='$description' WHERE name='$name'";
      $insert = $dbcon->query($sqlupdate);

      if(!$insert) {
        die("Error: {$dbcon->errno} : {$dbcon->error}");      
      }
    }
	
}

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/factions.php");
?> 