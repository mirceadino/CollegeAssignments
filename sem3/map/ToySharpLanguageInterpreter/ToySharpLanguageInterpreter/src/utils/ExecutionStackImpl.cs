using System.Collections.Generic;
using System.Linq;

namespace ToySharpLanguageInterpreter
{
	public class ExecutionStackImpl<S> : ExecutionStack<S>
	{
		private Stack<S> stack;

		public ExecutionStackImpl()
		{
			stack = new Stack<S>();
		}


		public void push(S statement)
		{
			stack.Push(statement);
		}


		public S pop()
		{
			return stack.Pop();
		}


		public bool isEmpty()
		{
			return stack.Count() == 0;
		}


		public override string ToString()
		{
			string str = "";
			str += "ExecutionStackImpl = {";

			if (stack.Count() > 0)
			{
				str += "\n";
			}

			foreach (S statement in stack)
			{
				str += "   " + statement + "\n";
			}

			str += "}";
			return str;
		}


		public List<S> getAll()
		{
			return stack.ToList();
		}
	}
}