<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');

    $name = $_POST['name'];
    $description = $_POST['description'];
	$prim_id = $_POST['prim_id'];
	$sec_id = $_POST['sec_id'];

    $sqlinsert = "INSERT INTO alliances (name, description, primary_faction, secondary_faction) VALUES ('$name', '$description', $prim_id, $sec_id)";
    $insert = $dbcon->query($sqlinsert);

    if(!$insert) {
      die("Error: {$dbcon->errno} : {$dbcon->error}");      
    }
  }

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/alliances.php");
?>  