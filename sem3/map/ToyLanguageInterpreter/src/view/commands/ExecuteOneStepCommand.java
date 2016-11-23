package view.commands;

import controller.Controller;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 14/11/2016.
 */
public class ExecuteOneStepCommand extends Command {
    private Controller controller;

    public ExecuteOneStepCommand(String key, String description, Controller controller) {
        super(key, description);
        this.controller = controller;
    }

    @Override
    public void execute() {
        try {
            controller.executeOneStep(controller.getCurrentProgram());
            System.out.println(controller.currentProgramToString());
            System.out.flush();
        } catch (InterpreterException error) {
            System.out.println(error.toString());
            System.out.flush();
        }
    }
}
