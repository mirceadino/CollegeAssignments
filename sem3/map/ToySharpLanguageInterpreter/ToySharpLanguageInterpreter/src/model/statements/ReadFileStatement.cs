using System;
using System.IO;

namespace ToySharpLanguageInterpreter
{
	public class ReadFileStatement : Statement
	{
		private Expression fileDescriptor;
		private string variable;

		public ReadFileStatement(Expression fileDescriptor, string variable)
		{
			this.fileDescriptor = fileDescriptor;
			this.variable = variable;
		}


		public ProgramState execute(ProgramState programState)
		{
			try
			{
				int descriptor = fileDescriptor.evaluate(programState.getSymbolTable());
				FileTable<int, FileData<string, StreamReader>> fileTable = programState.getFileTable();
				StreamReader bufferedReader = fileTable.getValue(descriptor).Item2;

				string line = bufferedReader.ReadLine();
				ConstExpr value;

				if (line == null)
				{
					value = new ConstExpr(0);
				}
				else {
					value = new ConstExpr(int.Parse(line));
				}

				Statement assignment = new AssignmentStatement(variable, value);

				return assignment.execute(programState);

			}
			catch (IOException)
			{
				throw (new InterpreterException("error: file could not be read"));
			}
		}


		public override string ToString()
		{
			return "readFile(" + fileDescriptor + ", " + variable + ")";
		}
	}
}