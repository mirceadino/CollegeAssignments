package model.statements;

import model.ProgramState;

/**
 * Created by mirko on 12/10/2016.
 */
public interface Statement {
    ProgramState execute(ProgramState programState);

    String toString();
}
