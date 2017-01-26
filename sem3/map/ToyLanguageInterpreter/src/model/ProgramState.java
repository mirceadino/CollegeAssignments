package model;

import model.statements.Statement;
import utils.*;
import utils.exceptions.InterpreterException;

import java.io.BufferedReader;
import java.io.Serializable;

/**
 * Created by mirko on 12/10/2016.
 */
public class ProgramState implements Serializable {
    private int id;
    private ExecutionStack<Statement> executionStack;
    private SymbolTable<String, Integer> symbolTable;
    private Output<String> output;
    private FileTable<Integer, FileData<String, BufferedReader>> fileTable;
    private NumberGenerator fileDescriptorGenerator;
    private Heap<Integer, Integer> heap;
    private NumberGenerator heapAddressGenerator;
    private LockTable<Integer, Integer> lockTable;
    private NumberGenerator lockAddressGenerator;

    public ProgramState(ExecutionStack<Statement> executionStack,
                        SymbolTable<String, Integer> symbolTable,
                        Output<String> output, FileTable<Integer, FileData<String, BufferedReader>> fileTable,
                        NumberGenerator fileDescriptorGenerator, Heap<Integer, Integer> heap,
                        NumberGenerator heapAddressGenerator,
                        LockTable<Integer, Integer> lockTable,
                        NumberGenerator lockAddressGenerator) {
        this.executionStack = executionStack;
        this.symbolTable = symbolTable;
        this.output = output;
        this.fileTable = fileTable;
        this.fileDescriptorGenerator = fileDescriptorGenerator;
        this.heap = heap;
        this.heapAddressGenerator = heapAddressGenerator;
        this.lockTable = lockTable;
        this.lockAddressGenerator = lockAddressGenerator;
    }

    public boolean isCompleted() {
        return executionStack.isEmpty();
    }

    public boolean isNotCompleted() {
        return !isCompleted();
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
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

    public NumberGenerator getFileDescriptorGenerator() {
        return fileDescriptorGenerator;
    }

    public Heap<Integer, Integer> getHeap() {
        return heap;
    }

    public NumberGenerator getHeapGenerator() {
        return heapAddressGenerator;
    }

    public LockTable<Integer, Integer> getLockTable() {
        return lockTable;
    }

    public NumberGenerator getLockGenerator() {
        return lockAddressGenerator;
    }

    public ProgramState executeOneStep() throws InterpreterException {
        if (isCompleted())
            throw new InterpreterException("error: program's execution is completed");

        Statement statement = executionStack.pop();
        return statement.execute(this);
    }

    @Override
    public String toString() {
        return "Program #" + id + "\n"
                + executionStack.toString() + "\n"
                + symbolTable.toString() + "\n"
                + output.toString() + "\n"
                + fileTable.toString() + "\n"
                + heap.toString();
    }
}
