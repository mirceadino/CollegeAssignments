using System;

namespace ToySharpLanguageInterpreter
{
	public class CompoundStatement : Statement
	{
		private Statement first;
		private Statement second;

		public CompoundStatement(Statement first, Statement second)
		{
			this.first = first;
			this.second = second;
		}


		public ProgramState execute(ProgramState programState)
		{
			ExecutionStack<Statement> executionStack = programState.getExecutionStack();
			executionStack.push(second);
			executionStack.push(first);
			return programState;
		}


		public override string ToString()
		{
			return first.ToString() + "; " + second.ToString();
		}
	}
}