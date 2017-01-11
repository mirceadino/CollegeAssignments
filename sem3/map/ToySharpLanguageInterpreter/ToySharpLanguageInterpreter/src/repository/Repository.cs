using System.Collections.Generic;

namespace ToySharpLanguageInterpreter
{
	public interface Repository
	{
		void add(ProgramState programState);

		ProgramState getCurrentProgramState();

		void logCurrentProgramState();
	}
}