<?php
  if(isset($_POST['submitted'])) {
    include('connection-mysql.php');

    $name = $_POST['name'];
	$weapontype = $_POST['weapontype'];
    $description = $_POST['description'];

    $sqlinsert = "INSERT INTO offensivemods (name, weapontype, description) VALUES ('$name', '$weapontype', '$description')";
    $insert = $dbcon->query($sqlinsert);

    if(!$insert) {
      die("Error: {$dbcon->errno} : {$dbcon->error}");      
    }
  }

  header("Location:http://web.engr.oregonstate.edu/~brewbakl/CS340/offensive.php");
?>  