package utils;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

/**
 * Created by mirko on 12/10/2016.
 */
public class ExecutionStackImpl<S> implements ExecutionStack<S> {
    private Deque<S> stack;

    public ExecutionStackImpl() {
        stack = new ArrayDeque<S>();
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

        for (S statement : stack) {
            string.append("   " + statement.toString() + "\n");
        }

        string.append("}");
        return string.toString();
    }

    @Override
    public Iterable<S> getAll() {
        return stack;
    }
}
