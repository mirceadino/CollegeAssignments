package repository;

import model.Being;

/**
 * Created by mirko on 05/10/16.
 */
public class BeingRepositoryMock implements BeingRepository {
    private Being[] beings;
    private int size;
    private int capacity;

    public BeingRepositoryMock(int capacity) {
        this.beings = new Being[capacity];
        this.size = 0;
        this.capacity = capacity;
    }

    @Override
    public void add(Being being) {
        if (size == capacity) resize();
        beings[size++] = being;
    }

    @Override
    public Being[] getAll() {
        Being[] returned_beings = new Being[size];
        for (int i = 0; i < size; ++i) {
            returned_beings[i] = beings[i];
        }
        return returned_beings;
    }

    private void resize() {
        Being[] new_beings = new Being[2 * capacity];
        for (int i = 0; i < capacity; ++i) {
            new_beings[i] = beings[i];
        }
        beings = new_beings;
        capacity *= 2;
    }
}
