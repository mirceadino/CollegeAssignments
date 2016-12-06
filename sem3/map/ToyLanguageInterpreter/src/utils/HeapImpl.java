package utils;

import utils.exceptions.InterpreterException;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by mirko on 06/12/2016.
 */
public class HeapImpl<K, V> implements Heap<K, V> {
    private Map<K, V> heap;

    public HeapImpl() {
        this.heap = new HashMap<K, V>();
    }

    @Override
    public void add(K key, V value) {
        heap.put(key, value);
    }

    @Override
    public V remove(K key) {
        return heap.remove(key);
    }

    @Override
    public boolean contains(K key) {
        return heap.containsKey(key);
    }

    @Override
    public V getValue(K key) throws InterpreterException {
        if (!contains(key)) throw new InterpreterException("error: key \"" + key + "\" doesn't exist in heap");
        return heap.get(key);
    }

    @Override
    public String toString() {
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
    public Iterable<Map.Entry<K, V>> getAll() {
        return heap.entrySet();
    }
}
