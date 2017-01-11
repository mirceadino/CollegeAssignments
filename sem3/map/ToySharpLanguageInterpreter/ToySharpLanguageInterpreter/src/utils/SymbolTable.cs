using System.Collections.Generic;

namespace ToySharpLanguageInterpreter
{
	public interface SymbolTable<K, V>
	{
		void add(K key, V value);

		bool contains(K key);

		V getValue(K key);

		string ToString();

		List<KeyValuePair<K, V>> getAll();
	}
}