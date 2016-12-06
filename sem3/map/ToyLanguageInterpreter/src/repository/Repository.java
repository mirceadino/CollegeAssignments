package repository;

import model.ProgramState;
import utils.exceptions.InterpreterException;

import java.io.Serializable;

/**
 * Created by mirko on 12/10/2016.
 */
public interface Repository extends Serializable {
    void add(ProgramState programState);

    ProgramState getCurrentProgramState() throws InterpreterException;

    String getLogFilePath();

    void logCurrentProgramState() throws InterpreterException;

    void serialize(String serializeFilePath) throws InterpreterException;

    void deserialize(String serializeFilePath) throws InterpreterException;
}
