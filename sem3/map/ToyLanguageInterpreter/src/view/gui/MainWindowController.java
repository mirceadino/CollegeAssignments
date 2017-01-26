package view.gui;

import controller.Controller;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.stage.Modality;
import javafx.stage.Stage;
import model.ProgramState;
import model.statements.Statement;
import utils.FileData;
import utils.exceptions.InterpreterException;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.toList;

public class MainWindowController {

    @FXML
    private TextField programStatesTitle;

    @FXML
    private ListView<String> programStates;

    @FXML
    private Button runOneStepButton;

    @FXML
    private TableView<Map.Entry<Integer, Integer>> heapBox;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, String> heapKey;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, String> heapValue;

    @FXML
    private ListView<String> outputBox;

    @FXML
    private TableView<Map.Entry<Integer, String>> fileTableBox;

    @FXML
    private TableColumn<Map.Entry<Integer, String>, String> fileTableKey;

    @FXML
    private TableColumn<Map.Entry<Integer, String>, String> fileTableValue;

    @FXML
    private ListView<String> executionStackBox;

    @FXML
    private TableView<Map.Entry<String, Integer>> symbolTableBox;

    @FXML
    private TableColumn<Map.Entry<String, Integer>, String> symbolTableKey;

    @FXML
    private TableColumn<Map.Entry<String, Integer>, String> symbolTableValue;

    @FXML
    private TableView<Map.Entry<Integer, Integer>> lockTableBox;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, String> lockTableKey;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, String> lockTableValue;

    private Controller controller;

    public void setController(Controller controller) {
        this.controller = controller;
    }

    public void handleUpdateProgramState() {
        update();
    }

    public void handleChooseExample() {
        try {
            // Load the fxml file and create a new stage for the popup dialog.
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(ChooseWindowController.class.getResource("ChooseWindow.fxml"));
            BorderPane root = loader.load();

            // Create the dialog Stage.
            Stage dialogStage = new Stage();
            dialogStage.setTitle("Edit Student");
            dialogStage.initModality(Modality.WINDOW_MODAL);
            Scene scene = new Scene(root);
            dialogStage.setScene(scene);

            ChooseWindowController chooseWindowController = loader.getController();
            chooseWindowController.setController(controller, this, dialogStage);

            dialogStage.show();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void handleRunOneStep() {
        try {
            controller.executeOneStep();
        } catch (InterpreterException e) {
            showMessage(e.toString());
        }

        update();
    }

    static void showMessage(String text) {
        Alert message = new Alert(Alert.AlertType.INFORMATION);
        message.setTitle("Message");
        message.setContentText(text);
        message.showAndWait();
    }

    public void update() {
        populateProgramStates();

        int index = programStates.getFocusModel().getFocusedIndex();
        if (index < 0 && !programStates.getItems().isEmpty()) {
            programStates.getFocusModel().focus(0);
            index = 0;
        }

        populateHeap(index);
        populateOutput(index);
        populateFileTable(index);
        populateSymbolTable(index);
        populateExecutionStack(index);
        populateLockTable(index);
    }

    @FXML
    private void initialize() {
        heapKey.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getKey() + ""));

        heapValue.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getValue() + ""));

        fileTableKey.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getKey() + ""));

        fileTableValue.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getValue() + ""));

        symbolTableKey.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getKey() + ""));

        symbolTableValue.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getValue() + ""));

        lockTableKey.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getKey() + ""));

        lockTableValue.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getValue() + ""));
    }

    private void populateProgramStates() {
        List<ProgramState> programs = controller.getCurrentProgramStates();
        ObservableList<String> model = FXCollections.observableArrayList(
                programs.stream().map(p -> "Program #" + p.getId()).collect(toList())
        );

        programStatesTitle.setText("Program States: " + programs.size());
        programStates.setItems(model);
        programStates.refresh();
    }

    private void populateHeap(int index) {
        ObservableList<Map.Entry<Integer, Integer>> model;

        if (index == -1) {
            model = FXCollections.observableArrayList(new ArrayList<>());

        } else {
            List<ProgramState> programs = controller.getCurrentProgramStates();
            ProgramState program = programs.get(index);
            List<Map.Entry<Integer, Integer>> elements = iterableToList(program.getHeap().getAll());

            model = FXCollections.observableArrayList(elements);
        }

        heapBox.setItems(model);
        heapBox.refresh();
    }

    private void populateOutput(int index) {
        ObservableList<String> model;

        if (index == -1) {
            model = FXCollections.observableArrayList(new ArrayList<>());

        } else {
            List<ProgramState> programs = controller.getCurrentProgramStates();
            ProgramState program = programs.get(index);
            List<String> elements = iterableToList(program.getOutput().getAll());

            model = FXCollections.observableArrayList(elements);
        }

        outputBox.setItems(model);
        outputBox.refresh();
    }

    private void populateFileTable(int index) {
        ObservableList<Map.Entry<Integer, String>> model;

        if (index == -1) {
            model = FXCollections.observableArrayList(new ArrayList<>());

        } else {
            List<ProgramState> programs = controller.getCurrentProgramStates();
            ProgramState program = programs.get(index);
            List<Map.Entry<Integer, FileData<String, BufferedReader>>> all_elements =
                    iterableToList(program.getFileTable().getAll());
            List<Map.Entry<Integer, String>> elements = all_elements.stream().map(
                    p -> new AbstractMap.SimpleEntry<>(p.getKey(), p.getValue().getKey()))
                    .collect(Collectors.toList());

            model = FXCollections.observableArrayList(elements);
        }

        fileTableBox.setItems(model);
        fileTableBox.refresh();
    }

    private void populateSymbolTable(int index) {
        ObservableList<Map.Entry<String, Integer>> model;

        if (index == -1) {
            model = FXCollections.observableArrayList(new ArrayList<>());

        } else {
            List<ProgramState> programs = controller.getCurrentProgramStates();
            ProgramState program = programs.get(index);
            List<Map.Entry<String, Integer>> elements = iterableToList(program.getSymbolTable().getAll());

            model = FXCollections.observableArrayList(elements);
        }

        symbolTableBox.setItems(model);
        symbolTableBox.refresh();
    }

    private void populateExecutionStack(int index) {
        ObservableList<String> model;

        if (index == -1) {
            model = FXCollections.observableArrayList(new ArrayList<>());

        } else {
            List<ProgramState> programs = controller.getCurrentProgramStates();
            ProgramState program = programs.get(index);
            List<Statement> all_elements = iterableToList(program.getExecutionStack().getAll());
            List<String> elements = all_elements.stream().map(p -> p.toString()).collect(Collectors.toList());

            model = FXCollections.observableArrayList(elements);
        }

        executionStackBox.setItems(model);
        executionStackBox.refresh();
    }

    private void populateLockTable(int index) {
        ObservableList<Map.Entry<Integer, Integer>> model;

        if (index == -1) {
            model = FXCollections.observableArrayList(new ArrayList<>());

        } else {
            List<ProgramState> programs = controller.getCurrentProgramStates();
            ProgramState program = programs.get(index);
            List<Map.Entry<Integer, Integer>> elements = iterableToList(program.getLockTable().getAll());

            model = FXCollections.observableArrayList(elements);
        }

        lockTableBox.setItems(model);
        lockTableBox.refresh();
    }

    private <E> List<E> iterableToList(Iterable<E> iterable) {
        List<E> list = new ArrayList<E>();
        for (E element : iterable) {
            list.add(element);
        }
        return list;
    }
}

