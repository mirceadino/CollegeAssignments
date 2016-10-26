package utils;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by mirko on 12/10/2016.
 */
public class SymbolTableTest {
    @Test
    public void basicTest() throws Exception {
        SymbolTable<String, Integer> symTable = new SymbolTableImpl<>();
        symTable.add("a", 0);
        symTable.add("b", 1);
        symTable.add("mlc", 2);
        assertTrue(symTable.contains("a"));
        assertTrue(symTable.contains("b"));
        assertFalse(symTable.contains("c"));
        assertTrue(symTable.contains("mlc"));
        assertEquals(symTable.getValue("a"), new Integer(0));
        assertEquals(symTable.getValue("b"), new Integer(1));
        assertEquals(symTable.getValue("mlc"), new Integer(2));
        symTable.add("a", 2);
        symTable.add("b", 1);
        symTable.add("c", 3);
        assertTrue(symTable.contains("c"));
        assertEquals(symTable.getValue("a"), new Integer(2));
        assertEquals(symTable.getValue("b"), new Integer(1));
        assertEquals(symTable.getValue("c"), new Integer(3));
    }
}