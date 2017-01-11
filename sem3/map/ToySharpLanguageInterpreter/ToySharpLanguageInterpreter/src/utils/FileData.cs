using System;

namespace ToySharpLanguageInterpreter
{
	public class FileData<K, V> : Tuple<K, V>
	{
		public FileData(K key, V value) : base(key, value)
		{ }
	}
}
