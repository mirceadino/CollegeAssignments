package model.statements;

import model.ProgramState;
import model.expressions.Expression;
import utils.ExecutionStack;
import utils.Heap;
import utils.SymbolTable;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 06/12/2016.
 */
public class WhileStatement implements Statement {
    private Expression expression;
    private Statement branch;

    public WhileStatement(Expression expression, Statement branch) {
        this.expression = expression;
        this.branch = branch;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws InterpreterException {
        ExecutionStack<Statement> executionStack = programState.getExecutionStack();
        SymbolTable<String, Integer> symbolTable = programState.getSymbolTable();
        Heap<Integer, Integer> heap = programState.getHeap();

        if (expression.evaluate(symbolTable, heap) != 0) {
            executionStack.push(this);
            executionStack.push(branch);
        }

        return null;
    }

    @Override
    public String toString() {
        return "while(" + expression + ") do(" + branch + ")";
    }
}
