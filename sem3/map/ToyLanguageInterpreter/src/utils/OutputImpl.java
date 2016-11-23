package utils;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by mirko on 12/10/2016.
 */
public class OutputImpl<S> implements Output<S> {
    private List<S> outputs;

    public OutputImpl() {
        this.outputs = new ArrayList<S>();
    }

    @Override
    public void add(S output) {
        outputs.add(output);
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("OutputImpl = {");

        if (!outputs.isEmpty()) string.append("\n");

        for (S output : outputs) {
            string.append("   " + output + "\n");
        }

        string.append("}");
        return string.toString();
    }

    @Override
    public Iterable<S> getAll() {
        return outputs;
    }
}
