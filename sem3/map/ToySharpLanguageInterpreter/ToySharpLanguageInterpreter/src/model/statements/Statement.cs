using System;

namespace ToySharpLanguageInterpreter
{
	public interface Statement
	{
		ProgramState execute(ProgramState programState);

		string ToString();
	}
}