package repository;

import model.ProgramState;

/**
 * Created by mirko on 12/10/2016.
 */
public class SingleProgramStateRepository implements Repository {
    private ProgramState programState;

    @Override
    public void add(ProgramState programState) {
        this.programState = programState;
    }

    @Override
    public ProgramState getCurrentProgramState() {
        if (programState == null) throw new RuntimeException("error: no program to execute");
        return programState;
    }
}
