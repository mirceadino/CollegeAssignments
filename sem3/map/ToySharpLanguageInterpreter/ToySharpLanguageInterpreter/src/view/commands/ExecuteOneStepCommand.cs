using System;
using System.IO;

namespace ToySharpLanguageInterpreter
{
	public class ExecuteOneStepCommand : Command
	{
		private Controller controller;

		public ExecuteOneStepCommand(string key, string description, Controller controller) : base(key, description)
		{
			this.controller = controller;
		}


		public override void execute()
		{
			try
			{
				controller.executeOneStep(controller.getCurrentProgram());
				Console.WriteLine(controller.currentProgramToString());
			}
			catch (InterpreterException error)
			{
				Console.WriteLine(error.Message);
			}
		}
	}
}