package view.commands;

import utils.exceptions.InterpreterException;

import java.util.Scanner;

/**
 * Created by mirko on 14/11/2016.
 */
public abstract class Command {
    private String key;
    private String description;

    public Command(String key, String description) {
        this.key = key;
        this.description = description;
    }

    public abstract void execute(Scanner scanner) throws InterpreterException;

    public String getKey() {
        return key;
    }

    public String getDescription() {
        return description;
    }
}
