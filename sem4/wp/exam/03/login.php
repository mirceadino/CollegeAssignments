<?php

session_start();
session_destroy();

$username = $_POST["username"];
$file = $_POST["filename"];
$filelength = $_POST["filelength"];

$connection = mysqli_connect("localhost", "exam", "exam", "exam");
if(!$connection) {
  die("Couldn't connect: " . mysqli_error($connection));
}

$query = "SELECT * FROM User WHERE Username='$username' AND File='$file' AND FileLength='$filelength'";
$result = mysqli_query($connection, $query);

$message = "";
$admin = 0;

if(mysqli_affected_rows($connection) > 0) {
  $message = "Authentification succeeded.";

  while($row = mysqli_fetch_array($result)) {
    $admin = $row["Admin"];
  }

  session_start();
  $_SESSION["username"] = $username;
  $_SESSION["admin"] = $admin;

} else {
  $message = "Authentification failed.";
}

$message = $message . "<br>";
$message = $message . "<a href=\"vote.html\">Vote here</a><br>";

if($admin) {
  $message = $message . "<a href=\"change.html\">Change pics here</a><br>";
}

echo($message);

?>
