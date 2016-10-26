package model;

import utils.SymbolTable;

/**
 * Created by mirko on 12/10/2016.
 */
public interface Expression {
    int evaluate(SymbolTable<String, Integer> symTable);

    String toString();
}
