package controller;

import model.ProgramState;
import model.Statement;
import repository.Repository;
import utils.*;

/**
 * Created by mirko on 12/10/2016.
 */
public class Controller {
    private Repository repository;

    public Controller(Repository repository) {
        this.repository = repository;
    }

    public void addProgram(Statement statement) {
        ExecutionStack<Statement> executionStack = new ExecutionStackImpl<Statement>();
        SymbolTable<String, Integer> symbolTable = new SymbolTableImpl<String, Integer>();
        Output<String> output = new OutputImpl<String>();

        executionStack.push(statement);

        ProgramState program = new ProgramState(executionStack, symbolTable, output);
        repository.add(program);
    }

    public ProgramState getCurrentProgram() {
        return repository.getCurrentProgramState();
    }

    public ProgramState executeOneStep(ProgramState program) {
        if (program == null) throw new RuntimeException("error: no program to execute");

        ExecutionStack<Statement> executionStack = program.getExecutionStack();
        Statement statement = executionStack.pop();
        if (statement == null) throw new RuntimeException("\nerror: execution stack is empty");
        return statement.execute(program);
    }

    public void executeAllSteps() {
        ProgramState currentProgram = repository.getCurrentProgramState();
        while (!currentProgram.getExecutionStack().isEmpty()) {
            executeOneStep(currentProgram);
            repository.logCurrentProgramState();
        }
    }

    public String currentProgramToString() {
        ProgramState currentProgram = repository.getCurrentProgramState();
        return currentProgram.toString();
    }
}
