package view.gui;

import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

/**
 * Created by mirko on 03/01/2017.
 */
public class MainWindow {
    /* rootBox
     * |-- topBox
     * |   |-- programBox
     * |   |   |-- programBoxTitle
     * |   |   +-- programStatesView
     * |   |
     * |   +-- buttomBox
     * |       |-- chooseExampleButton
     * |       +-- runOneStepButton
     * |
     * |-- middleBox
     * |   |-- heapView
     * |   |-- outputView
     * |   +-- fileTableView
     * |
     * +-- bottomBox
     *     |-- symbolTableView
     *     +-- executionStackView
     * */

    private VBox rootBox;
    private HBox topBox;
    private HBox middleBox;
    private HBox bottomBox;
    private VBox programBox;
    private VBox buttonBox;
    private TextField programBoxTitle;
    private ListView<String> programStatesView;
    private Button chooseExampleButton;
    private Button runOneStepButton;
    private TableView<String> heapView;
    private ListView<String> outputView;
    private TableView<String> fileTableView;
    private TableView<String> symbolTableView;
    private ListView<String> executionStackView;

    public MainWindow() {
        initRootBox();
    }

    public void show(Stage primaryStage) throws Exception {
        Scene scene = new Scene(rootBox, 700, 500);
        primaryStage.setTitle("Toy Language Interpreter");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void initRootBox() {
        rootBox = new VBox(5);
        rootBox.setPadding(new Insets(20));
        rootBox.setAlignment(Pos.BASELINE_CENTER);

        topBox = new HBox(5);
        middleBox = new HBox(5);
        bottomBox = new HBox(5);

        rootBox.getChildren().addAll(topBox, middleBox, bottomBox);

        initTopBox();
        initMiddleBox();
        initBottomBox();
    }

    private void initTopBox() {
        programBox = new VBox(5);
        buttonBox = new VBox(5);

        topBox.getChildren().addAll(programBox, buttonBox);

        initProgramBox();
        initButtonBox();
    }

    private void initProgramBox() {
        programBoxTitle = new TextField("Program States");
        programStatesView = new ListView<String>();

        programBox.getChildren().addAll(programBoxTitle, programStatesView);
    }

    private void initButtonBox() {
        chooseExampleButton = new Button("Choose example");
        runOneStepButton = new Button("Run one step");

        buttonBox.getChildren().addAll(chooseExampleButton, runOneStepButton);
    }

    private void initMiddleBox() {
        heapView = new TableView<String>();
        outputView = new ListView<String>();
        fileTableView = new TableView<String>();

        middleBox.getChildren().addAll(heapView, outputView, fileTableView);
    }

    private void initBottomBox() {
        symbolTableView = new TableView<String>();
        executionStackView = new ListView<String>();

        bottomBox.getChildren().addAll(symbolTableView, executionStackView);
    }
}
