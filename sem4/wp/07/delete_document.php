<?php

$id = $_POST["id"];

$connection = mysqli_connect("localhost", "mirko", "mirko", "mirko");
if(!$connection) {
  die("Couldn't connect: " . mysqli_error($connection));
}

$query = "DELETE FROM documents WHERE id=$id";
$result = mysqli_query($connection, $query);

if($result) {
  $message_type = "success";
  $message = "Successfully deleted.";

} else {
  $message_type = "danger";
  $message = mysqli_error($connection);
}

echo("<button style=\"width: 100%; white-space: normal\" class=\"btn-$message_type\">$message</button>");

?>
