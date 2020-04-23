package com.uzi.qg.web.formbean;

import java.util.HashMap;
import java.util.Map;

public class RegisterFormBean {
    private String userName;
    private String password;
    private String confirmPwd;
    private Map<String, String> errors = new HashMap<String, String>();

    public Map<String, String> getErrors() {
        return errors;
    }

    public void setErrors(Map<String, String> errors) {
        this.errors = errors;
    }

    public boolean validate() {
        boolean isOk = true;
        if (this.userName == null || this.userName.trim().equals("")){
            isOk = false;
            errors.put("userName", "用户名不能为空！！");
        }

        if (this.password == null || this.password.trim().equals("")){
            isOk = false;
            errors.put("password", "密码不能为空！！");
        }

        if (this.confirmPwd != null) {
            if (!this.confirmPwd.equals(this.password)) {
                isOk = false;
                errors.put("confirmPwd", "两次密码不一致！！");
            }
        }
        return isOk;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getConfirmPwd() {
        return confirmPwd;
    }

    public void setConfirmPwd(String confirmPwd) {
        this.confirmPwd = confirmPwd;
    }
}
