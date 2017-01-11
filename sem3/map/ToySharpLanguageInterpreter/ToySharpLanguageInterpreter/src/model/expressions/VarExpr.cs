using System;

namespace ToySharpLanguageInterpreter
{
	public class VarExpr : Expression
	{
		private string name;

		public VarExpr(string name)
		{
			this.name = name;
		}

		public int evaluate(SymbolTable<string, int> symTable)
		{
			return symTable.getValue(name);
		}

		public override string ToString()
		{
			return name;
		}
	}
}