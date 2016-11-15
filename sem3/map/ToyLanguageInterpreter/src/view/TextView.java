package view;

import controller.Controller;
import model.expressions.ArithExpr;
import model.expressions.ConstExpr;
import model.expressions.VarExpr;
import model.statements.*;
import repository.Repository;
import repository.SingleProgramStateRepository;
import utils.exceptions.InterpreterException;

import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by mirko on 18/10/2016.
 */
public class TextView {
    private Controller controller;
    private Scanner scanner;
    private PrintWriter printer;

    public TextView(Controller controller, Scanner scanner, PrintWriter printer) {
        this.controller = controller;
        this.scanner = scanner;
        this.printer = printer;
    }

    public void run() throws InterpreterException {
        while (true) {
            printMenu();

            printer.print("Choose option: ");
            printer.flush();
            int option = scanner.nextInt();

            if (option == 0) {
                exit();
                break;
            }

            switch (option) {
                case 1: {
                    inputProgram();
                    break;
                }
                case 2: {
                    executeOneStep();
                    break;
                }
                case 3: {
                    executeAllSteps();
                    break;
                }
                default: {
                    printer.println("Option doesn't exist.");
                    printer.flush();
                    break;
                }
            }
        }
    }

    private void printMenu() {
        printer.println("1 - Choose program");
        printer.println("2 - Execute one step of the current program");
        printer.println("3 - Execute all steps of the current program");
        printer.println("0 - Exit");
        printer.flush();
    }

    private void inputProgram() throws InterpreterException {
        printer.print("Choose program (0 - 7): ");
        printer.flush();
        int option = scanner.nextInt();

        Statement program = getProgramByOption(option);

        if (program != null) {
            controller.addProgram(program);
            printer.println(controller.currentProgramToString());
            printer.flush();

            printer.println("Program was set as current.");
            printer.flush();
        } else {
            printer.println("Program doesn't exist.");
            printer.flush();
        }
    }

    private void executeOneStep() {
        try {
            controller.executeOneStep(controller.getCurrentProgram());
            printer.println(controller.currentProgramToString());
            printer.flush();
        } catch (InterpreterException error) {
            printer.println(error.toString());
            printer.flush();
        }
    }

    private void executeAllSteps() {
        try {
            controller.executeAllSteps();
            printer.println(controller.currentProgramToString());
            printer.flush();
        } catch (InterpreterException error) {
            printer.println(error.toString());
            printer.flush();
        }
    }

    private void exit() {
        printer.println("Bye!");
        printer.flush();
    }

    private Statement getProgramByOption(int option) {
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

            default: {
                return null;
            }
        }

    }

    public static void main(String[] args) throws InterpreterException {
        Repository repository = new SingleProgramStateRepository("./logs/alllogs.txt");
        Controller controller = new Controller(repository);
        TextView textView = new TextView(controller, new Scanner(System.in), new PrintWriter(System.out));

        textView.run();
    }
}
