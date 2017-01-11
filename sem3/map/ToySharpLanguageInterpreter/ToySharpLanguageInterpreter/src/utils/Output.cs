using System.Collections.Generic;

namespace ToySharpLanguageInterpreter
{
	public interface Output<S>
	{
		void add(S output);

		string ToString();

		List<S> getAll();
	}
}