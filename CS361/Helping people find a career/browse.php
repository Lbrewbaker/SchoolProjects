<?php

	include('connection-mysql.php');

	// run sql query to pull career info
	$sqlbrowsequery = "SELECT name, shortDescription, medianpay
	FROM career 
	GROUP BY name";
	$career_query = mysqli_query($dbcon, $sqlbrowsequery);
	
	 // sort pay- descending order 
    $sortpaydescquery = "SELECT name, shortDescription, medianpay 
    FROM  career
    ORDER BY medianpay DESC ";
    $sort_paydesc_query = mysqli_query($dbcon, $sortpaydescquery);
    
    // sort pay- ascending order 
    $sortpayascquery = "SELECT name, shortDescription, medianpay 
    FROM  career
    ORDER BY medianpay ASC";
    $sort_payasc_query = mysqli_query($dbcon, $sortpayascquery);
    
    // sort career by name- descending order 
    $sortnamedescquery = "SELECT name, shortDescription, medianpay 
    FROM  career
    ORDER BY name DESC";
    $sort_namedesc_query = mysqli_query($dbcon, $sortnamedescquery);
    
    // sort career name- ascending order 
    $sortnameascquery = "SELECT name, shortDescription, medianpay 
    FROM  career
    ORDER BY name ASC";
    $sort_nameasc_query = mysqli_query($dbcon, $sortnameascquery);

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
			</div>
		</div>
		
		<!-- information displayed on a table -->
		<div class = "container">
			<h3>Career Information</h3>
			<p>Click the name to find out more information about any job posting</p>
			<table class = "table table-stripped">
				<tr>
					<th>Name
							<form action="browse.php" method="post">
							<input type="submit" class="btn btn-mini" name="NameDes" value="&#x25BC" style="padding: 0; font-size: 8px; line-height: 1;"/>
							<input type="submit" class="btn btn-mini" name="NameAsc" value ="&#x25B2" style="padding: 0; font-size: 8px; line-height: 1;"/>
						</form>
					</th>
					<th>Description</th>
					<th>Median Pay
							<form action="browse.php" method="post">
							<input type="submit" class="btn btn-mini" name="PayDes" value="&#x25BC" style="padding: 0; font-size: 8px; line-height: 1;"/>
							<input type="submit" class="btn btn-mini" name="PayAsc" value ="&#x25B2" style="padding: 0; font-size: 8px; line-height: 1;"/>
						</form>	
					</th>
				</tr>
				
				<?php if(isset($_POST['NameAsc'])):; ?>
					<?php while($careertable = mysqli_fetch_array($sort_nameasc_query)):; ?>
						<tr>
							<td><a href="jobrequirements.php?name=<?php echo $careertable[0]; ?>"><?php echo $careertable[0]; ?></a></td>
							<td><?php echo $careertable[1]; ?></td>
							<td><?php echo $careertable[2]; ?></td>
						</tr>
					<?php endwhile; ?>  
				<?php endif; ?>
        
				<?php if(isset($_POST['NameDes'])):; ?>
					<?php while($careertable = mysqli_fetch_array($sort_namedesc_query)):; ?>
						<tr>
							<td><a href="jobrequirements.php?name=<?php echo $careertable[0]; ?>"><?php echo $careertable[0]; ?></a></td>
							<td><?php echo $careertable[1]; ?></td>
							<td><?php echo $careertable[2]; ?></td>
						</tr>
					<?php endwhile; ?>  
				<?php endif; ?>
        
				<?php if(isset($_POST['PayAsc'])):; ?>
						<?php while($careertable = mysqli_fetch_array($sort_payasc_query)):; ?>
							<tr>
								<td><a href="jobrequirements.php?name=<?php echo $careertable[0]; ?>"><?php echo $careertable[0]; ?></a></td>
								<td><?php echo $careertable[1]; ?></td>
								<td><?php echo $careertable[2]; ?></td>
							</tr>
						<?php endwhile; ?>  
				<?php endif; ?>
        
				<?php if(isset($_POST['PayDes'])):; ?>
						<?php while($careertable = mysqli_fetch_array($sort_paydesc_query)):; ?>
							<tr>
								<td><a href="jobrequirements.php?name=<?php echo $careertable[0]; ?>"><?php echo $careertable[0]; ?></a></td>
								<td><?php echo $careertable[1]; ?></td>
								<td><?php echo $careertable[2]; ?></td>
							</tr>
						<?php endwhile; ?>  
				<?php endif; ?>
				

			</table>
		</div>
		
		
	<script src = "http://code.jquery.com/jquery.js"></script>	
	<script src = "js/bootstrap.min.js"></script>
	</body>
</html>