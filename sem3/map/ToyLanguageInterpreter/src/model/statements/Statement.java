package model.statements;

import model.ProgramState;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 12/10/2016.
 */
public interface Statement {
    ProgramState execute(ProgramState programState) throws InterpreterException;

    String toString();
}
