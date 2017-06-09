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
while($row = mysqli_fetch_array($result)) {
  $pics[$index] = array($row["IDPicture"], $row["Filename"], $row["Vote"]);
  $index += 1;
}

for($i = 0; $i < 3; $i += 1) {
  echo("<tr>");
  for($j = 0; $j < 3; $j += 1) {
    $x = 3*$i + $j;
    $idpicture = $pics[$x][0];
    $filename = $pics[$x][1];
    $vote = $pics[$x][2];

    echo("<td onclick=\"interchange($i, $j, $idpicture)\" id=\"cell-$i-$j\">");
    echo("<img src=\"$filename\"><br>");
    echo("Vote: $vote");
    echo("<input type=\"hidden\" name=\"vote-$idpicture\" value=0>");
    echo("<input type=\"hidden\" name=\"x-$idpicture\" value=$i>");
    echo("<input type=\"hidden\" name=\"y-$idpicture\" value=$j>");
    echo("</td>");
  }
  echo("</tr>");
}

echo("</table>");

?>

