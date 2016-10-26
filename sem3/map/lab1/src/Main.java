import controller.AquariumController;
import repository.BeingRepository;
import repository.BeingRepositoryMock;

/**
 * Created by mirko on 05/10/16.
 */
public class Main {
    public static void main(String[] args) {
        BeingRepository repository = new BeingRepositoryMock(1);
        AquariumController aquarium = new AquariumController(repository);

        aquarium.addFish("Nemo", 2.2, "orange");
        aquarium.addFish("Dory", 1.4, "blue");
        aquarium.addTurtle("Big Old Turtle", 230.4, 300);
        aquarium.addTurtle("Big Young Turtle", 0.9, 14);
        aquarium.addFish("Small fish", 0.2, "black and yellow");
        aquarium.addTurtle("Tortoise", 32.0, 12);

        aquarium.displayBeingsOlderThan(2.0);
    }
}
