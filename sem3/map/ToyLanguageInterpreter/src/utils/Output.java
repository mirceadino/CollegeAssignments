package utils;

import java.io.Serializable;

/**
 * Created by mirko on 12/10/2016.
 */
public interface Output<S> extends Serializable {
    void add(S output);

    String toString();

    Iterable<S> getAll();
}

