package model;

import model.statements.Statement;
import utils.*;

import java.io.BufferedReader;

/**
 * Created by mirko on 12/10/2016.
 */
public class ProgramState {
    private ExecutionStack<Statement> executionStack;
    private SymbolTable<String, Integer> symbolTable;
    private Output<String> output;
    private FileTable<Integer, FileData<String, BufferedReader>> fileTable;
    private FileDescriptorGenerator generator;
    private Heap<Integer> heap;

    public ProgramState(ExecutionStack<Statement> executionStack,
                        SymbolTable<String, Integer> symbolTable,
                        Output<String> output, FileTable<Integer, FileData<String, BufferedReader>> fileTable,
                        FileDescriptorGenerator generator, Heap<Integer> heap) {
        this.executionStack = executionStack;
        this.symbolTable = symbolTable;
        this.output = output;
        this.fileTable = fileTable;
        this.generator = generator;
        this.heap = heap;
    }

    public ExecutionStack<Statement> getExecutionStack() {
        return executionStack;
    }

    public SymbolTable<String, Integer> getSymbolTable() {
        return symbolTable;
    }

    public Output<String> getOutput() {
        return output;
    }

    public FileTable<Integer, FileData<String, BufferedReader>> getFileTable() {
        return fileTable;
    }

    public FileDescriptorGenerator getFileDescriptorGenerator() {
        return generator;
    }

    public Heap<Integer> getHeap() {
        return heap;
    }

    @Override
    public String toString() {
        return executionStack.toString() + "\n"
                + symbolTable.toString() + "\n"
                + output.toString() + "\n"
                + fileTable.toString() + "\n"
                + heap.toString();
    }
}
