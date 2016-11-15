package model.expressions;

import utils.SymbolTable;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 12/10/2016.
 */
public interface Expression {
    int evaluate(SymbolTable<String, Integer> symTable) throws InterpreterException;

    String toString();
}
