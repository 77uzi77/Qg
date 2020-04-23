<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE HTML>
<html>
<head>
    <title>用户注册</title>
</head>
<body style="text-align: center;">
<form action="${pageContext.request.contextPath}/registerServlet" method="post">
    <table width="%" border="">
        <tr>
            <td>用户名</td>
            <td>
                <%--使用EL表达式${}提取存储在request对象中的formBean对象中封装的表单数据(formBean.userName)以及错误提示消息(formBean.errors.userName)--%>
                <input type="text" name="userName" value="${formBean.userName}">${formBean.errors.userName}
            </td>
        </tr>
        <tr>
            <td>密码</td>
            <td>
                <input type="password" name="password" value="${formBean.password}">${formBean.errors.password}
            </td>
        </tr>
        <tr>
            <td>确认密码</td>
            <td>
                <input type="password" name="confirmPwd" value="${formBean.confirmPwd}">${formBean.errors.confirmPwd}
            </td>
        </tr>
        <tr>
            <td>
                <input type="reset" value="清空">
            </td>
            <td>
                <input type="submit" value="注册">
            </td>
        </tr>
    </table>
</form>
</body>
</html>