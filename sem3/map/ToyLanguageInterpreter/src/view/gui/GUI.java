package view.gui;

import controller.Controller;
import javafx.stage.Stage;

/**
 * Created by mirko on 03/01/2017.
 */
public class GUI {
    private MainWindow mainWindow;
    // private SelectionWindow selectionWindow;
    private Controller controller;

    public GUI(Controller controller) {
        this.mainWindow = new MainWindow();
        // this.selectionWindow = new SelectionWindow();
        this.controller = controller;
    }

    public void show(Stage primaryStage) throws Exception {
        mainWindow.show(primaryStage);
    }
}
