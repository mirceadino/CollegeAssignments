using System;
using System.Collections.Generic;

namespace ToySharpLanguageInterpreter
{
	public interface FileTable<K, V>
	{
		void add(K key, V value);

		V remove(K key);

		bool contains(K key);

		V getValue(K key);

		string ToString();

		List<KeyValuePair<K, V>> getAll();
	}
}