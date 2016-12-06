package model.expressions;

import model.ProgramState;
import utils.Heap;
import utils.SymbolTable;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 06/12/2016.
 */
public class ReadHeapExpression implements Expression {
    private String variable;

    public ReadHeapExpression(String variable) {
        this.variable = variable;
    }

    @Override
    public int evaluate(SymbolTable<String, Integer> symTable, Heap<Integer, Integer> heap) throws InterpreterException {
        return heap.getValue(symTable.getValue(variable));
    }

    @Override
    public String toString() {
        return "readHeap(" + variable + ")";
    }
}
