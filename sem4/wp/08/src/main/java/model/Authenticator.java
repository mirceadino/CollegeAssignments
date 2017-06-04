package model;

import java.sql.*;

public class Authenticator extends DbUtil {

  public String authenticate(String username, String password) {
    String query = "SELECT * FROM users WHERE username='" + username + "' AND password='" + password + "'";
    try (ResultSet resultSet = newStatement().executeQuery(query)) {
      if (resultSet.next()) {
        return "success";
      }

    } catch (SQLException e) {
      e.printStackTrace();
    }

    return "error";
  }
}