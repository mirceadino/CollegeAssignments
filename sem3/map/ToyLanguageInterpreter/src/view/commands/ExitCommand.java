package view.commands;

import utils.exceptions.ExitTextMenuException;
import utils.exceptions.InterpreterException;

import java.util.Scanner;

/**
 * Created by mirko on 14/11/2016.
 */
public class ExitCommand extends Command {
    public ExitCommand(String key, String description) {
        super(key, description);
    }

    @Override
    public void execute(Scanner scanner) throws InterpreterException {
        throw new ExitTextMenuException("");
    }
}
