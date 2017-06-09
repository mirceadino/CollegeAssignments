<?php

session_start();

$username = $_SESSION["username"];
$admin = $_SESSION["admin"];

if($username=="" || $admin!=1) {
  die("Not authentificated as admin.");
}

$connection = mysqli_connect("localhost", "exam", "exam", "exam");
if(!$connection) {
  die("Couldn't connect: " . mysqli_error($connection));
}

echo("<table>");

$pics = array();
$index = 0;
for($x = 0; $x < 9; $x += 1) {
  $id = $_POST["id_" . $x];
  $filename = $_POST["filename_" . $x];
  $vote = $_POST["vote_" . $x];

  $query = "UPDATE Picture SET Filename = '$filename', Vote = '$vote' WHERE IDPicture = '$id'";
  $result = mysqli_query($connection, $query);
}

header("Location: change.html");

?>

