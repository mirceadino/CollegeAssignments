package model.statements;

import model.ProgramState;
import model.expressions.Expression;
import utils.ExecutionStack;
import utils.Heap;
import utils.LockTable;
import utils.SymbolTable;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 06/12/2016.
 */
public class LockStatement implements Statement {
    private String variable;

    public LockStatement(String variable) {
        this.variable = variable;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws InterpreterException {
        SymbolTable<String, Integer> symbolTable = programState.getSymbolTable();
        LockTable<Integer, Integer> lockTable = programState.getLockTable();
        ExecutionStack<Statement> executionStack = programState.getExecutionStack();
        int address = symbolTable.getValue(variable);

        synchronized (lockTable) {
            int foundIndex = lockTable.getValue(address);

            if (foundIndex == -1) {
                lockTable.add(address, programState.getId());
            } else {
                executionStack.push(new LockStatement(variable));
            }
        }

        return null;
    }

    @Override
    public String toString() {
        return "lock(" + variable + ")";
    }
}
