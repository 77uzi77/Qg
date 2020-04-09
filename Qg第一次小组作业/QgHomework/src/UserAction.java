import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.regex.Pattern;


public class UserAction {
    // 用户输入
    public String[] userInput(){
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入用户名：");
        String userName = sc.nextLine();
        System.out.println("请输入密码：");
        String password = sc.nextLine();

        String[] userMessage = new String[2];
        userMessage[0] = userName;
        userMessage[1] = password;

        return userMessage;
    }

    // 注册
    public boolean register(String userName,String password){

        String sql = "insert into user (user_name,password) VALUES (?,?)";
        int result = DBUtils.update(sql,userName,password);


        return result != 0;
    }

    // 判断用户是否存在
    public boolean isExit(String userName){
        String sql = "select user_name from user where user_name = ?";
        List<Map<String, Object>> user = DBUtils.query(sql, userName);

        return user.size() != 0;
    }
    // 登录
    public boolean login(String userName,String password){

        String sql = "select user_name from user where user_name = ? AND password = ?";
        List<Map<String, Object>> user = DBUtils.query(sql, userName, password);


        return user.size() != 0;
    }

   // 用户写入
    public void writeAction(String userName){

        FileWriter input = null;
        try {
            Scanner sc = new Scanner(System.in);

            System.out.println("请输入想要更新内容的目录：");
            String filePath = sc.nextLine();
            input = new FileWriter(filePath, true);

            System.out.println("请输入想要更新的行数:");
            String lineNum = sc.nextLine();
            Pattern pattern = Pattern.compile("^[-\\+]?[\\d]*$");
            while ( !pattern.matcher(lineNum).matches() || lineNum.equals("")  ){
                System.out.println("请正确输入的行数:");
                lineNum = sc.nextLine();
            }
            System.out.println("请输入想要更新的内容：");
            for (int i = 0; i < Integer.parseInt(lineNum); i++) {
                String text = sc.nextLine();
                writeRecord( userName,text + "\n");
                input.write(text);
                input.write("\r\n");
            }
        }catch (IOException e){
            System.out.println("请输入正确的文件目录！");
            e.printStackTrace();
        }finally {
            try{
                if (input != null){
                    input.close();
                }
            }catch (IOException e){
                e.printStackTrace();
            }
        }
    }

    // 历史输入
    public void showHistory(String name) {
        String sql = "select text from user where user_name = ?";
        List<Map<String, Object>> text = DBUtils.query(sql, name);

        String history = (String) text.get(0).get("text");

        System.out.println(history);
    }


    // 记录输入
    public void writeRecord(String userName,String text){
        String sql_history = "select text from user where user_name = ?";
        List<Map<String, Object>> historyText = DBUtils.query(sql_history, userName);

        String nowText =  historyText.get(0).get("text") + text;
        String sql_add = "update user set text = ? where user_name = ? ";
        DBUtils.update(sql_add, nowText, userName);

    }
}
