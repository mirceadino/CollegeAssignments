package model.statements;

import model.ProgramState;
import utils.ExecutionStack;
import utils.ExecutionStackImpl;
import utils.SymbolTable;
import utils.SymbolTableImpl;
import utils.exceptions.InterpreterException;

import java.io.*;
import java.util.Map;

/**
 * Created by mirko on 12/12/2016.
 */
public class ForkStatement implements Statement {
    private Statement statement;

    public ForkStatement(Statement statement) {
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws InterpreterException {
        ExecutionStack<Statement> newExecutionStack = new ExecutionStackImpl<Statement>();
        newExecutionStack.push(statement);

        SymbolTable<String, Integer> newSymbolTable = new SymbolTableImpl<>();
        for (Map.Entry<String, Integer> entry : programState.getSymbolTable().getAll()) {
            newSymbolTable.add(entry.getKey(), entry.getValue());
        }

        ProgramState newProgramState = new ProgramState(
                newExecutionStack,
                newSymbolTable,
                programState.getOutput(),
                programState.getFileTable(),
                programState.getFileDescriptorGenerator(),
                programState.getHeap(),
                programState.getHeapGenerator(),
                programState.getLockTable(),
                programState.getLockGenerator());
        newProgramState.setId(programState.getId() + 1);

        return newProgramState;
    }

    @Override
    public String toString() {
        String statementToString = "";
        if (statement != null) statementToString = statement.toString();
        return "fork(" + statementToString + ")";
    }
}
