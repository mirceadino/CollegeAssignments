package model.statements;

import model.ProgramState;
import model.expressions.Expression;
import utils.Heap;
import utils.Output;
import utils.SymbolTable;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 12/10/2016.
 */
public class PrintStatement implements Statement {
    private Expression expression;

    public PrintStatement(Expression expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws InterpreterException {
        SymbolTable<String, Integer> symbolTable = programState.getSymbolTable();
        Heap<Integer, Integer> heap = programState.getHeap();
        Output<String> output = programState.getOutput();
        output.add("" + expression.evaluate(symbolTable, heap));
        return programState;
    }

    @Override
    public String toString() {
        return "print(" + expression.toString() + ")";
    }
}
