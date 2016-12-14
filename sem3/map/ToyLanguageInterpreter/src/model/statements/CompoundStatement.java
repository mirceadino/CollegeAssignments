package model.statements;

import model.ProgramState;
import utils.ExecutionStack;

/**
 * Created by mirko on 12/10/2016.
 */
public class CompoundStatement implements Statement {
    private Statement first;
    private Statement second;

    public CompoundStatement(Statement first, Statement second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public ProgramState execute(ProgramState programState) {
        ExecutionStack<Statement> executionStack = programState.getExecutionStack();
        executionStack.push(second);
        executionStack.push(first);
        return null;
    }

    @Override
    public String toString() {
        return first.toString() + "; " + second.toString();
    }
}
