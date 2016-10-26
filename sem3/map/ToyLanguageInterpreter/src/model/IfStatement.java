package model;

import utils.ExecutionStack;
import utils.SymbolTable;

/**
 * Created by mirko on 18/10/2016.
 */
public class IfStatement implements Statement {
    private Expression expression;
    private Statement ifBranch;
    private Statement elseBranch;

    public IfStatement(Expression expression, Statement ifBranch, Statement elseBranch) {
        this.expression = expression;
        this.ifBranch = ifBranch;
        this.elseBranch = elseBranch;
    }

    @Override
    public ProgramState execute(ProgramState programState) {
        ExecutionStack<Statement>executionStack = programState.getExecutionStack();
        SymbolTable<String, Integer> symbolTable = programState.getSymbolTable();

        if (expression.evaluate(symbolTable) != 0) {
            executionStack.push(ifBranch);
        } else if (elseBranch != null) {
            executionStack.push(elseBranch);
        }

        return programState;
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("if(" + expression.toString() + ") then(" + ifBranch.toString() + ")");
        if (elseBranch != null) {
            string.append(" else(" + elseBranch.toString() + ")");
        }
        return string.toString();
    }
}
