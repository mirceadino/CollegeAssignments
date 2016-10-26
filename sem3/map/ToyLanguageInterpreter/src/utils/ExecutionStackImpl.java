package utils;

import java.util.Stack;

/**
 * Created by mirko on 12/10/2016.
 */
public class ExecutionStackImpl<S> implements ExecutionStack<S> {
    private Stack<S> stack;

    public ExecutionStackImpl() {
        stack = new Stack<S>();
    }

    @Override
    public void push(S statement) {
        stack.push(statement);
    }

    @Override
    public S pop() {
        if (isEmpty()) return null;
        return stack.pop();
    }

    @Override
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("ExecutionStackImpl = {");

        if (!stack.isEmpty()) {
            string.append("\n");
        }

        Stack<S> reversed_stack = new Stack<S>();

        while (!stack.empty()) {
            S statement = stack.pop();
            reversed_stack.push(statement);
            string.append("   " + statement.toString() + "\n");
        }

        while (!reversed_stack.empty()) {
            S statement = reversed_stack.pop();
            stack.push(statement);
        }

        string.append("}");
        return string.toString();
    }
}
