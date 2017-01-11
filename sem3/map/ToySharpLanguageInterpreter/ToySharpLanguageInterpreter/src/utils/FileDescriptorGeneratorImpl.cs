using System;

namespace ToySharpLanguageInterpreter
{
	public class FileDescriptorGeneratorImpl : FileDescriptorGenerator
	{
		private int currentNumber;

		public int next()
		{
			currentNumber += 1;
			return currentNumber;
		}
	}
}