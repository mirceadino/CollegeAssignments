package controller;

import model.ProgramState;
import model.statements.Statement;
import repository.Repository;
import utils.*;
import utils.exceptions.InterpreterException;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * Created by mirko on 12/10/2016.
 */
public class Controller {
    private Repository repository;

    public Controller(Repository repository) {
        this.repository = repository;
    }

    public void setRepository(Repository repository) {
        this.repository = repository;
    }

    public Repository getRepository() {
        return this.repository;
    }

    public void addProgram(Statement statement) {
        ExecutionStack<Statement> executionStack = new ExecutionStackImpl<>();
        SymbolTable<String, Integer> symbolTable = new SymbolTableImpl<>();
        Output<String> output = new OutputImpl<String>();
        FileTable<Integer, FileData<String, BufferedReader>> fileTable = new FileTableImpl<>();
        NumberGenerator fileDescriptorGenerator = new NumberGeneratorImpl(0);
        Heap<Integer, Integer> heap = new HeapImpl<>();
        NumberGenerator heapAddressGenerator = new NumberGeneratorImpl(1);

        executionStack.push(statement);

        ProgramState program = new ProgramState(executionStack, symbolTable, output, fileTable, fileDescriptorGenerator,
                heap, heapAddressGenerator);
        repository.add(program);
    }

    public ProgramState getCurrentProgram() throws InterpreterException {
        return repository.getCurrentProgramState();
    }

    public ProgramState executeOneStep(ProgramState program) throws InterpreterException {
        if (program == null) throw new InterpreterException("error: no program to execute");

        ExecutionStack<Statement> executionStack = program.getExecutionStack();
        Statement statement = executionStack.pop();
        if (statement == null) throw new InterpreterException("\nerror: execution stack is empty");
        return statement.execute(program);
    }

    public void executeAllSteps() throws InterpreterException {
        ProgramState currentProgram = repository.getCurrentProgramState();
        while (!currentProgram.getExecutionStack().isEmpty()) {
            executeOneStep(currentProgram);
            currentProgram.getHeap().setContent(
                    conservativeGarbageCollector(
                            currentProgram.getSymbolTable(),
                            currentProgram.getHeap()));
            repository.logCurrentProgramState();
        }
    }

    public String currentProgramToString() throws InterpreterException {
        ProgramState currentProgram = repository.getCurrentProgramState();
        return currentProgram.toString();
    }

    Map<Integer, Integer> conservativeGarbageCollector(SymbolTable<String, Integer> symbolTable,
                                                       Heap<Integer, Integer> heap) {
        Collection<Integer> symbolTableValues = new ArrayList<Integer>();
        for (Integer value : symbolTable.getValues()) {
            symbolTableValues.add(value);
        }

        Map<Integer, Integer> heapEntries = new HashMap<Integer, Integer>();
        for (Map.Entry<Integer, Integer> entry : heap.getAll()) {
            heapEntries.put(entry.getKey(), entry.getValue());
        }

        return heapEntries.entrySet().stream()
                .filter(e -> symbolTableValues.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }
}
