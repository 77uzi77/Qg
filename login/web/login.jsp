<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<html>
<head>
    <meta charset="UTF-8">
    <title>登陆</title>
    <style>
        div{
            color:red;
        }
    </style>
</head>
<body>
    <form action="${pageContext.request.contextPath}/loginServlet" method="post">
        用户名:<input type="text" name="userName"><br>
        密码:<input type="password" name="password"><br>

        <a href="register.jsp">注册</a>
        <input type="submit" value="登录">

    </form>

    <div>
        ${requestScope.login_error}
    </div>

</body>
</html>
