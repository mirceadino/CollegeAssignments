package repository;

import model.Being;

/**
 * Created by mirko on 05/10/16.
 */
public interface BeingRepository {
    void add(Being being);

    Being[] getAll();
}
