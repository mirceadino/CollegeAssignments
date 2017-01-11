using System;

namespace ToySharpLanguageInterpreter
{
	public class Interpreter
	{

		public static void Main(string[] args)
		{
			TextMenu menu = new TextMenu();
			Repository repository = new SingleProgramStateRepository("./logs/alllogs.txt");
			Controller controller = new Controller(repository);

			menu.addCommand(new ChooseProgramCommand("1", "Choose program", controller));
			menu.addCommand(new ExecuteOneStepCommand("2", "Execute one step of the current program", controller));
			menu.addCommand(new ExecuteAllStepsCommand("3", "Execute all steps of the current program", controller));
			menu.addCommand(new ExitCommand("0", "Exit"));

			menu.show();
		}
	}

}