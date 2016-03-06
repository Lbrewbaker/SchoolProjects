<?php

	include('connection-mysql.php');
	
	//query for job requirements based on which one they select
	$jobname = $_GET["name"];
	
	$idquery = "SELECT id FROM career WHERE name = '$jobname'";
	$idfetch = mysqli_query($dbcon, $idquery);
	$job_id = mysqli_fetch_array($idfetch);
	
	$sqlreqquery = "SELECT c.description, r.description, c.medianpay
		FROM career AS c
		INNER JOIN requirements AS r ON c.id = r.jobid
		WHERE c.name = '$jobname'";
	$requirements_query = mysqli_query($dbcon, $sqlreqquery);
	$reqdata = mysqli_fetch_array($requirements_query);
	
	
	 
?>

<!DOCTYPE html>
<html>
	<head>
		<title>Find a Career!</title>
        <link href="css/bootstrap.min.css" rel="stylesheet" media="screen">
	</head>
	<body>
	
		<!-- nav bar -->
		<div class = "navbar navbar-inverse">
			<div class = "navbar-inner">
				<a class = "brand" href="index.html"> Career's Home Page</a>
					<ul class = "nav navbar-nav navbar-right">
						<li><a href = "browse.php">Browse</a></li>
					</ul>
			</div>
		</div>
		
		<div class = "container">
			<h3>Job Requirements for <?php echo $jobname; ?></h3>
			
			<strong>Full Description:</strong>
			<br>
			<?php echo $reqdata[0]; ?>
			<br><br>
			
			<strong>Requirements:</strong>
			<br>
			<?php echo $reqdata[1]; ?>
			<br><br>
			
			<strong>Pay:</strong>
			<br>
			<?php echo $reqdata[2]; ?>
			
		</div>
		
		
	<script src = "http://code.jquery.com/jquery.js"></script>	
	<script src = "js/bootstrap.min.js"></script>
	</body>
</html>