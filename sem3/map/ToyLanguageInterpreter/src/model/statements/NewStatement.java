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
        Heap<Integer, Integer> heap = programState.getHeap();
        SymbolTable<String, Integer> symbolTable = programState.getSymbolTable();
        Integer address = new Integer(programState.getHeapGenerator().next());
        heap.add(address, value.evaluate(symbolTable, heap));
        symbolTable.add(variable, address);
        return null;
    }

    @Override
    public String toString() {
        return "new(" + variable + ", " + value + ")";
    }
}
