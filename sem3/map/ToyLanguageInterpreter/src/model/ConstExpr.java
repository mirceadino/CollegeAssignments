package model;

import utils.SymbolTable;

/**
 * Created by mirko on 12/10/2016.
 */
public class ConstExpr implements Expression {
    private int value;

    public ConstExpr(int value) {
        this.value = value;
    }

    @Override
    public int evaluate(SymbolTable<String, Integer> symTable) {
        return value;
    }

    @Override
    public String toString() {
        return "" + value;
    }
}
