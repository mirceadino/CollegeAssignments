package model;

import utils.ExecutionStack;
import utils.Output;
import utils.SymbolTable;

/**
 * Created by mirko on 12/10/2016.
 */
public class ProgramState {
    private ExecutionStack<Statement> executionStack;
    private SymbolTable<String, Integer> symbolTable;
    private Output<String> output;

    public ProgramState(ExecutionStack<Statement> executionStack, SymbolTable<String, Integer> symbolTable,
                        Output<String> output) {
        this.executionStack = executionStack;
        this.symbolTable = symbolTable;
        this.output = output;
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

    @Override
    public String toString() {
        return executionStack.toString() + "\n" + symbolTable.toString() + "\n" + output.toString();
    }
}
