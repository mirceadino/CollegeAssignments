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

    echo("<tr>");
    echo("<td>");
    echo("<input type=\"hidden\" value=\"$idpicture\" name=\"id_$x\">");
    echo("Filename: <input type=\"text\" value=\"$filename\" name=\"filename_$x\">");
    echo("Vote: <input type=\"text\" value=\"$vote\" name=\"vote_$x\">");
    echo("</td>");
    echo("</tr>");
  }
}

echo("</table>");

?>

