<%-- 
    Document   : MyFirstJSP
    Created on : Apr 5, 2017, 10:57:41 PM
    Author     : Ajithkumar
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%
            out.println("<h1>Hello World! from JSP</h1>");
        %>
        <a href="myservlet" > Click here for the servlet </a>
    </body>
</html>
