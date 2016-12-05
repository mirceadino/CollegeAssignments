package utils;

import utils.exceptions.InterpreterException;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by mirko on 06/12/2016.
 */
public class HeapImpl<V> implements Heap<V> {
    private Map<Integer, V> heap;
    private int nextFreeLocation;

    public HeapImpl() {
        this.heap = new HashMap<Integer, V>();
        nextFreeLocation = 1;
    }

    @Override
    public int add(V value) {
        heap.put(nextFreeLocation, value);
        ++nextFreeLocation;
        return nextFreeLocation - 1;
    }

    @Override
    public V remove(int key) {
        return heap.remove(key);
    }

    @Override
    public boolean contains(int key) {
        return heap.containsKey(key);
    }

    @Override
    public V getValue(int key) throws InterpreterException {
        if (!contains(key)) throw new InterpreterException("error: key \"" + key + "\" doesn't exist in heap");
        return heap.get(key);
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("Heap = {");

        if (!heap.isEmpty()) string.append("\n");

        for (Integer key : heap.keySet()) {
            string.append("   " + key + " <- " + heap.get(key) + "\n");
        }

        string.append("}");
        return string.toString();
    }

    @Override
    public Iterable<Map.Entry<Integer, V>> getAll() {
        return heap.entrySet();
    }
}
