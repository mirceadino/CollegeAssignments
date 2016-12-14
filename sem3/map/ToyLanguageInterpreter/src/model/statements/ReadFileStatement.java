package model.statements;

import model.ProgramState;
import model.expressions.ConstExpr;
import model.expressions.Expression;
import utils.FileData;
import utils.FileTable;
import utils.exceptions.InterpreterException;

import java.io.BufferedReader;
import java.io.IOException;

/**
 * Created by mirko on 09/11/2016.
 */
public class ReadFileStatement implements Statement {
    private Expression fileDescriptor;
    private String variable;

    public ReadFileStatement(Expression fileDescriptor, String variable) {
        this.fileDescriptor = fileDescriptor;
        this.variable = variable;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws InterpreterException {
        try {
            int descriptor = fileDescriptor.evaluate(programState.getSymbolTable(), programState.getHeap());
            FileTable<Integer, FileData<String, BufferedReader>> fileTable = programState.getFileTable();
            BufferedReader bufferedReader = fileTable.getValue(descriptor).getValue();

            String line = bufferedReader.readLine();
            ConstExpr value;

            if (line == null) {
                value = new ConstExpr(0);
            } else {
                value = new ConstExpr(Integer.parseInt(line));
            }

            Statement assignment = new AssignmentStatement(variable, value);
            return assignment.execute(programState);

        } catch (IOException e) {
            throw new InterpreterException("error: file could not be read");
        }
    }

    @Override
    public String toString() {
        return "readFile(" + fileDescriptor + ", " + variable + ")";
    }
}
