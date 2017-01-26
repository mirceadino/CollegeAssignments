package model.statements;

import model.ProgramState;
import model.expressions.Expression;
import utils.Heap;
import utils.LockTable;
import utils.SymbolTable;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 06/12/2016.
 */
public class NewLockStatement implements Statement {
    private String variable;

    public NewLockStatement(String variable) {
        this.variable = variable;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws InterpreterException {
        LockTable<Integer, Integer> lockTable = programState.getLockTable();
        SymbolTable<String, Integer> symbolTable = programState.getSymbolTable();
        Integer address = new Integer(programState.getLockGenerator().next());
        lockTable.add(address, -1);
        symbolTable.add(variable, address);
        return null;
    }

    @Override
    public String toString() {
        return "newLock(" + variable + ")";
    }
}
