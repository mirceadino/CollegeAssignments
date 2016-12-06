package utils;

import java.io.Serializable;

/**
 * Created by mirko on 12/10/2016.
 */
public interface ExecutionStack<S> extends Serializable {
    void push(S statement);

    S pop();

    boolean isEmpty();

    String toString();

    Iterable<S> getAll();
}
