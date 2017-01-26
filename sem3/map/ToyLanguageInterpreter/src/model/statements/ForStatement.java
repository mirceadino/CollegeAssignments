package model.statements;

import model.ProgramState;
import model.expressions.Expression;
import utils.ExecutionStack;
import utils.exceptions.InterpreterException;

/**
 * Created by mirko on 25/01/2017.
 */
public class ForStatement implements Statement {
    private Statement statement1;
    private Expression expression;
    private Statement statement2;
    private Statement body;

    public ForStatement(Statement statement1, Expression expression, Statement statement2, Statement body) {
        this.statement1 = statement1;
        this.expression = expression;
        this.statement2 = statement2;
        this.body = body;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws InterpreterException {
        ExecutionStack<Statement> executionStack = programState.getExecutionStack();

        executionStack.push(
                new CompoundStatement(
                        statement1,
                        new WhileStatement(
                                expression,
                                new CompoundStatement(body, statement2))));

        return null;
    }

    @Override
    public String toString() {
        return "for(" + statement1 + "; " + expression + "; " + statement2 + ") do(" + body + ")";
    }
}
