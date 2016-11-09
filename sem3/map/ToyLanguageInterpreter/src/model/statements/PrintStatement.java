package model.statements;

import model.ProgramState;
import model.expressions.Expression;
import utils.Output;
import utils.SymbolTable;

/**
 * Created by mirko on 12/10/2016.
 */
public class PrintStatement implements Statement {
    private Expression expression;

    public PrintStatement(Expression expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState programState) {
        SymbolTable<String, Integer> symbolTable = programState.getSymbolTable();
        Output<String> output = programState.getOutput();
        output.add("" + expression.evaluate(symbolTable));
        return programState;
    }

    @Override
    public String toString() {
        return "print(" + expression.toString() + ")";
    }
}
