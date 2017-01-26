package utils;

import utils.exceptions.InterpreterException;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by mirko on 06/12/2016.
 */
public class LockTableImpl<K, V> implements LockTable<K, V> {
    private Map<K, V> heap;

    public LockTableImpl() {
        this.heap = new HashMap<K, V>();
    }

    @Override
    public synchronized void add(K key, V value) {
        heap.put(key, value);
    }

    @Override
    public synchronized V remove(K key) {
        return heap.remove(key);
    }

    @Override
    public synchronized boolean contains(K key) {
        return heap.containsKey(key);
    }

    @Override
    public synchronized V getValue(K key) throws InterpreterException {
        if (!contains(key)) throw new InterpreterException("error: key \"" + key + "\" doesn't exist in heap");
        return heap.get(key);
    }

    @Override
    public synchronized String toString() {
        StringBuilder string = new StringBuilder();
        string.append("Heap = {");

        if (!heap.isEmpty()) string.append("\n");

        for (K key : heap.keySet()) {
            string.append("   " + key + " <- " + heap.get(key) + "\n");
        }

        string.append("}");
        return string.toString();
    }

    @Override
    public synchronized Iterable<Map.Entry<K, V>> getAll() {
        return heap.entrySet();
    }

    @Override
    public synchronized void setContent(Map<K, V> content) {
        heap = new HashMap<K, V>();
        for (Map.Entry<K, V> entry : content.entrySet()) {
            heap.put(entry.getKey(), entry.getValue());
        }
    }
}
