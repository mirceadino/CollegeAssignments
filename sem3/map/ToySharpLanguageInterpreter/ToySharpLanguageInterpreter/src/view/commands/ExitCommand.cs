using System;
using System.IO;

namespace ToySharpLanguageInterpreter
{
	public class ExitCommand : Command
	{
		public ExitCommand(string key, string description) : base(key, description)
		{
		}


		public override void execute()
		{
			throw (new ExitTextMenuException(""));
		}
	}
}