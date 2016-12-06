package model.expressions;

import utils.Heap;
import utils.SymbolTable;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 12/10/2016.
 */
public interface Expression {
    int evaluate(SymbolTable<String, Integer> symTable, Heap<Integer, Integer> heap) throws InterpreterException;

    String toString();
}
