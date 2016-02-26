<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');

    $name = $_POST['name'];
	$deftype = $_POST['deftype'];
    $description = $_POST['description'];

    $sqlinsert = "INSERT INTO defensivemods (name, deftype, description) VALUES ('$name', '$deftype', '$description')";
    $insert = $dbcon->query($sqlinsert);

    if(!$insert) {
      die("Error: {$dbcon->errno} : {$dbcon->error}");      
    }
  }

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/defensive.php");
?>  