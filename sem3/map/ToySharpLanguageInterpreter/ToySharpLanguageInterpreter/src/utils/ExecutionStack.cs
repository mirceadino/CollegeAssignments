using System.Collections.Generic;

namespace ToySharpLanguageInterpreter
{
	public interface ExecutionStack<S>
	{
		void push(S statement);

		S pop();

		bool isEmpty();

		string ToString();

		List<S> getAll();
	}
}