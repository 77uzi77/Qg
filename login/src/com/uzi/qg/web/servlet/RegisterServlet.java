package com.uzi.qg.web.servlet;

import com.uzi.qg.domain.User;
import com.uzi.qg.service.UserService;
import com.uzi.qg.util.WebUtils;
import com.uzi.qg.web.formbean.RegisterFormBean;
import org.apache.commons.beanutils.BeanUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/registerServlet")
public class RegisterServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //将客户端提交的表单数据封装到RegisterFormBean对象中
        RegisterFormBean formBean = WebUtils.requestBean(request,RegisterFormBean.class);
        if ( !formBean.validate() ) {//如果校验失败
            //将封装了用户填写的表单数据的formBean对象发送回register.jsp页面的form表单中进行显示
            request.setAttribute("formBean", formBean);
            //校验失败就说明是用户填写的表单数据有问题，那么就跳转回register.jsp
            request.getRequestDispatcher("register.jsp").forward(request, response);
            return;
        }
        User user = new User();
        try {

            BeanUtils.copyProperties(user, formBean);//把表单的数据填充到javabean中
            user.setId(WebUtils.makeId());//设置用户的Id属性
            //IUserService service = new UserServiceImpl();
            UserService service = new UserService();
            //调用service层提供的注册用户服务实现用户注册
            if ( service.registerUser(user) ) {
                String message = String.format(
                        "注册成功！！3秒后为您自动跳到登录页面！！<meta http-equiv='refresh' content='3;url=login.jsp'>");
                request.setAttribute("message",message);
                request.getRequestDispatcher("/message.jsp").forward(request,response);

            }else{
                formBean.getErrors().put("userName","注册用户已存在！");
                request.setAttribute("formBean", formBean);
                request.getRequestDispatcher("/register.jsp").forward(request, response);
            }
//        } catch (UserExistException e) {
//            formBean.getErrors().put("userName", "注册用户已存在！！");
//            request.setAttribute("formBean", formBean);
//            request.getRequestDispatcher("/WEB-INF/pages/register.jsp").forward(request, response);
        } catch (Exception e) {
            e.printStackTrace(); // 在后台记录异常
            //request.setAttribute("message", "对不起，注册失败！！");
            //request.getRequestDispatcher("/message.jsp").forward(request,response);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request,response);
    }
}
