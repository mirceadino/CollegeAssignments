package repository;

import model.ProgramState;
import model.statements.Statement;
import utils.FileData;
import utils.exceptions.InterpreterException;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * Created by mirko on 14/12/2016.
 */
public class MultipleProgramStateRepository implements Repository {
    private List<ProgramState> list;
    private String logFilePath;

    public MultipleProgramStateRepository(String logFilePath) {
        this.logFilePath = logFilePath;
        this.list = new ArrayList<ProgramState>();
    }

    @Override
    public void add(ProgramState programState) {
        list.add(programState);
    }

    @Override
    public List<ProgramState> getProgramStateList() {
        return list;
    }

    @Override
    public void setProgramStateList(List<ProgramState> list) throws InterpreterException {
        this.list = list;
    }

    @Override
    public String getLogFilePath() {
        return logFilePath;
    }

    @Override
    public void logProgramState(ProgramState programState) throws InterpreterException {
        try (PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)))) {
            logFile.append("Program #" + programState.getId() + "\n");
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
            logFile.append("\n");

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

            logFile.append("-------------------\n");
        } catch (IOException error) {
            throw new InterpreterException("error: could not write to the given file");
        }
    }

    @Override
    public void serialize(String serializeFilePath) throws InterpreterException {
        try (ObjectOutputStream serializeFile = new ObjectOutputStream(new FileOutputStream(serializeFilePath))) {
            serializeFile.writeObject(this);
        } catch (IOException e) {
            throw new InterpreterException("error: could not serialize to the given file");
        }
    }

    @Override
    public void deserialize(String serializeFilePath) throws InterpreterException {
        try (ObjectInputStream serializeFile = new ObjectInputStream(new FileInputStream(serializeFilePath))) {
            MultipleProgramStateRepository deserializedRepository =
                    (MultipleProgramStateRepository) serializeFile.readObject();
            this.list = deserializedRepository.list;
            this.logFilePath = deserializedRepository.logFilePath;
        } catch (IOException e) {
            throw new InterpreterException("error: could not deserialize from the given file");
        } catch (ClassNotFoundException e) {
            throw new InterpreterException("error: could not deserialize from the given file due to class not found");
        }
    }

}
