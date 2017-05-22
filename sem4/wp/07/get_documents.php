<?php

$filter_type = $_POST["filter_type"];
$filter_text = $_POST["filter_text"];

$connection = mysqli_connect("localhost", "mirko", "mirko", "mirko");
if(!$connection) {
  die("Couldn't connect: " . mysqli_error($connection));
}

$query = "SELECT * FROM documents";
if(strlen($filter_text)) {
  $query = $query . " WHERE $filter_type LIKE '$filter_text%'";
}
$result = mysqli_query($connection, $query);

echo("<table class=\"table\">");
echo("<tr>");
echo("<th>Id</th>");
echo("<th>Author</th>");
echo("<th>Title</th>");
echo("<th>Num. pages</th>");
echo("<th>Type</th>");
echo("<th>Format</th>");
echo("<th></th>");
echo("</tr>");

while($row = mysqli_fetch_array($result)) {
  echo("<tr>");
  echo("<td>" . $row["id"] . "</td>");
  echo("<td>" . $row["author"] . "</td>");
  echo("<td>" . $row["title"] . "</td>");
  echo("<td>" . $row["num_pages"] . "</td>");
  echo("<td>" . $row["type"] . "</td>");
  echo("<td>" . $row["format"] . "</td>");
  echo("<td>

    <button type=\"button\" name=\"delete\"
    onclick=\"deleteDocument(" . $row["id"] . ")\">
    delete</button>

    <button type=\"button\" name=\"update\"
    onclick=\"preUpdateDocument("
    . $row["id"] . ",'"
    . $row["author"] . "','"
    . $row["title"] . "','"
    . $row["num_pages"] . "','"
    . $row["type"] . "','"
    . $row["format"] .
    "')\">update</button>

    </td>");
  echo("</tr>");
}

echo("</table>");

?>
