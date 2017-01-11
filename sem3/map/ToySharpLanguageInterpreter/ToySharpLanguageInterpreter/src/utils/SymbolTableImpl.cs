using System.Collections.Generic;
using System.Linq;

namespace ToySharpLanguageInterpreter
{
	public class SymbolTableImpl<K, V> : SymbolTable<K, V>
	{
		private Dictionary<K, V> symbolTable;

		public SymbolTableImpl()
		{
			this.symbolTable = new Dictionary<K, V>();
		}


		public void add(K key, V value)
		{
			if (symbolTable.ContainsKey(key)) symbolTable[key] = value;
			else symbolTable.Add(key, value);
		}


		public bool contains(K key)
		{
			return symbolTable.ContainsKey(key);
		}


		public V getValue(K key)
		{
			if (!contains(key)) throw (new InterpreterException("error: key \"" + key + "\" doesn't exist in symbol table"));
			return symbolTable[key];
		}


		public override string ToString()
		{
			string str = "";
			str += "SymbolTableImpl = {";

			if (symbolTable.Count() > 0) str += "\n";

			foreach (KeyValuePair<K, V> pair in symbolTable.ToList())
			{
				str += "   " + pair.Key + " <- " + pair.Value + "\n";
			}

			str += "}";
			return str;
		}


		public List<KeyValuePair<K, V>> getAll()
		{
			return symbolTable.ToList();
		}
	}
}