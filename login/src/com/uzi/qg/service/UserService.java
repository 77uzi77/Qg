package com.uzi.qg.service;

import com.uzi.qg.dao.UserDao;
import com.uzi.qg.domain.User;
import org.apache.commons.beanutils.BeanUtils;

import java.lang.reflect.InvocationTargetException;
import java.util.Map;

public class UserService {
    UserDao dao = new UserDao();

    public User getUser(User loginUser, Map userMessage) throws InvocationTargetException, IllegalAccessException {
//        User loginUser = new User();
//        loginUser.setUserName(userName);
//        loginUser.setPassword(password);
        BeanUtils.populate(loginUser,userMessage);

        User user = dao.login(loginUser);

        return user;
    }

    public boolean registerUser(User user){
        if (dao.find(user) != 0) {
        //checked exception
        //unchecked exception
        //这里抛编译时异常的原因：是我想上一层程序处理这个异常，以给用户一个友好提示
            return false;
        }
        dao.add(user);
        return true;
    }
}
