package controller;

import model.Authenticator;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;


public class LoginController extends HttpServlet {

  public LoginController() {
    super();
  }

  protected void doGet(HttpServletRequest request,
                       HttpServletResponse response) throws ServletException, IOException {

    RequestDispatcher requestDispatcher = request.getRequestDispatcher("/index.jsp");
    requestDispatcher.forward(request, response);
  }

  protected void doPost(HttpServletRequest request,
                        HttpServletResponse response) throws ServletException, IOException {

    String username = request.getParameter("username");
    String password = request.getParameter("password");
    RequestDispatcher requestDispatcher = null;

    Authenticator authenticator = new Authenticator();
    String result = authenticator.authenticate(username, password);

    if (result.equals("success")) {
      requestDispatcher = request.getRequestDispatcher("/success.jsp");

      HttpSession session = request.getSession();
      session.setAttribute("username", username);

    } else {
      requestDispatcher = request.getRequestDispatcher("/error.jsp");
    }

    requestDispatcher.forward(request, response);
  }

}