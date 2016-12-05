package repository;

import model.ProgramState;
import model.statements.Statement;
import utils.FileData;
import utils.exceptions.InterpreterException;

import java.io.*;
import java.util.Map;

/**
 * Created by mirko on 12/10/2016.
 */
public class SingleProgramStateRepository implements Repository {
    private ProgramState programState;
    private String logFilePath;

    public SingleProgramStateRepository(String logFilePath) {
        this.logFilePath = logFilePath;
    }

    @Override
    public void add(ProgramState programState) {
        this.programState = programState;
    }

    @Override
    public ProgramState getCurrentProgramState() throws InterpreterException {
        if (programState == null) throw new InterpreterException("error: no program to execute");
        return programState;
    }

    @Override
    public void logCurrentProgramState() throws InterpreterException {
        try (PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)))) {
            logFile.append("Execution Stack\n");
            for (Statement statement : programState.getExecutionStack().getAll()) {
                logFile.append("  " + statement + "\n");
            }
            logFile.append("\n");

            logFile.append("Symbol Table\n");
            for (Map.Entry<String, Integer> entry : programState.getSymbolTable().getAll()) {
                logFile.append("  " + entry.getKey() + " --> " + entry.getValue() + "\n");
            }
            logFile.append("\n");

            logFile.append("Output\n");
            for (String output : programState.getOutput().getAll()) {
                logFile.append("  " + output + "\n");
            }
            logFile.append("-------------------\n");

            logFile.append("File Table\n");
            for (Map.Entry<Integer, FileData<String, BufferedReader>> entry : programState.getFileTable().getAll()) {
                logFile.append("  " + entry.getKey() + " --> " + entry.getValue() + "\n");
            }
            logFile.append("\n");

            logFile.append("Heap\n");
            for (Map.Entry<Integer, Integer> entry : programState.getHeap().getAll()) {
                logFile.append("  " + entry.getKey() + " --> " + entry.getValue() + "\n");
            }
            logFile.append("\n");
        } catch (IOException error) {
            throw new InterpreterException("error: could not write to the given file");
        }
    }
}
