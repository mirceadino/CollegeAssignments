using System;

namespace ToySharpLanguageInterpreter
{
	public interface Expression
	{
		int evaluate(SymbolTable<string, int> symTable);

		string ToString();
	}
}