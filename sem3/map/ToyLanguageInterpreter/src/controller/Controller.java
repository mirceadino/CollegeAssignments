package controller;

import model.ProgramState;
import model.statements.Statement;
import repository.Repository;
import utils.*;
import utils.exceptions.InterpreterException;

import java.io.*;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

/**
 * Created by mirko on 12/10/2016.
 */
public class Controller {
    private Repository repository;
    private ExecutorService executor;

    public Controller(Repository repository) {
        this.repository = repository;
    }

    public void setRepository(Repository repository) {
        this.repository = repository;
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

    public void executeOneStepForAllPrograms(List<ProgramState> list) throws InterpreterException {
        List<Callable<ProgramState>> callableList = list.stream()
                .map(p ->
                        (Callable<ProgramState>) (() -> {
                            return p.executeOneStep();
                        })
                )
                .collect(Collectors.toList());

        List<ProgramState> newList;
        try {
            newList = executor.invokeAll(callableList).stream()
                    .map(future -> {
                        try {
                            return future.get();
                        } catch (InterruptedException e) {
                            throw new InterpreterException("error: interrupted exception");
                        } catch (ExecutionException e) {
                            throw new InterpreterException("error: execution exception");
                        }
                    })
                    .filter(p -> p != null)
                    .collect(Collectors.toList());
        } catch (InterruptedException e) {
            throw new InterpreterException("error: interrupted exception");
        }

        for (ProgramState newProgramState : newList) {
            list.add(newProgramState);
        }

        list.forEach(p -> {
            repository.logProgramState(p);
        });

        repository.setProgramStateList(list);
    }

    public void executeAllSteps() throws InterpreterException {
        clearFile(repository.getLogFilePath());

        executor = Executors.newFixedThreadPool(2);

        repository.getProgramStateList().forEach(p -> {
            repository.logProgramState(p);
        });

        while (true) {
            List<ProgramState> list = removeCompletedPrograms(repository.getProgramStateList());
            if (list.size() == 0) {
                break;
            }
            executeOneStepForAllPrograms(list);
        }
        executor.shutdownNow();
    }

    public String currentProgramStatesToString() throws InterpreterException {
        StringBuilder result = new StringBuilder();
        for (ProgramState programState : repository.getProgramStateList()) {
            result.append(programState + "\n");
        }
        return result.toString();
    }

    public void serializeRepository(String serializeFilePath) throws InterpreterException {
        repository.serialize(serializeFilePath);
    }

    public void deserializeRepository(String serializeFilePath) throws InterpreterException {
        repository.deserialize(serializeFilePath);
    }

    private Map<Integer, Integer> conservativeGarbageCollector(SymbolTable<String, Integer> symbolTable,
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

    private List<ProgramState> removeCompletedPrograms(List<ProgramState> list) {
        return list.stream()
                .filter(p -> p.isNotCompleted())
                .collect(Collectors.toList());
    }

    private void clearFile(String file) throws InterpreterException {
        try (PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(file, false)))) {
        } catch (IOException error) {
            throw new InterpreterException("error: file could not be cleared");
        }
    }
}
