using System;
using System.IO;

namespace ToySharpLanguageInterpreter
{
	public class ChooseExampleCommand : Command
	{
		private Controller controller;
		private Statement statement;
		private string logfile;

		public ChooseExampleCommand(string key, string description, Controller controller,
									Statement statement, string logfile) : base(key, description)
		{
			this.controller = controller;
			this.statement = statement;
			this.logfile = logfile;
		}


		public override void execute()
		{
			Repository repository = new SingleProgramStateRepository(logfile);
			controller.setRepository(repository);
			controller.addProgram(statement);
			throw (new ExitTextMenuException("Program was chosen."));
		}
	}
}