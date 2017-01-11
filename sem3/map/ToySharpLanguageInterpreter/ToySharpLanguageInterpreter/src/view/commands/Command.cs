using System;
using System.IO;

namespace ToySharpLanguageInterpreter
{
	public abstract class Command
	{
		private string key;
		private string description;

		public Command(string key, string description)
		{
			this.key = key;
			this.description = description;
		}

		public abstract void execute();

		public string getKey()
		{
			return key;
		}

		public string getDescription()
		{
			return description;
		}
	}
}