import controller.Controller;
import repository.Repository;
import repository.SingleProgramStateRepository;
import view.TextMenu;
import view.commands.*;

import java.util.Scanner;

/**
 * Created by mirko on 14/11/2016.
 */
public class Interpreter {

    public static void main(String[] args) {
        TextMenu menu = new TextMenu(new Scanner(System.in));
        Repository repository = new SingleProgramStateRepository("./logs/alllogs.txt");
        Controller controller = new Controller(repository);

        menu.addCommand(new ChooseProgramCommand("1", "Choose program", controller));
        menu.addCommand(new ExecuteAllStepsCommand("2", "Execute all steps of the current program", controller));
        menu.addCommand(new SerializeProgramStatesCommand("3", "Serialize the program states to a file", controller));
        menu.addCommand(new DeserializeProgramStatesCommand("4", "Deserialize the program states from a file", controller));
        menu.addCommand(new ExitCommand("0", "Exit"));

        menu.show();
    }
}
