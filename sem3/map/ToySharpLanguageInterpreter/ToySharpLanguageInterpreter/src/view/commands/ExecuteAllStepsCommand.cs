using System;
using System.IO;

namespace ToySharpLanguageInterpreter
{
	public class ExecuteAllStepsCommand : Command
	{
		private Controller controller;

		public ExecuteAllStepsCommand(string key, string description, Controller controller) : base(key, description)
		{
			this.controller = controller;
		}


		public override void execute()
		{
			try
			{
				controller.executeAllSteps();
				Console.WriteLine(controller.currentProgramToString());
			}
			catch (InterpreterException error)
			{
				Console.WriteLine(error.Message);
			}
		}
	}

}