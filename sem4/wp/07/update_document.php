<?php

$id = $_POST["id"];
$author = $_POST["author"];
$title = $_POST["title"];
$num_pages = $_POST["num_pages"];
$type = $_POST["type"];
$format = $_POST["format"];

$connection = mysqli_connect("localhost", "mirko", "mirko", "mirko");
if(!$connection) {
  die("Couldn't connect: " . mysqli_error($connection));
}

$query = "UPDATE documents SET author = '$author', title = '$title', num_pages = '$num_pages', type = '$type', format = '$format' WHERE id = '$id'";
$result = mysqli_query($connection, $query);

if(mysqli_affected_rows($connection) > 0) {
  $message_type = "success";
  $message = "Successfully updated.";

} else {
  $message_type = "warning";
  $message = "Nothing to update.";
}

echo("<button style=\"width: 100%; white-space: normal\" class=\"btn-$message_type\">$message</button>");

?>
