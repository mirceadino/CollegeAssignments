<?php

$author = $_POST["author"];
$title = $_POST["title"];
$num_pages = $_POST["num_pages"];
$type = $_POST["type"];
$format = $_POST["format"];

$connection = mysqli_connect("localhost", "mirko", "mirko", "mirko");
if(!$connection) {
  die("Couldn't connect: " . mysqli_error($connection));
}

$query = "INSERT INTO documents (author, title, num_pages, type, format) VALUES ('$author', '$title', '$num_pages', '$type', '$format')";
$result = mysqli_query($connection, $query);

if($result) {
  $message_type = "success";
  $message = "Successfully added.";

} else {
  $message_type = "danger";
  $message = mysqli_error($connection);
}

echo("<button style=\"width: 100%; white-space: normal\" class=\"btn-$message_type\">$message</button>");

?>
