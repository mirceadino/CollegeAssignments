package model.statements;

import model.ProgramState;
import utils.ExecutionStack;
import utils.LockTable;
import utils.SymbolTable;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 06/12/2016.
 */
public class UnlockStatement implements Statement {
    private String variable;

    public UnlockStatement(String variable) {
        this.variable = variable;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws InterpreterException {
        SymbolTable<String, Integer> symbolTable = programState.getSymbolTable();
        LockTable<Integer, Integer> lockTable = programState.getLockTable();
        int address = symbolTable.getValue(variable);

        int foundIndex = -1;
        try {
            foundIndex = lockTable.getValue(address);
        } catch (InterpreterException err) {
        }

        if (foundIndex != -1) {
            lockTable.add(address, -1);
        }

        return null;
    }

    @Override
    public String toString() {
        return "unlock(" + variable + ")";
    }
}
