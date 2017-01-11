using System;
using System.Collections.Generic;
using System.Linq;

namespace ToySharpLanguageInterpreter
{
	public class FileTableImpl<K, V> : FileTable<K, V>
	{
		private IDictionary<K, V> fileTable;

		public FileTableImpl()
		{
			this.fileTable = new Dictionary<K, V>();
		}

		public void add(K key, V value)
		{
			if (fileTable.ContainsKey(key)) fileTable[key] = value;
			else fileTable.Add(key, value);
		}


		public V remove(K key)
		{
			V value = fileTable[key];
			fileTable.Remove(key);
			return value;
		}

		public bool contains(K key)
		{
			return fileTable.ContainsKey(key);
		}

		public V getValue(K key)
		{
			if (!contains(key)) throw (new InterpreterException("error: key \"" + key + "\" doesn't exist in file table"));
			return fileTable[key];
		}

		public override string ToString()
		{
			string str = "";
			str += "FileTable = {";

			if (fileTable.Count() > 0) str += "\n";

			foreach (KeyValuePair<K, V> pair in fileTable.ToList())
			{
				str += "   " + pair.Key + " <- " + pair.Value + "\n";
			}

			str += "}";
			return str;
		}


		public List<KeyValuePair<K, V>> getAll()
		{
			return fileTable.ToList();
		}
	}
}