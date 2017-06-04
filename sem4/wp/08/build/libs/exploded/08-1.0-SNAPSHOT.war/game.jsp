<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <meta http-equiv="refresh" content="1">
    <title></title>
</head>
<body>

<%
    String username = (String) session.getAttribute("username");
    if (username == null || username.equals("")) {
        out.println("Not connected. <br>");
        out.println("<a href=\"login\">Log in.</a><br>");
        return;
    }

    out.println("Playing as <b>" + username + "</b>!<br>");

    String table = (String) session.getAttribute("table");
    out.println("" + table);
%>

</body>
</html>