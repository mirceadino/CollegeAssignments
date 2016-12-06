package view.commands;

import controller.Controller;
import model.statements.Statement;
import repository.Repository;
import repository.SingleProgramStateRepository;
import utils.exceptions.ExitTextMenuException;
import utils.exceptions.InterpreterException;

import java.util.Scanner;

/**
 * Created by mirko on 15/11/2016.
 */
public class ChooseExampleCommand extends Command {
    private Controller controller;
    private Statement statement;
    private String logfile;

    public ChooseExampleCommand(String key, String description, Controller controller,
                                Statement statement, String logfile) {
        super(key, description);
        this.controller = controller;
        this.statement = statement;
        this.logfile = logfile;
    }

    @Override
    public void execute(Scanner scanner) throws InterpreterException {
        Repository repository = new SingleProgramStateRepository(logfile);
        controller.setRepository(repository);
        controller.addProgram(statement);
        throw new ExitTextMenuException("Program was chosen.");
    }
}
