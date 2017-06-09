<?php

session_start();

$username = $_SESSION["username"];
$admin = $_SESSION["admin"];

if($username=="") {
  die("Not authentificated.");
}

if($admin ==1) {
  echo("<a href=\"change.html\">Change pics here</a><br>");
}

$connection = mysqli_connect("localhost", "exam", "exam", "exam");
if(!$connection) {
  die("Couldn't connect: " . mysqli_error($connection));
}

$query = "SELECT * FROM Picture";
$result = mysqli_query($connection, $query);

echo("<table>");

$pics = array();
$index = 0;
$sum = 0;
while($row = mysqli_fetch_array($result)) {
  $pics[$index] = array($row["IDPicture"], $row["Filename"], $row["Vote"]);
  $index += 1;
  $sum += $row["Vote"];
}

$mean = $sum / 9;
$average_pic = 0;
$best_diff = $pics[0][2];

for($x = 0; $x < 9; $x += 1) {
  $idpicture = $pics[$x][0];
  $filename = $pics[$x][1];
  $vote = $pics[$x][2];
  $diff = $mean - $vote;
  if($diff < 0) $diff = -$diff;
  if($diff < $best_diff) {
    $average_pic = $x;
    $best_diff = $diff;
  }
}

$filename = $pics[$average_pic][1];
$vote = $pics[$average_pic][2];
echo("<img src=\"$filename\"><br>");
echo("Vote: $vote<br>");
echo("Average is: $mean");

?>

