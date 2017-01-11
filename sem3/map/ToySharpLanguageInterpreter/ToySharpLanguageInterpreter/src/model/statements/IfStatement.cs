using System;

namespace ToySharpLanguageInterpreter
{
	public class IfStatement : Statement
	{
		private Expression expression;
		private Statement ifBranch;
		private Statement elseBranch;

		public IfStatement(Expression expression, Statement ifBranch, Statement elseBranch)
		{
			this.expression = expression;
			this.ifBranch = ifBranch;
			this.elseBranch = elseBranch;
		}


		public ProgramState execute(ProgramState programState)
		{
			ExecutionStack<Statement> executionStack = programState.getExecutionStack();
			SymbolTable<string, int> symbolTable = programState.getSymbolTable();

			if (expression.evaluate(symbolTable) != 0)
			{
				executionStack.push(ifBranch);
			}
			else if (elseBranch != null)
			{
				executionStack.push(elseBranch);
			}

			return programState;
		}


		public override string ToString()
		{
			string str = "";
			str += "if(" + expression.ToString() + ") then(" + ifBranch.ToString() + ")";
			if (elseBranch != null)
			{
				str += " else(" + elseBranch.ToString() + ")";
			}
			return str;
		}
	}
}