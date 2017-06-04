package controller;

import model.StateRecorder;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.UUID;


public class GameController extends HttpServlet {

  StateRecorder stateRecorder;
  String gameId;

  public GameController() {
    super();
    stateRecorder = new StateRecorder();
  }

  private String generateNewGameId() {
    String gameId = UUID.randomUUID().toString();
    return gameId;
  }

  private String buildTable(String username, String gameId) {
    StringBuilder table = new StringBuilder();
    table.append("<table>");
    for (int i = 0; i < 3; ++i) {
      table.append("<tr>");

      for (int j = 0; j < 3; ++j) {
        table.append("<td>");

        String disabled = "";
        String buttonValue = stateRecorder.getContentOnCell(gameId, i * 3 + j);
        if (!buttonValue.equals(" ") || !stateRecorder.getCurrentPlayer(gameId).equals(username)) disabled = "disabled";

        table.append("<form action=\"game\" method=\"post\">");
        table.append("<input name=\"cell\" type=\"hidden\" value=\"" + (i * 3 + j) + "\"/>");
        table.append("<input type=\"submit\" value=\"" + buttonValue + "\" " + disabled + "/>");
        table.append("</form>");

        table.append("</td>");
      }

      table.append("</tr>");
    }

    return table.toString();
  }

  protected void doGet(HttpServletRequest request,
                       HttpServletResponse response) throws ServletException, IOException {

    HttpSession session = request.getSession();
    String username = (String) session.getAttribute("username");

    if (gameId == null) {
      gameId = generateNewGameId();
    }

    String path = "/error.jsp";
    if (stateRecorder.getNumPlayersPerGame(gameId) < 2 || stateRecorder.isUserConnected(username, gameId)) {
      path = "/game.jsp";
      stateRecorder.recordUserOnGame(username, gameId);

      if (!stateRecorder.isGameFinished(gameId)) {
        session.setAttribute("table", buildTable(username, gameId));

      } else {
        String winner = stateRecorder.getWinner(gameId);
        path = "/finish.jsp";

        String message = "Game over! Winner: <b>" + winner + "</b>";
        message += "<br>";
        message += "<a href=\"login\">Play again.</a> ";
        session.setAttribute("message", message);

        gameId = null;
      }
    }

    RequestDispatcher requestDispatcher = request.getRequestDispatcher(path);
    requestDispatcher.forward(request, response);
  }

  protected void doPost(HttpServletRequest request,
                        HttpServletResponse response) throws ServletException, IOException {

    int cell = Integer.parseInt(request.getParameter("cell"));
    stateRecorder.executeMove(stateRecorder.getCurrentPlayer(gameId), gameId, cell);

    RequestDispatcher requestDispatcher = request.getRequestDispatcher("/game.jsp");
    requestDispatcher.forward(request, response);
  }

}