using System;

namespace ToySharpLanguageInterpreter
{
	public class ExitTextMenuException : InterpreterException
	{
		public ExitTextMenuException(string message) : base(message)
		{ }
	}
}