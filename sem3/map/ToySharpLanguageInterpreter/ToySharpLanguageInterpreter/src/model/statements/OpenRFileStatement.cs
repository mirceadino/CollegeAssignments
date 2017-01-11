using System;
using System.Collections.Generic;
using System.IO;

namespace ToySharpLanguageInterpreter
{
	public class OpenRFileStatement : Statement
	{
		private string variable;
		private string filename;

		public OpenRFileStatement(string variable, string filename)
		{
			this.variable = variable;
			this.filename = filename;
		}


		public ProgramState execute(ProgramState programState)
		{
			try
			{
				checkIfFileNameWasNotUsedOrThrowException(programState);

				StreamReader bufferedReader = new StreamReader(filename);
				FileDescriptorGenerator generator = programState.getFileDescriptorGenerator();
				int descriptor = generator.next();

				SymbolTable<string, int> symbolTable = programState.getSymbolTable();
				symbolTable.add(variable, descriptor);

				FileTable<int, FileData<string, StreamReader>> fileTable = programState.getFileTable();
				fileTable.add(descriptor, new FileData<string, StreamReader>(filename, bufferedReader));

				return programState;

			}
			catch (IOException)
			{
				throw new InterpreterException("error: file could not be open");
			}
		}


		public override string ToString()
		{
			return "openRFile(" + variable + ", \"" + filename + "\")";
		}

		private void checkIfFileNameWasNotUsedOrThrowException(ProgramState programState)
		{
			FileTable<int, FileData<string, StreamReader>> fileTable = programState.getFileTable();

			foreach (KeyValuePair<int, FileData<string, StreamReader>> entry in fileTable.getAll())
			{
				if (entry.Value.Item1 == filename)
				{
					throw (new InterpreterException("error: a file with that name was already open"));
				}
			}
		}
	}
}