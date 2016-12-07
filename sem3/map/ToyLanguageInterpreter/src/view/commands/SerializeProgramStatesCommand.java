package view.commands;

import controller.Controller;
import utils.exceptions.InterpreterException;

import java.util.Scanner;

/**
 * Created by mirko on 06/12/2016.
 */
public class SerializeProgramStatesCommand extends Command {
    private Controller controller;

    public SerializeProgramStatesCommand(String key, String description, Controller controller) {
        super(key, description);
        this.controller = controller;
    }

    @Override
    public void execute(Scanner scanner) throws InterpreterException {
        System.out.print("Type the path of the file: ");
        String serializeFilePath = scanner.nextLine();
        controller.serializeRepository(serializeFilePath);
    }
}
