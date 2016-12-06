package utils;

/**
 * Created by mirko on 09/11/2016.
 */
public class NumberGeneratorImpl implements NumberGenerator {
    private int currentNumber;

    public NumberGeneratorImpl(int number) {
        this.currentNumber = number;
    }

    @Override
    public int next() {
        currentNumber += 1;
        return currentNumber;
    }
}
