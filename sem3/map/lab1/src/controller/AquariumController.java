package controller;

import model.Being;
import model.Fish;
import model.Turtle;
import repository.BeingRepository;

/**
 * Created by mirko on 05/10/16.
 */
public class AquariumController {
    private BeingRepository repository;

    public AquariumController(BeingRepository repository) {
        this.repository = repository;
    }

    public void addBeing(Being being) {
        repository.add(being);
    }

    public void addFish(String name, double age, String color) {
        addBeing(new Fish(name, age, color));
    }

    public void addTurtle(String name, double age, double weight) {
        addBeing(new Turtle(name, age, weight));
    }

    public void displayBeingsOlderThan(double age) {
        for (Being being : repository.getAll()) {
            if (being.getAge() >= age) {
                System.out.println(being);
            }
        }
    }
}
