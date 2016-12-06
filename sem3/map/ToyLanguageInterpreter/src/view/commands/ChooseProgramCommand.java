package view.commands;

import controller.Controller;
import model.expressions.*;
import model.statements.*;
import utils.exceptions.InterpreterException;
import view.TextMenu;

/**
 * Created by mirko on 15/11/2016.
 */
public class ChooseProgramCommand extends Command {
    private Controller controller;

    public ChooseProgramCommand(String key, String description, Controller controller) {
        super(key, description);
        this.controller = controller;
    }

    @Override
    public void execute() throws InterpreterException {
        TextMenu menu = new TextMenu();

        int index = 1;
        while (true) {
            Statement program = getProgram(index);
            if (program == null) {
                break;
            }

            menu.addCommand(new ChooseExampleCommand(
                    "" + index, "Choose example " + index + "\n       " + program,
                    controller,
                    program,
                    "./logs/log" + index + ".txt")
            );
            ++index;
        }

        menu.addCommand(new ExitCommand("0", "Exit submenu"));

        menu.show();
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
                                                                        new ReadHeapExpression("v"),
                                                                        '+')),
                                                        new CompoundStatement(
                                                                new PrintStatement(
                                                                        new ArithExpr(
                                                                                new ConstExpr(100),
                                                                                new ReadHeapExpression("a"),
                                                                                '+')),
                                                                new CompoundStatement(
                                                                        new WriteHeapStatement("a", new ConstExpr(30)),
                                                                        new CompoundStatement(
                                                                                new PrintStatement(new ReadHeapExpression("a")),
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

            default: {
                return null;
            }
        }

    }
}
