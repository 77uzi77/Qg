

import java.util.Scanner;



public class homework1 {



    public static void main(String[] args){
        UserAction userAction = new UserAction();
        String name;
        System.out.println("请输入您想进行的操作：");
        while (true) {
            System.out.println("1.注册");
            System.out.println("2.登录");
            System.out.println("0.退出");
            Scanner userInput = new Scanner(System.in);
            int userChoose = userInput.nextInt();
            if (userChoose == 1) {
                String[] userMessage = userAction.userInput();
                String userName = userMessage[0];
                String password = userMessage[1];

                if ( !userAction.isExit(userName) ) {
                    if (userAction.register(userName, password)) {
                        System.out.println("注册成功！");
                        name = userName;
                        break;
                    }
                } else {
                    System.out.println("该用户名已存在，请重新注册或登录！");
                }
            } else if (userChoose == 2) {
                String[] userMessage = userAction.userInput();
                String userName = userMessage[0];
                String password = userMessage[1];
                if ( userAction.login(userName, password) ) {
                    System.out.println("登录成功！");
                    name = userName;
                    break;
                } else {
                    System.out.println("账号或密码错误，请重新输入！");
                }
            } else if (userChoose == 0) {
                System.exit(0);
            }else{
                System.out.println("请输入正确的选项！");
            }
        }

        System.out.println("欢迎使用！");
        System.out.println("请输入您想进行的操作：");
        while (true){
            System.out.println("1.查看历史输入");
            System.out.println("2.增加输入");
            System.out.println("0.退出");
            Scanner input = new Scanner(System.in);
            int action = input.nextInt();
            if ( action == 0){
                System.exit(0);
            }else if (action == 1){
                userAction.showHistory(name);
            }else if (action == 2){
                 userAction.writeAction(name);
            }
        }

    }

}
