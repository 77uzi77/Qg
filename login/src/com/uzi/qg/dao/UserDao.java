package com.uzi.qg.dao;

import com.uzi.qg.domain.User;
import com.uzi.qg.util.JDBCUtils;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

import java.util.List;
import java.util.Map;

public class UserDao {

    private JdbcTemplate template = new JdbcTemplate(JDBCUtils.getDataSource());

    public User login(User loginUser){
        try {
            String sql = "select * from user where userName = ? and password = ?";
            User user = template.queryForObject(sql,
                    new BeanPropertyRowMapper<User>(User.class),
                    loginUser.getUserName(),loginUser.getPassword());

            return user;
        } catch (DataAccessException e) {
            //e.printStackTrace();  // 记录日志
            return null;
        }
    }

    public int find(User user){
        String sql = "select id from user where userName = ?";
        List<Map<String, Object>> maps = template.queryForList(sql, user.getUserName());

        return maps.size();
    }

    public void add(User user) {
        String sql = "insert into user (userName,password) values (?,?)";
        template.update(sql,user.getUserName(),user.getPassword());
    }
}
