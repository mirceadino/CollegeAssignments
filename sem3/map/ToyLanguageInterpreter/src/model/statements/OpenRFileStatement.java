package model.statements;

import model.ProgramState;
import utils.FileDescriptorGenerator;
import utils.FileTable;
import utils.FileData;
import utils.SymbolTable;
import utils.exceptions.InterpreterException;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;

/**
 * Created by mirko on 09/11/2016.
 */
public class OpenRFileStatement implements Statement {
    private String variable;
    private String filename;

    public OpenRFileStatement(String variable, String filename) {
        this.variable = variable;
        this.filename = filename;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws InterpreterException {
        try {
            checkIfFileNameWasNotUsedOrThrowException(programState);

            BufferedReader bufferedReader = new BufferedReader(new FileReader(filename));
            FileDescriptorGenerator generator = programState.getFileDescriptorGenerator();
            int descriptor = generator.next();

            SymbolTable<String, Integer> symbolTable = programState.getSymbolTable();
            symbolTable.add(variable, descriptor);

            FileTable<Integer, FileData<String, BufferedReader>> fileTable = programState.getFileTable();
            fileTable.add(descriptor, new FileData<>(filename, bufferedReader));

            return programState;

        } catch (IOException e) {
            throw new InterpreterException("error: file could not be open");
        }
    }

    @Override
    public String toString() {
        return "openRFile(" + variable + ", \"" + filename + "\")";
    }

    private void checkIfFileNameWasNotUsedOrThrowException(ProgramState programState) throws InterpreterException {
        FileTable<Integer, FileData<String, BufferedReader>> fileTable = programState.getFileTable();

        for (Map.Entry<Integer, FileData<String, BufferedReader>> entry : fileTable.getAll()) {
            if (entry.getValue().getKey() == filename) {
                throw new InterpreterException("error: a file with that name was already open");
            }
        }
    }
}
