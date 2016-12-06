package model.expressions;

import utils.Heap;
import utils.SymbolTable;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 06/12/2016.
 */
public class BooleanExpr implements Expression {
    private String operator;
    private Expression first;
    private Expression second;

    public BooleanExpr(Expression first, Expression second, String operator) {
        this.operator = operator;
        this.first = first;
        this.second = second;
    }

    @Override
    public int evaluate(SymbolTable<String, Integer> symTable, Heap<Integer, Integer> heap) throws InterpreterException {
        int firstResult = first.evaluate(symTable, heap);
        int secondResult = second.evaluate(symTable, heap);

        switch (operator) {
            case "<": {
                if (firstResult < secondResult) return 1;
                return 0;
            }
            case ">": {
                if (firstResult > secondResult) return 1;
                return 0;
            }
            case "==": {
                if (firstResult == secondResult) return 1;
                return 0;
            }
            case "!=": {
                if (firstResult != secondResult) return 1;
                return 0;
            }
            case "<=": {
                if (firstResult <= secondResult) return 1;
                return 0;
            }
            case ">=": {
                if (firstResult >= secondResult) return 1;
                return 0;
            }

            default:
                throw new InterpreterException("error: invalid operator");
        }
    }

    @Override
    public String toString() {
        return "(" + first + operator + second + ")";
    }
}
