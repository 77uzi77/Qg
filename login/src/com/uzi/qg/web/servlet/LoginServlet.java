package com.uzi.qg.web.servlet;


import com.uzi.qg.domain.User;
import com.uzi.qg.service.UserService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Map;

@WebServlet("/loginServlet")
public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
//        String userName = request.getParameter("userName");
//        String password = request.getParameter("password");
        Map<String, String[]> parameterMap = request.getParameterMap();

        User user = new User();
        try {
            user = new UserService().getUser(user,parameterMap);
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }

        if (user == null){
            // 转发
            request.setAttribute("login_error","账号或密码错误!");
            request.getRequestDispatcher("/login.jsp").forward(request,response);
        }else{
            // 重定向
            request.getSession().setAttribute("user",user.getUserName());
            response.sendRedirect(request.getContextPath()+"/success.jsp");
        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request,response);
    }
}
