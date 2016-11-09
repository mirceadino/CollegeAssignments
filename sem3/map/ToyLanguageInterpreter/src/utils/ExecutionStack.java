package utils;

/**
 * Created by mirko on 12/10/2016.
 */
public interface ExecutionStack<S> {
    void push(S statement);

    S pop();

    boolean isEmpty();

    String toString();

    Iterable<S> getAll();
}
