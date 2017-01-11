using System;
using System.IO;

namespace ToySharpLanguageInterpreter
{
	public class CloseRFileStatement : Statement
	{
		private Expression fileDescriptor;

		public CloseRFileStatement(Expression fileDescriptor)
		{
			this.fileDescriptor = fileDescriptor;
		}


		public ProgramState execute(ProgramState programState)
		{
			try
			{
				int descriptor = fileDescriptor.evaluate(programState.getSymbolTable());
				FileTable<int, FileData<string, StreamReader>> fileTable = programState.getFileTable();
				StreamReader bufferedReader = fileTable.getValue(descriptor).Item2;

				bufferedReader.Close();
				fileTable.remove(descriptor);

				return programState;

			}
			catch (IOException)
			{
				throw (new InterpreterException("error: file could not be closed"));
			}
		}


		public override string ToString()
		{
			return "closeRFile(" + fileDescriptor + ")";
		}
	}
}
