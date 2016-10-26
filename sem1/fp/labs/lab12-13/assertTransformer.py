tryblock = [False]


def replace(S, a, b):
    p = S.find(a)
    if p == -1:
        return S
    q = S.find(a) + len(a)
    return S[:p] + b + S[q:]


def main(tryblock):
    inp = input()

    newLine = ""

    inp = replace(inp, "__", "")
    inp = replace(inp, "():", "(self):")
    inp = replace(inp, "Activity(p, \"2015.12.20\", \"12:12\", \"Swimming\")", "a1")
    inp = replace(inp, "Activity(p, \"2016.01.20\", \"12:12\", \"Swimming\")", "a2")
    inp = replace(inp, "Activity(q, \"2015.12.21\", \"12:12\", \"Swimming\")", "a3")
    inp = replace(inp, "Activity(q, \"2015.12.20\", \"10:12\", \"Reading\")", "a4")
    
    line = inp.split()

    if ("==" in line and "True" in line) or ("!=" in line and "False" in line):
        newLine = inp[:inp.find("assert")] + "self.assertTrue("
        newLine += line[1] + ")"
    elif ("==" in line and "False" in line) or ("!=" in line and "True" in line):
        newLine = inp[:inp.find("assert")] + "self.assertFalse("
        newLine += line[1] + ")"
    elif "==" in line:
        newLine = inp[:inp.find("assert")] + "self.assertEqual("
        newLine += line[1] + ", "
        newLine += line[3] + ")"
    elif "!=" in line:
        newLine = inp[:inp.find("assert")] + "self.assertNotEqual("
        newLine += line[1] + ", "
        newLine += line[3] + ")"
    else:
        newLine = inp

    if "try:" in inp or "except" in inp:
        tryblock[0] = True

    if not tryblock[0]:
        print(newLine)

    if "assert True" in inp or "assert False" in inp:
        tryblock[0] = False


while True:
    main(tryblock)
