/**
 * Created by mirko on 03/01/2017.
 */

import controller.Controller;
import javafx.application.Application;
import javafx.stage.Stage;
import repository.Repository;
import repository.SingleProgramStateRepository;
import view.gui.GUI;

public class InterpreterWithGUI extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        Repository repository = new SingleProgramStateRepository("./logs/alllogs.txt");
        Controller controller = new Controller(repository);
        GUI gui = new GUI(controller);

        gui.show(primaryStage);
    }

}
