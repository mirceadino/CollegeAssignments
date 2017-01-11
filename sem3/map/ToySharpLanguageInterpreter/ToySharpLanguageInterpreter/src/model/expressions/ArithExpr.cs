using System;

namespace ToySharpLanguageInterpreter
{
	public class ArithExpr : Expression
	{
		private char op;
		private Expression first;
		private Expression second;

		public ArithExpr(Expression first, Expression second, char op)
		{
			this.op = op;
			this.first = first;
			this.second = second;
		}

		public int evaluate(SymbolTable<string, int> symTable)
		{
			int firstResult = first.evaluate(symTable);
			int secondResult = second.evaluate(symTable);

			switch (op)
			{
				case '+':
					return firstResult + secondResult;
				case '-':
					return firstResult - secondResult;
				case '*':
					return firstResult * secondResult;
				case '/':
					{
						if (secondResult == 0) throw (new InterpreterException("error: division by zero"));
						return firstResult / secondResult;
					}
				default:
					throw (new InterpreterException("error: invalid op"));
			}
		}

		public override string ToString()
		{
			return first.ToString() + op + second.ToString();
		}
	}
}