package repository;

import model.ProgramState;

/**
 * Created by mirko on 12/10/2016.
 */
public interface Repository {
    void add(ProgramState programState);

    ProgramState getCurrentProgramState();
}
