<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title></title>
</head>
<body>

<%
    String message = (String) session.getAttribute("message");
    out.println(message);
    session.invalidate();
%>

</body>
</html>