package repository;

import model.ProgramState;
import model.Statement;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
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
    public ProgramState getCurrentProgramState() {
        if (programState == null) throw new RuntimeException("error: no program to execute");
        return programState;
    }

    @Override
    public void logCurrentProgramState() {
        try (PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)))) {
            logFile.append("Execution Stack\n");
            for (Statement statement : programState.getExecutionStack().getAll()) {
                logFile.append(statement + "\n");
            }
            logFile.append("\n");

            logFile.append("Symbol Table\n");
            for (Map.Entry<String, Integer> entry : programState.getSymbolTable().getAll()) {
                logFile.append(entry.getKey() + " --> " + entry.getValue() + "\n");
            }
            logFile.append("\n");

            logFile.append("Output\n");
            for (String output : programState.getOutput().getAll()) {
                logFile.append(output + "\n");
            }
            logFile.append("\n");
        } catch (IOException error) {
            throw new RuntimeException("error: could not write to the given file");
        }
    }
}
