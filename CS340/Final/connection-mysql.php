<?php
  error_reporting(E_ALL);

  DEFINE ('DB_USER', 'ENTER_YOUR_INFO');
  DEFINE ('DB_PSWD', 'ENTER_YOUR_INFO');
  DEFINE ('DB_HOST', 'ENTER_YOUR_INFO');
  DEFINE ('DB_NAME', 'ENTER_YOUR_INFO');

  $dbcon = mysqli_connect(DB_HOST, DB_USER, DB_PSWD, DB_NAME);
  if($dbcon->connect_errno) {
    echo "Connection error " . $dbcon->connect_errno . " " . $dbcon->connect_error;
  }
?>