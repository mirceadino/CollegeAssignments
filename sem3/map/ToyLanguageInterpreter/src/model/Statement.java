package model;

/**
 * Created by mirko on 12/10/2016.
 */
public interface Statement {
    ProgramState execute(ProgramState programState);

    String toString();
}
