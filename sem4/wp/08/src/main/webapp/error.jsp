<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title></title>
</head>
<body>

<%
    session.invalidate();
%>

Login failed or there are too many players in the game! <br>
<a href="login">Try again.</a><br>

</body>
</html>