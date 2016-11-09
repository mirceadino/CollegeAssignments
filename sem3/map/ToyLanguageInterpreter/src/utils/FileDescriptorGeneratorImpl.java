package utils;

/**
 * Created by mirko on 09/11/2016.
 */
public class FileDescriptorGeneratorImpl implements FileDescriptorGenerator {
    private int currentNumber;

    @Override
    public int next() {
        currentNumber += 1;
        return currentNumber;
    }
}
