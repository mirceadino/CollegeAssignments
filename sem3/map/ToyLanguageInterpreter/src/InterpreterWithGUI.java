/**
 * Created by mirko on 03/01/2017.
 */

import controller.Controller;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;
import repository.MultipleProgramStateRepository;
import repository.Repository;
import view.gui.MainWindowController;

import java.io.IOException;

public class InterpreterWithGUI extends Application {
    private BorderPane mainWindow;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        Repository repository = new MultipleProgramStateRepository("./logs/alllogs.txt");
        Controller controller = new Controller(repository);

        createMainWindow(primaryStage, controller);
    }

    private void createMainWindow(Stage primaryStage, Controller controller) {
        try {
            //Load root layout from fxml file.
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(InterpreterWithGUI.class.getResource("./view/gui/MainWindow.fxml"));
            mainWindow = loader.load();

            // Show the scene containing the root layout.
            MainWindowController mainWindowController = loader.getController();
            mainWindowController.setController(controller);

            Scene scene = new Scene(mainWindow);
            primaryStage.setScene(scene);
            primaryStage.show();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
