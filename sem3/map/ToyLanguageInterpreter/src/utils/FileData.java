package utils;

import java.util.AbstractMap;

/**
 * Created by mirko on 09/11/2016.
 */
public class FileData<K, V> extends AbstractMap.SimpleEntry<K, V> {
    public FileData(K key, V value) {
        super(key, value);
    }
}
