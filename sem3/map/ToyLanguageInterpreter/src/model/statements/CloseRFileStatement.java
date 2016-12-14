package model.statements;

import model.ProgramState;
import model.expressions.Expression;
import utils.FileData;
import utils.FileTable;
import utils.exceptions.InterpreterException;

import java.io.BufferedReader;
import java.io.IOException;

/**
 * Created by mirko on 09/11/2016.
 */
public class CloseRFileStatement implements Statement {
    private Expression fileDescriptor;

    public CloseRFileStatement(Expression fileDescriptor) {
        this.fileDescriptor = fileDescriptor;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws InterpreterException {
        try {
            int descriptor = fileDescriptor.evaluate(programState.getSymbolTable(), programState.getHeap());
            FileTable<Integer, FileData<String, BufferedReader>> fileTable = programState.getFileTable();
            BufferedReader bufferedReader = fileTable.getValue(descriptor).getValue();

            bufferedReader.close();
            fileTable.remove(descriptor);

            return null;

        } catch (IOException e) {
            throw new InterpreterException("error: file could not be closed");
        }
    }

    @Override
    public String toString() {
        return "closeRFile(" + fileDescriptor + ")";
    }
}
