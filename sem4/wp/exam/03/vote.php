<?php

session_start();

$username = $_SESSION["username"];
$admin = $_SESSION["admin"];

if($username=="") {
  die("Not authentificated.");
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
while($row = mysqli_fetch_array($result)) {
  $pics[$index] = array($row["IDPicture"], $row["Filename"], $row["Vote"]);
  $index += 1;
}

for($i = 0; $i < 3; $i += 1) {
  for($j = 0; $j < 3; $j += 1) {
    $x = 3*$i + $j;
    $idpicture = $pics[$x][0];
    $filename = $pics[$x][1];
    $vote = $pics[$x][2];
    $increment = $_POST["vote-" . $idpicture];

    echo("Add $filename $increment<br>");
    $vote += $increment;

    $query = "UPDATE Picture SET Vote = '$vote' WHERE IDPicture = '$idpicture'";
    $result = mysqli_query($connection, $query);
  }
}

header("Location: vote.html");

?>

