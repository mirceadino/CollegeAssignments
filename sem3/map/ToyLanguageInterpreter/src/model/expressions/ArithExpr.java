package model.expressions;

import utils.SymbolTable;

/**
 * Created by mirko on 12/10/2016.
 */
public class ArithExpr implements Expression {
    private char operator;
    private Expression first;
    private Expression second;

    public ArithExpr(Expression first, Expression second, char operator) {
        this.operator = operator;
        this.first = first;
        this.second = second;
    }

    @Override
    public int evaluate(SymbolTable<String, Integer> symTable) {
        int firstResult = first.evaluate(symTable);
        int secondResult = second.evaluate(symTable);

        switch (operator) {
            case '+':
                return firstResult + secondResult;
            case '-':
                return firstResult - secondResult;
            case '*':
                return firstResult * secondResult;
            case '/': {
                if (secondResult == 0) throw new RuntimeException("error: division by zero");
                return firstResult / secondResult;
            }
            default:
                throw new RuntimeException("error: invalid operator");
        }
    }

    @Override
    public String toString() {
        return first.toString() + operator + second.toString();
    }
}
