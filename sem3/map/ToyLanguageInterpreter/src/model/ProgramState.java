package model;

import model.statements.Statement;
import utils.*;

import java.io.BufferedReader;
import java.io.FileDescriptor;

/**
 * Created by mirko on 12/10/2016.
 */
public class ProgramState {
    private ExecutionStack<Statement> executionStack;
    private SymbolTable<String, Integer> symbolTable;
    private FileTable<Integer, FileData<String, BufferedReader>> fileTable;
    private FileDescriptorGenerator generator;
    private Output<String> output;

    public ProgramState(ExecutionStack<Statement> executionStack,
                        SymbolTable<String, Integer> symbolTable,
                        FileTable<Integer, FileData<String, BufferedReader>> fileTable,
                        FileDescriptorGenerator generator,
                        Output<String> output) {
        this.executionStack = executionStack;
        this.symbolTable = symbolTable;
        this.fileTable = fileTable;
        this.generator = generator;
        this.output = output;
    }

    public ExecutionStack<Statement> getExecutionStack() {
        return executionStack;
    }

    public SymbolTable<String, Integer> getSymbolTable() {
        return symbolTable;
    }

    public FileTable<Integer, FileData<String, BufferedReader>> getFileTable() {
        return fileTable;
    }

    public FileDescriptorGenerator getFileDescriptorGenerator() {
        return generator;
    }

    public Output<String> getOutput() {
        return output;
    }

    @Override
    public String toString() {
        return executionStack.toString() + "\n"
                + symbolTable.toString() + "\n"
                + fileTable.toString() + "\n"
                + output.toString();
    }
}
