using System;

namespace ToySharpLanguageInterpreter
{
	public class AssignmentStatement : Statement
	{

	private string variable;
	private Expression value;

	public AssignmentStatement(string variable, Expression value)
	{
		this.variable = variable;
		this.value = value;
	}

	public ProgramState execute(ProgramState programState) 
	{
		SymbolTable<string, int> symbolTable = programState.getSymbolTable();
		symbolTable.add(variable, value.evaluate(symbolTable));
        return programState;
	}

	public override string ToString()
	{
		return variable + " = " + value;
	}
}
}