package model.statements;

import model.ProgramState;
import utils.exceptions.InterpreterException;

import java.io.Serializable;

/**
 * Created by mirko on 12/10/2016.
 */
public interface Statement extends Serializable {
    ProgramState execute(ProgramState programState) throws InterpreterException;

    String toString();
}
