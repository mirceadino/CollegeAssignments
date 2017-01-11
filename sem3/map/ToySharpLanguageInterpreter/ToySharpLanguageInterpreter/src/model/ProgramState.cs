using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ToySharpLanguageInterpreter
{
	public class ProgramState
	{
		private ExecutionStack<Statement> executionStack;
		private SymbolTable<string, int> symbolTable;
		private FileTable<int, FileData<string, StreamReader>> fileTable;
		private FileDescriptorGenerator generator;
		private Output<string> output;

		public ProgramState(ExecutionStack<Statement> executionStack,
							SymbolTable<string, int> symbolTable,
							FileTable<int, FileData<string, StreamReader>> fileTable,
							FileDescriptorGenerator generator,
							Output<string> output)
		{
			this.executionStack = executionStack;
			this.symbolTable = symbolTable;
			this.fileTable = fileTable;
			this.generator = generator;
			this.output = output;
		}

		public ExecutionStack<Statement> getExecutionStack()
		{
			return executionStack;
		}

		public SymbolTable<string, int> getSymbolTable()
		{
			return symbolTable;
		}

		public FileTable<int, FileData<string, StreamReader>> getFileTable()
		{
			return fileTable;
		}

		public FileDescriptorGenerator getFileDescriptorGenerator()
		{
			return generator;
		}

		public Output<string> getOutput()
		{
			return output;
		}


		public override string ToString()
		{
			return executionStack.ToString() + "\n"
					+ symbolTable.ToString() + "\n"
					+ fileTable.ToString() + "\n"
					+ output.ToString();
		}
	}
}