using System.Collections.Generic;
using System.IO;

namespace ToySharpLanguageInterpreter
{
	public class SingleProgramStateRepository : Repository
	{
		private ProgramState programState;
		private string logFilePath;

		public SingleProgramStateRepository(string logFilePath)
		{
			this.logFilePath = logFilePath;
		}


		public void add(ProgramState programState)
		{
			this.programState = programState;
		}


		public ProgramState getCurrentProgramState()
		{
			if (programState == null) throw (new InterpreterException("error: no program to execute"));
			return programState;
		}


		public void logCurrentProgramState()
		{
			using (StreamWriter logFile = new StreamWriter(logFilePath, true))
			{
				try
				{
					logFile.WriteLine("Execution Stack\n");
					foreach (Statement statement in programState.getExecutionStack().getAll())
					{
						logFile.WriteLine("  " + statement + "\n");
					}
					logFile.WriteLine("\n");

					logFile.WriteLine("Symbol Table\n");
					foreach (KeyValuePair<string, int> entry in programState.getSymbolTable().getAll())
					{
						logFile.WriteLine("  " + entry.Key + " --> " + entry.Value + "\n");
					}
					logFile.WriteLine("\n");

					logFile.WriteLine("File Table\n");
					foreach (KeyValuePair<int, FileData<string, StreamReader>> entry in programState.getFileTable().getAll())
					{
						logFile.WriteLine("  " + entry.Key + " --> " + entry.Value + "\n");
					}
					logFile.WriteLine("\n");

					logFile.WriteLine("Output\n");
					foreach (string output in programState.getOutput().getAll())
					{
						logFile.WriteLine("  " + output + "\n");
					}
					logFile.WriteLine("-------------------\n");
				}
				catch (IOException)
				{
					throw (new InterpreterException("error: could not write to the given file"));
				}
			}
		}
	}
}