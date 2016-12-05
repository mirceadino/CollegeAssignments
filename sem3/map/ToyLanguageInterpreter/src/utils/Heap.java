package utils;

import utils.exceptions.InterpreterException;

import java.util.Map;

/**
 * Created by mirko on 06/12/2016.
 */
public interface Heap<V> {
    int add(V value);

    V remove(int key);

    boolean contains(int key);

    V getValue(int key) throws InterpreterException;

    String toString();

    Iterable<Map.Entry<Integer, V>> getAll();
}
