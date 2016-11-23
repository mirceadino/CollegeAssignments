import controller.Controller;
import repository.Repository;
import repository.SingleProgramStateRepository;
import view.TextMenu;
import view.commands.ChooseProgramCommand;
import view.commands.ExecuteAllStepsCommand;
import view.commands.ExecuteOneStepCommand;
import view.commands.ExitCommand;

/**
 * Created by mirko on 14/11/2016.
 */
public class Interpreter {

    public static void main(String[] args) {
        TextMenu menu = new TextMenu();
        Repository repository = new SingleProgramStateRepository("./logs/alllogs.txt");
        Controller controller = new Controller(repository);

        menu.addCommand(new ChooseProgramCommand("1", "Choose program", controller));
        menu.addCommand(new ExecuteOneStepCommand("2", "Execute one step of the current program", controller));
        menu.addCommand(new ExecuteAllStepsCommand("3", "Execute all steps of the current program", controller));
        menu.addCommand(new ExitCommand("0", "Exit"));

        menu.show();
    }
}
