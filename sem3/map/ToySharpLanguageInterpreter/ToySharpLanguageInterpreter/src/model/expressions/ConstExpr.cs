using System;

namespace ToySharpLanguageInterpreter
{
	public class ConstExpr : Expression
	{
		private int value;

		public ConstExpr(int value)
		{
			this.value = value;
		}

		public int evaluate(SymbolTable<string, int> symTable)
		{
			return value;
		}

		public override string ToString()
		{
			return "" + value;
		}
	}
}