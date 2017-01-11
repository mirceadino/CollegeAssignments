using System;
using System.Collections.Generic;
using System.IO;

namespace ToySharpLanguageInterpreter
{
	public class TextMenu
	{
		private Dictionary<string, Command> commands;

		public TextMenu()
		{
			commands = new Dictionary<string, Command>();
		}

		public void addCommand(Command command)
		{
			commands.Add(command.getKey(), command);
		}

		private void printMenu()
		{
			foreach (KeyValuePair<string, Command> command in commands)
			{
				string line = string.Format("{0} : {1}", command.Value.getKey(), command.Value.getDescription());
				Console.WriteLine(line);
			}
		}

		public void show()
		{
			while (true)
			{
				printMenu();

				Console.Write("Type an option: ");
				string key = Console.ReadLine();
				Command command = commands[key];

				if (command == null)
				{
					Console.WriteLine("Option doesn't exist.");
					continue;
				}

				try
				{
					command.execute();
				}
				catch (ExitTextMenuException)
				{
					break;
				}
				catch (InterpreterException err)
				{
					Console.WriteLine(err.Message);
				}
			}
		}
	}
}