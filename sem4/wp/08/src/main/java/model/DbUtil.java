package model;

import java.sql.*;

public abstract class DbUtil {

  protected Connection connection;

  public DbUtil() {
    connect();
  }

  public void connect() {
    try {
      Class.forName("org.gjt.mm.mysql.Driver");
      connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/mirko", "mirko", "mirko");

    } catch (Exception ex) {
      System.out.println("error connecting:" + ex.getMessage());
      ex.printStackTrace();
    }
  }

  protected Statement newStatement() throws SQLException {
    return connection.createStatement();
  }
}
