package view.gui;

import controller.Controller;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.stage.Stage;
import model.expressions.*;
import model.statements.*;
import repository.MultipleProgramStateRepository;
import repository.Repository;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by mirko on 06/01/2017.
 */
public class ChooseWindowController {
    @FXML
    public Button chooseExampleButton;

    @FXML
    public ListView examplesBox;

    private Controller controller;
    private MainWindowController mainWindowController;
    private Stage dialogStage;

    public void setController(Controller controller, MainWindowController mainWindowController, Stage dialogStage) {
        this.controller = controller;
        this.mainWindowController = mainWindowController;
        this.dialogStage = dialogStage;
    }

    public void handleCancel() {
        dialogStage.close();
    }

    public void handleChooseExampleButton() {
        int index = examplesBox.getFocusModel().getFocusedIndex();
        if (index < 0) return;

        String logFile = "./logs/log" + index + ".txt";
        Statement statement = getProgram(index);

        Repository repository = new MultipleProgramStateRepository(logFile);
        controller.setRepository(repository);
        controller.addProgram(statement);

        mainWindowController.update();
        dialogStage.close();
    }

    @FXML
    private void initialize() {
        populateExamplesBox();
    }

    private void populateExamplesBox() {
        List<Statement> programs = new ArrayList<Statement>();
        Statement program = null;
        int index = 0;
        while (true) {
            program = getProgram(index);
            ++index;

            if (program == null) {
                break;
            }

            programs.add(program);
        }

        ObservableList<String> model = FXCollections.observableArrayList(
                programs.stream().map(p -> p.toString()).collect(Collectors.toList())
        );

        examplesBox.setItems(model);
    }

    private Statement getProgram(int option) {
        switch (option) {
            case 0: {
                /* a = 3; */

                return new AssignmentStatement("a", new ConstExpr(3));
            }

            case 1: {
                /* v = 2;
                 * PRINT(v); */

                return new CompoundStatement(
                        new AssignmentStatement("v", new ConstExpr(2)),
                        new PrintStatement(new VarExpr("v")));
            }

            case 2: {
                /* a = 2 + 3 * 5;
                 * b = a + 1;
                 * PRINT(b); */

                return new CompoundStatement(
                        new AssignmentStatement(
                                "a",
                                new ArithExpr(
                                        new ConstExpr(2),
                                        new ArithExpr(
                                                new ConstExpr(3),
                                                new ConstExpr(5),
                                                '*'
                                        ),
                                        '+')),
                        new CompoundStatement(
                                new AssignmentStatement(
                                        "b",
                                        new ArithExpr(
                                                new VarExpr("a"),
                                                new ConstExpr(1),
                                                '+')),
                                new PrintStatement(new VarExpr("b"))));
            }

            case 3: {
                /* a = 2 - 2;
                 * IF(a) THEN(
                 *    v = 2
                 * ) ELSE(
                 *    v = 3
                 * );
                 * PRINT(v) */

                return new CompoundStatement(
                        new AssignmentStatement(
                                "a",
                                new ArithExpr(
                                        new ConstExpr(2),
                                        new ConstExpr(2),
                                        '-'
                                )),
                        new CompoundStatement(
                                new IfStatement(
                                        new VarExpr("a"),
                                        new AssignmentStatement(
                                                "v",
                                                new ConstExpr(2)
                                        ),
                                        new AssignmentStatement(
                                                "v",
                                                new ConstExpr(3)
                                        )
                                ),
                                new PrintStatement(new VarExpr("v"))
                        )
                );
            }

            case 4: {
                /* a = 3;
                 * b = (a * 10 - 10 * 3);
                 * IF(b) THEN(
                 *   c = 100 / b;
                 *   PRINT(c);
                 * ) ELSE(
                 *    IF(a - 2) THEN (
                 *      PRINT(b);
                 *      PRINT(2 * a + 3);
                 *      c = a;
                 *      PRINT(c);
                 * );
                 * */

                return new CompoundStatement(
                        new AssignmentStatement(
                                "a",
                                new ConstExpr(3)
                        ),
                        new CompoundStatement(
                                new AssignmentStatement(
                                        "b",
                                        new ArithExpr(
                                                new ArithExpr(
                                                        new VarExpr("a"),
                                                        new ConstExpr(10),
                                                        '*'
                                                ),
                                                new ArithExpr(
                                                        new ConstExpr(10),
                                                        new ConstExpr(3),
                                                        '*'
                                                ),
                                                '-'
                                        )
                                ),
                                new IfStatement(
                                        new VarExpr("b"),
                                        new CompoundStatement(
                                                new AssignmentStatement(
                                                        "c",
                                                        new ArithExpr(
                                                                new ConstExpr(100),
                                                                new VarExpr("b"),
                                                                '/'
                                                        )
                                                ),
                                                new PrintStatement(
                                                        new VarExpr("c")
                                                )
                                        ),
                                        new IfStatement(
                                                new ArithExpr(
                                                        new VarExpr("a"),
                                                        new ConstExpr(2),
                                                        '-'
                                                ),
                                                new CompoundStatement(
                                                        new PrintStatement(
                                                                new VarExpr("b")
                                                        ),
                                                        new CompoundStatement(
                                                                new PrintStatement(
                                                                        new ArithExpr(
                                                                                new ArithExpr(
                                                                                        new ConstExpr(2),
                                                                                        new VarExpr("a"),
                                                                                        '*'
                                                                                ),
                                                                                new ConstExpr(3),
                                                                                '+'
                                                                        )
                                                                ),
                                                                new CompoundStatement(
                                                                        new AssignmentStatement(
                                                                                "c",
                                                                                new VarExpr("a")
                                                                        ),
                                                                        new PrintStatement(
                                                                                new VarExpr("c")
                                                                        )
                                                                )
                                                        )
                                                ),
                                                null
                                        )
                                )
                        )
                );
            }

            case 5: {
                /* a = 3;
                 * b = a + 3;
                 * d = c - 3;
                 * PRINT(a);
                 * PRINT(b);
                 * PRINT(d);
                 */

                return new CompoundStatement(
                        new AssignmentStatement(
                                "a",
                                new ConstExpr(3)
                        ),
                        new CompoundStatement(
                                new AssignmentStatement(
                                        "b",
                                        new ArithExpr(
                                                new VarExpr("a"),
                                                new ConstExpr(3),
                                                '+'
                                        )
                                ),
                                new CompoundStatement(
                                        new AssignmentStatement(
                                                "d",
                                                new ArithExpr(
                                                        new VarExpr("c"),
                                                        new ConstExpr(3),
                                                        '-'
                                                )
                                        ),
                                        new CompoundStatement(
                                                new PrintStatement(
                                                        new VarExpr("a")
                                                ),
                                                new CompoundStatement(
                                                        new PrintStatement(
                                                                new VarExpr("b")
                                                        ),
                                                        new PrintStatement(
                                                                new VarExpr("d")
                                                        )
                                                )
                                        )
                                )
                        )
                );
            }

            case 6: {
                /* OPENRFILE(var_f, "test.in");
                 * READFILE(var_f, var_c);
                 * IF(var_c) THEN(
                 *   READFILE(var_f, var_c);
                 *   PRINT(var_c);
                 * ) ELSE(
                 *   PRINT(var_c);
                 * );
                 * CLOSERFILE(var_f); */

                return new CompoundStatement(
                        new OpenRFileStatement("var_f", "test.in"),
                        new CompoundStatement(
                                new ReadFileStatement(new VarExpr("var_f"), "var_c"),
                                new CompoundStatement(
                                        new PrintStatement(new VarExpr("var_c")),
                                        new CompoundStatement(
                                                new IfStatement(
                                                        new VarExpr("var_c"),
                                                        new CompoundStatement(
                                                                new ReadFileStatement(new VarExpr("var_f"), "var_c"),
                                                                new PrintStatement(new VarExpr("var_c"))
                                                        ),
                                                        new PrintStatement(new ConstExpr(0))
                                                ),
                                                new CloseRFileStatement(new VarExpr("var_f")))
                                )
                        )
                );
            }

            case 7: {
                /* OPENRFILE(var_f, "test.in");
                 * READFILE(var_f + 2, var_c);
                 * PRINT(var_c);
                 * IF(var_c) THEN(
                 *   READFILE(var_f, var_c);
                 *   PRINT(var_c);
                 * ) ELSE(
                 *   PRINT(0);
                 * );
                 * CLOSERFILE(var_f); */

                return new CompoundStatement(
                        new OpenRFileStatement("var_f", "test.in"),
                        new CompoundStatement(
                                new ReadFileStatement(
                                        new ArithExpr(
                                                new VarExpr("var_f"),
                                                new ConstExpr(2),
                                                '+'),
                                        "var_c"),
                                new CompoundStatement(
                                        new PrintStatement(new VarExpr("var_c")),
                                        new CompoundStatement(
                                                new IfStatement(
                                                        new VarExpr("var_c"),
                                                        new CompoundStatement(
                                                                new ReadFileStatement(new VarExpr("var_f"), "var_c"),
                                                                new PrintStatement(new VarExpr("var_c"))
                                                        ),
                                                        new PrintStatement(new ConstExpr(0))
                                                ),
                                                new CloseRFileStatement(new VarExpr("var_f"))
                                        )
                                )
                        )
                );
            }

            case 8: {
              /* v = 10;
               * NEW(v, 20);
               * NEW(a, 22);
               * PRINT(v);
               * PRINT(100 + READHEAP(v));
               * PRINT(100 + READHEAP(a));
               * WRITEHEAP(a, 30)
               * PRINT(READHEAP(a))
               * a = 0 */

                return new CompoundStatement(
                        new AssignmentStatement("v", new ConstExpr(10)),
                        new CompoundStatement(
                                new NewStatement("v", new ConstExpr(20)),
                                new CompoundStatement(
                                        new NewStatement("a", new ConstExpr(22)),
                                        new CompoundStatement(
                                                new PrintStatement(new VarExpr("v")),
                                                new CompoundStatement(
                                                        new PrintStatement(
                                                                new ArithExpr(
                                                                        new ConstExpr(100),
                                                                        new ReadHeapExpr("v"),
                                                                        '+')),
                                                        new CompoundStatement(
                                                                new PrintStatement(
                                                                        new ArithExpr(
                                                                                new ConstExpr(100),
                                                                                new ReadHeapExpr("a"),
                                                                                '+')),
                                                                new CompoundStatement(
                                                                        new WriteHeapStatement("a", new ConstExpr(30)),
                                                                        new CompoundStatement(
                                                                                new PrintStatement(new ReadHeapExpr("a")),
                                                                                new AssignmentStatement("a", new ConstExpr(0))
                                                                        )
                                                                )
                                                        )
                                                )
                                        )
                                )
                        )
                );
            }

            case 9: {
                /* PRINT(10 + (2 < 6))
                 * PRINT((10 + 2) < 6) */

                return new CompoundStatement(
                        new PrintStatement(
                                new ArithExpr(
                                        new ConstExpr(10),
                                        new BooleanExpr(
                                                new ConstExpr(2),
                                                new ConstExpr(6),
                                                "<"),
                                        '+')),
                        new PrintStatement(
                                new BooleanExpr(
                                        new ArithExpr(
                                                new ConstExpr(10),
                                                new ConstExpr(2),
                                                '+'
                                        ),
                                        new ConstExpr(6),
                                        "<")));
            }

            case 10: {
               /* v = 6;
                * WHILE(v > 4) DO(
                *   PRINT(v);
                *   v = v - 1;
                * )
                * PRINT(v) */

                return new CompoundStatement(
                        new AssignmentStatement("v", new ConstExpr(6)),
                        new CompoundStatement(
                                new WhileStatement(
                                        new BooleanExpr(new VarExpr("v"), new ConstExpr(4), ">"),
                                        new CompoundStatement(
                                                new PrintStatement(new VarExpr("v")),
                                                new AssignmentStatement(
                                                        "v",
                                                        new ArithExpr(new VarExpr("v"), new ConstExpr(1), '-'))
                                        )
                                ),
                                new PrintStatement(new VarExpr("v"))
                        )
                );
            }

            case 11: {
               /* v = 10;
                * NEW(a, 22);
                * FORK(WRITEHEAP(a, 30); v = 32; PRINT(v); PRINT(READHEAP(a));
                * PRINT(v); PRINT(READHEAP(a)); */

                return new CompoundStatement(
                        new AssignmentStatement("v", new ConstExpr(10)),
                        new CompoundStatement(
                                new NewStatement("a", new ConstExpr(22)),
                                new CompoundStatement(
                                        new ForkStatement(
                                                new CompoundStatement(
                                                        new WriteHeapStatement("a", new ConstExpr(30)),
                                                        new CompoundStatement(
                                                                new AssignmentStatement("v", new ConstExpr(32)),
                                                                new CompoundStatement(
                                                                        new PrintStatement(new VarExpr("v")),
                                                                        new PrintStatement(new ReadHeapExpr("a"))
                                                                )
                                                        )
                                                )

                                        ),
                                        new CompoundStatement(
                                                new PrintStatement(new VarExpr("v")),
                                                new PrintStatement(new ReadHeapExpr("a"))
                                        )
                                )
                        )
                );
            }

            default: {
                return null;
            }
        }

    }
}
