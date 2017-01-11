using System.Collections.Generic;
using System.Linq;

namespace ToySharpLanguageInterpreter
{
	public class OutputImpl<S> : Output<S>
	{
		private List<S> outputs;

		public OutputImpl()
		{
			this.outputs = new List<S>();
		}


		public void add(S output)
		{
			outputs.Add(output);
		}


		public override string ToString()
		{
			string str = "";
			str += "OutputImpl = {";

			if (outputs.Count() > 0) str += "\n";

			foreach (S output in outputs)
			{
				str += "   " + output + "\n";
			}

			str += "}";
			return str;
		}


		public List<S> getAll()
		{
			return outputs;
		}
	}
}