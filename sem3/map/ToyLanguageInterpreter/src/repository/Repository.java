package repository;

import model.ProgramState;
import utils.exceptions.InterpreterException;

import java.io.Serializable;
import java.util.List;

/**
 * Created by mirko on 12/10/2016.
 */
public interface Repository extends Serializable {
    void add(ProgramState programState);

    List<ProgramState> getProgramStateList();

    void setProgramStateList(List<ProgramState> list) throws InterpreterException;

    String getLogFilePath();

    void logProgramState(ProgramState programState) throws InterpreterException;

    void serialize(String serializeFilePath) throws InterpreterException;

    void deserialize(String serializeFilePath) throws InterpreterException;
}
