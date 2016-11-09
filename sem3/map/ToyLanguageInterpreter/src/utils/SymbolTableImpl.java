package utils;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by mirko on 12/10/2016.
 */
public class SymbolTableImpl<K, V> implements SymbolTable<K, V> {
    private Map<K, V> symbolTable;

    public SymbolTableImpl() {
        this.symbolTable = new HashMap<K, V>();
    }

    @Override
    public void add(K key, V value) {
        symbolTable.put(key, value);
    }

    @Override
    public boolean contains(K key) {
        return symbolTable.containsKey(key);
    }

    @Override
    public V getValue(K key) {
        if (!contains(key)) throw new RuntimeException("error: key \"" + key + "\" doesn't exist in symbol table");
        return symbolTable.get(key);
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("SymbolTableImpl = {");

        if (!symbolTable.isEmpty()) string.append("\n");

        for (K key : symbolTable.keySet()) {
            string.append("   " + key + " <- " + symbolTable.get(key) + "\n");
        }

        string.append("}");
        return string.toString();
    }

    @Override
    public Iterable<Map.Entry<K, V>> getAll() {
        return symbolTable.entrySet();
    }
}
