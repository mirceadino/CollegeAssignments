package model;

/**
 * Created by mirko on 05/10/16.
 */
public class Turtle implements Being {
    private String name;
    private double age;
    private double weight;

    public Turtle(String name, double age, double weight) {
        this.name = name;
        this.age = age;
        this.weight = weight;
    }

    @Override
    public double getAge() {
        return age;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("Turtle: " + name);
        builder.append(", age: " + age);
        builder.append(", weight: " + weight);
        return builder.toString();
    }
}
