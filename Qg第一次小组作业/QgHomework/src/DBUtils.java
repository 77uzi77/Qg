import java.io.FileInputStream;
import java.sql.*;
import java.util.*;


public class DBUtils {
    private static  String user;
    private static  String password;
    private static  String url;
    private static  String driver;

    // 静态代码块，只执行一次，效率高
    static {
        try {
            //利用 Properties类载入 数据库相关信息
            Properties info = new Properties();
            info.load(new FileInputStream("src/jdbc.properties"));
            user = info.getProperty("user");
            password = info.getProperty("password");
            url = info.getProperty("url");
            driver = info.getProperty("driver");

            //注册驱动
            Class.forName(driver);
        } catch ( Exception e){
            throw new RuntimeException(e); // 转换为运行时异常
        }

    }

    // 获取连接
    public static Connection getConnection() throws SQLException{

        return DriverManager.getConnection(url,user,password);
    }

    // 释放资源
    public static void close(ResultSet set,Statement statement,Connection connection){
        try{
            if(set != null){
                set.close();
            }
            if (statement != null){
                statement.close();
            }
            if (connection != null){
                connection.close();
            }
        }catch (Exception e){
            throw new RuntimeException(e);  // 转换为运行时异常
        }

    }
    // 增删改操作
    public static int update(String sql,Object... params){
        // 利用可变参数存放 操作值
        Connection conn = null;
        PreparedStatement statement = null;
        int result = 0;
        try{
            conn = getConnection();
            statement = conn.prepareStatement(sql);
            // 将操作值一一对应，给预编译语句赋值
            for (int i = 0; i < params.length; i++){
                statement.setObject(i+1,params[i]);
            }
            result = statement.executeUpdate(); // 返回受影响的行数
        } catch (SQLException e){
            e.printStackTrace();
        } finally {
            // 关闭数据库连接，释放资源
            close(null,statement,conn);
        }
        // 将结果返回，返回0为操作失败
        return result;
    }

    // 查询操作
    public static List<Map<String,Object>> query(String sql, Object... args){ //可变参数
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet set = null;
        try {
            conn = getConnection();
            ps = conn.prepareStatement(sql);
            /* 有可能有参数 */
            for (int i=0;i<args.length;i++){
                ps.setObject(i+1,args[i]);
            }
            /*执行*/
            set = ps.executeQuery();
            /*需要将所有数据都存放到 List中    每一行 用一个 map存放*/
            List<Map<String,Object>> list = new ArrayList<>();
            /*获取本次查询结果集有多少列*/
            int count = set.getMetaData().getColumnCount();

            while(set.next()){
                Map<String, Object> map = new HashMap<>();//一行数据 用一个map 接收
                /*
                不用在乎数据库表中有几列
                通过  getMetData().getColumnLabel() 获取列
                因为用的map键值对集合  得到了列  就能得到相应的values值
                 */
                for(int i=0;i<count;i++){
                    String name = set.getMetaData().getColumnLabel(i+1);
                    map.put(name,set.getObject(name));
                }
                /*将每行的map存放到 List中*/
                list.add(map);
            }
            return list;
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            close(set,ps,conn);
        }
        return null;
    }

    // 测试 数据库
    public static void main(String[] args) throws SQLException {
        Connection connection = DBUtils.getConnection();
        System.out.println(connection);
        String sql = "select * from user";
        List<Map<String, Object>> list = DBUtils.query(sql);
        for (Map<String, Object> stringObjectMap : list) {
            System.out.println(stringObjectMap);
        }
    }

}


