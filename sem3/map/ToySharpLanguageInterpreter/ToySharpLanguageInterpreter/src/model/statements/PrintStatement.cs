using System;

namespace ToySharpLanguageInterpreter
{
	public class PrintStatement : Statement
	{
		private Expression expression;

		public PrintStatement(Expression expression)
		{
			this.expression = expression;
		}


		public ProgramState execute(ProgramState programState)
		{
			SymbolTable<string, int> symbolTable = programState.getSymbolTable();
			Output<string> output = programState.getOutput();
			output.add("" + expression.evaluate(symbolTable));
			return programState;
		}


		public override string ToString()
		{
			return "print(" + expression.ToString() + ")";
		}
	}
}