package model.statements;

import model.ProgramState;
import model.expressions.Expression;
import utils.Heap;
import utils.SymbolTable;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 06/12/2016.
 */
public class NewStatement implements Statement {
    private String variable;
    private Expression value;

    public NewStatement(String variable, Expression value) {
        this.variable = variable;
        this.value = value;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws InterpreterException {
        Heap<Integer> heap = programState.getHeap();
        SymbolTable<String, Integer> symbolTable = programState.getSymbolTable();
        symbolTable.add(variable, heap.add(value.evaluate(symbolTable, heap)));
        return programState;
    }

    @Override
    public String toString() {
        return "new(" + variable + ", " + value + ")";
    }
}
