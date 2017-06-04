package model;

import java.sql.*;

public class StateRecorder extends DbUtil {

  public int getNumPlayersPerGame(String gameId) {
    String query = "SELECT username FROM users_games WHERE gameId='" + gameId + "'";
    try (ResultSet resultSet = newStatement().executeQuery(query)) {
      resultSet.last();
      return resultSet.getRow();

    } catch (SQLException e) {
      e.printStackTrace();
    }

    return 0;
  }

  public boolean isUserConnected(String username, String gameId) {
    String query = "SELECT * FROM users_games WHERE username='" + username + "' AND gameId='" + gameId + "'";
    try (ResultSet resultSet = newStatement().executeQuery(query)) {
      if (resultSet.next()) {
        return true;
      }

    } catch (SQLException e) {
      e.printStackTrace();
    }

    return false;
  }

  public void recordUserOnGame(String username, String gameId) {
    if (username == null) return;
    if (isUserConnected(username, gameId)) return;

    String query = "INSERT INTO users_games (username, gameId) VALUES ('" + username + "', '" + gameId + "')";
    try {
      newStatement().executeUpdate(query);

    } catch (SQLException e) {
      e.printStackTrace();
    }
  }

  public String getCurrentPlayer(String gameId) {
    String query = "SELECT username FROM game_moves WHERE id=(SELECT MAX(id) FROM game_moves WHERE gameId='" + gameId + "')";
    String lastUsername = "";
    try (ResultSet resultSet = newStatement().executeQuery(query)) {
      if (resultSet.next()) {
        lastUsername = resultSet.getString(1);
      }
    } catch (SQLException e) {
      e.printStackTrace();
    }

    query = "SELECT username FROM users_games WHERE gameId='" + gameId + "' AND username!='" + lastUsername + "'";
    try (ResultSet resultSet = newStatement().executeQuery(query)) {
      if (resultSet.next()) {
        return resultSet.getString(1);
      }

    } catch (SQLException e) {
      e.printStackTrace();
    }

    return "";
  }

  public String getFirstPlayer(String gameId) {
    String query = "SELECT username FROM users_games WHERE gameId='" + gameId + "'";
    try (ResultSet resultSet = newStatement().executeQuery(query)) {
      if (resultSet.next()) {
        return resultSet.getString(1);
      }

    } catch (SQLException e) {
      e.printStackTrace();
    }

    return "";
  }

  public String getContentOnCell(String gameId, int cell) {
    String query = "SELECT username FROM game_moves WHERE gameId='" + gameId + "' AND cell=" + cell;
    try (ResultSet resultSet = newStatement().executeQuery(query)) {
      if (resultSet.next()) {
        String username = resultSet.getString(1);
        if (username.equals(getFirstPlayer(gameId))) return "X";
        else return "O";
      }

    } catch (SQLException e) {
      e.printStackTrace();
    }

    return " ";
  }

  public void executeMove(String username, String gameId, int cell) {
    String query = "INSERT INTO game_moves (username, gameId, cell) VALUES ('" + username + "', '" + gameId + "', " + cell + ")";
    try {
      newStatement().executeUpdate(query);

    } catch (SQLException e) {
      e.printStackTrace();
    }
  }

  public boolean isGameFinished(String gameId) {
    int[][] table = new int[3][3];
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        String content = getContentOnCell(gameId, i * 3 + j);
        table[i][j] = content.equals(" ") ? 0 : content.equals("X") ? 1 : 2;
      }
    }

    for (int i = 0; i < 3; ++i) {
      boolean allSame = true;
      for (int j = 0; j < 3; ++j) {
        allSame &= (table[i][0] > 0 && table[i][0] == table[i][j]);
      }
      if (allSame) return true;
    }

    for (int i = 0; i < 3; ++i) {
      boolean allSame = true;
      for (int j = 0; j < 3; ++j) {
        allSame &= (table[0][i] > 0 && table[0][i] == table[j][i]);
      }
      if (allSame) return true;
    }

    boolean allSame = true;
    for (int i = 0; i < 3; ++i) {
      allSame &= (table[0][0] > 0 && table[0][0] == table[i][i]);
    }
    if (allSame) return true;

    allSame = true;
    for (int i = 0; i < 3; ++i) {
      allSame &= (table[0][2] > 0 && table[0][2] == table[i][2 - i]);
    }
    if (allSame) return true;

    boolean allFull = false;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        allFull |= (table[i][j] == 0);
      }
    }

    return !allFull;
  }

  public String getWinner(String gameId) {
    if (isGameFinished(gameId)) {
      String query = "SELECT username FROM game_moves WHERE gameId='" + gameId + "'";
      try (ResultSet resultSet = newStatement().executeQuery(query)) {
        resultSet.last();
        return resultSet.getString(1);

      } catch (SQLException e) {
        e.printStackTrace();
      }
    }
    return "none";
  }
}
