package view.commands;

import utils.exceptions.ExitTextMenuException;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 14/11/2016.
 */
public class ExitCommand extends Command {
    public ExitCommand(String key, String description) {
        super(key, description);
    }

    @Override
    public void execute() throws InterpreterException {
        throw new ExitTextMenuException("");
    }
}
