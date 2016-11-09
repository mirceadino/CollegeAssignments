package utils;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by mirko on 12/10/2016.
 */
public class FileTableImpl<K, V> implements FileTable<K, V> {
    private Map<K, V> fileTable;

    public FileTableImpl() {
        this.fileTable = new HashMap<K, V>();
    }

    @Override
    public void add(K key, V value) {
        fileTable.put(key, value);
    }

    @Override
    public V remove(K key) {
        return fileTable.remove(key);
    }

    @Override
    public boolean contains(K key) {
        return fileTable.containsKey(key);
    }

    @Override
    public V getValue(K key) {
        if (!contains(key)) throw new RuntimeException("error: key \"" + key + "\" doesn't exist in file table");
        return fileTable.get(key);
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("FileTable = {");

        if (!fileTable.isEmpty()) string.append("\n");

        for (K key : fileTable.keySet()) {
            string.append("   " + key + " <- " + fileTable.get(key) + "\n");
        }

        string.append("}");
        return string.toString();
    }

    @Override
    public Iterable<Map.Entry<K, V>> getAll() {
        return fileTable.entrySet();
    }
}
