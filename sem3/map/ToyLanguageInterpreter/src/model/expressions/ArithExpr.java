package model.expressions;

import utils.Heap;
import utils.SymbolTable;
import utils.exceptions.InterpreterException;

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
    public int evaluate(SymbolTable<String, Integer> symTable, Heap<Integer, Integer> heap) throws InterpreterException {
        int firstResult = first.evaluate(symTable, heap);
        int secondResult = second.evaluate(symTable, heap);

        switch (operator) {
            case '+':
                return firstResult + secondResult;
            case '-':
                return firstResult - secondResult;
            case '*':
                return firstResult * secondResult;
            case '/': {
                if (secondResult == 0) throw new InterpreterException("error: division by zero");
                return firstResult / secondResult;
            }
            default:
                throw new InterpreterException("error: invalid operator");
        }
    }

    @Override
    public String toString() {
        return first.toString() + operator + second.toString();
    }
}
