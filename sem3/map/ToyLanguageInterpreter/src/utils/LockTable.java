package utils;

import utils.exceptions.InterpreterException;

import java.io.Serializable;
import java.util.Map;

/**
 * Created by mirko on 06/12/2016.
 */
public interface LockTable<K, V> extends Serializable {
    void add(K key, V value);

    V remove(K key);

    boolean contains(K key);

    V getValue(K key) throws InterpreterException;

    String toString();

    Iterable<Map.Entry<K, V>> getAll();

    void setContent(Map<K, V> content);
}
