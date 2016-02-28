<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');

    $name = $_POST['name'];
	$deftype = $_POST['deftype'];
    $description = $_POST['description'];
	$fact_id = $_POST['fact_id'];

    $sqlinsert = "INSERT INTO defensivemods (name, deftype, description, fact_id) VALUES ('$name', '$deftype', '$description', $fact_id)";
    $insert = $dbcon->query($sqlinsert);

    if(!$insert) {
      die("Error: {$dbcon->errno} : {$dbcon->error}");      
    }
  }

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/defensive.php");
?>  