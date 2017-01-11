using System;

namespace ToySharpLanguageInterpreter
{
	public class InterpreterException : Exception
	{
		public InterpreterException(string message) : base(message)
		{ }
	}
}