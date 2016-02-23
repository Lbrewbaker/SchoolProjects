<?php
  include('connection-mysql.php');
  $sqldefensive = "SELECT name FROM defensive";
  $result2 = mysqli_query($dbcon, $sqldefensive); 

  // run sql query to make name dynamically appear
  $factionID = $_GET["factionID"];
  $sqlname = "SELECT name FROM faction WHERE factionID='$factionID'";
  $name_query = mysqli_query($dbcon, $sqlname);
  $name = mysqli_fetch_array($name_query);

  /*
  
  Maybe use to dispaly the full offensive/defensive sub systems per faction.
  // run sql query to pull up students class schedule
  $sqlschedule = "SELECT c.course_id, c.name, r.room_num, t.lname FROM courses AS c LEFT JOIN students_courses AS sc ON c.course_id=sc.course_id LEFT JOIN students AS s ON sc.student_id=s.student_id LEFT JOIN teachers AS t ON c.teacher_id=t.teacher_id LEFT JOIN classrooms AS r ON c.teacher_id=r.teacher_id WHERE sc.student_id='$student_id'";
  $schedule_query = mysqli_query($dbcon, $sqlschedule);
   
   */
?>

<!DOCTYPE html>
<html>
  <head>
    <title>CS340 Final Project - EVE Online Ship DB</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!-- Bootstrap -->
    <link href="css/bootstrap.min.css" rel="stylesheet" media="screen">
  </head>
  <body>
    <div class="navbar navbar-inverse">
      <div class="navbar-inner">
        <a class="brand" href="index.html">CS340 Final Project</a>
        <ul class="nav navbar-nav navbar-right">
          <li><a href="factions.php">Factions</a></li>
          <li><a href="offense.php">Offensive Modules</a></li>
          <li><a href="defensive.php">Defensive Modules</a></li>
          <li><a href="specializations.php">Speciallizations</a></li>
        </ul>
      </div>
    </div>

    <div class="container">
      <h3>Class Schedule For <?php echo $name[0]; ?></h3>
      <table class="table table-striped">
        <tr>
          <th>Course</th>
          <th>Room</th>
          <th>Instructor</th>
          <th></th>
        </tr>
        <?php while($schedule = mysqli_fetch_array($schedule_query)):; ?>
        <tr>
          <td><?php echo $schedule[1]; ?></td>
          <td><?php echo $schedule[2]; ?></td>
          <td><?php echo $schedule[3]; ?></td>
          <td><a href="remove_course.php?studentID=<?php echo $student_id; ?>&amp;courseID=<?php echo $schedule[0]; ?>">Remove</td>
        </tr>
        <?php endwhile; ?>
      </table>


      <form method="post" action="add_student_to_course.php">
        <input type="hidden" name="submitted" value="true" />
        <input type="hidden" name="student_id" value="<?php echo htmlspecialchars($_GET["studentID"]); ?>" />
        <legend>Add Class</legend>
        <div class="form-group">
          <label for="classinputteacher">Teacher</label>
          <select class="form-control" name="class">
            <?php while($row1 = mysqli_fetch_array($result2)):; ?>
              <option><?php echo $row1[0]; ?></option>
            <?php endwhile; ?>
          </select>
        </div>
        <button type="submit" class="btn btn-default">Submit</button>
      </form>

      <form method="post" action="update_student.php">
        <input type="hidden" name="submitted" value="true" />
        <input type="hidden" name="student_id" value="<?php echo htmlspecialchars($_GET["studentID"]); ?>" />
        <legend>Update Student</legend>
        <div class="form-group">
          <label for="studentinputname">Name</label>
          <input type="text" name="name" class="form-control" id="studentinputname" placeholder="">
        </div>
        <div class="form-group">
          <label for="studentinputaddress">Address</label>
          <input type="text" name="address" class="form-control" id="studentinputlname" placeholder="">
        </div>
        <div class="form-group">
          <label for="studentinputphone">Phone Number</label>
          <input type="text" name="phone" class="form-control" id="studentinputphone" placeholder="">
        </div>
        <button type="submit" class="btn btn-default">Submit</button>
      </form>

    </div> 

    <script src="http://code.jquery.com/jquery.js"></script>
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>