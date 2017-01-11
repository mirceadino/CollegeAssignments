using System;
using System.IO;

namespace ToySharpLanguageInterpreter
{
	public class Controller
	{
		private Repository repository;

		public Controller(Repository repository)
		{
			this.repository = repository;
		}

		public void setRepository(Repository repository)
		{
			this.repository = repository;
		}

		public void addProgram(Statement statement)
		{
			ExecutionStack<Statement> executionStack = new ExecutionStackImpl<Statement>();
			SymbolTable<string, int> symbolTable = new SymbolTableImpl<string, int>();
			FileTable<int, FileData<string, StreamReader>> fileTable = new FileTableImpl<int, FileData<string, StreamReader>>();
			FileDescriptorGenerator generator = new FileDescriptorGeneratorImpl();
			Output<string> output = new OutputImpl<string>();

			executionStack.push(statement);

			ProgramState program = new ProgramState(executionStack, symbolTable, fileTable, generator, output);
			repository.add(program);
		}

		public ProgramState getCurrentProgram()
		{
			return repository.getCurrentProgramState();
		}

		public ProgramState executeOneStep(ProgramState program)
		{
			if (program == null) throw (new InterpreterException("error: no program to execute"));

			ExecutionStack<Statement> executionStack = program.getExecutionStack();
			if (executionStack.isEmpty())
			{
				throw (new InterpreterException("\nerror: execution stack is empty"));
			}
			else
			{
				Statement statement = executionStack.pop();
				return statement.execute(program);
			}
		}

		public void executeAllSteps()
		{
			ProgramState currentProgram = repository.getCurrentProgramState();
			while (!currentProgram.getExecutionStack().isEmpty())
			{
				executeOneStep(currentProgram);
				repository.logCurrentProgramState();
			}
		}

		public string currentProgramToString()
		{
			ProgramState currentProgram = repository.getCurrentProgramState();
			return currentProgram.ToString();
		}
	}

}