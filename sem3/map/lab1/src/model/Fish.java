package model;

/**
 * Created by mirko on 05/10/16.
 */
public class Fish implements Being {
    private String name;
    private double age;
    private String color;

    public Fish(String name, double age, String color) {
        this.name = name;
        this.age = age;
        this.color = color;
    }

    @Override
    public double getAge() {
        return age;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("Fish: " + name);
        builder.append(", age: " + age);
        builder.append(", color: " + color);
        return builder.toString();
    }
}
