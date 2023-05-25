import random

opcodes = ["pall", "push", "pop", "nop", "swap"]

for i in range(100):
    with open("bytecodes/{}.m".format(i + 1), "w") as f:
        for j in range(10):
            f.write("{} {}\n".format("push", random.randint(0, 100)))
        for j in range(90):
            if (opcodes in ["pall", "swap", "nop"]):
                opcode = opcodes[random.randint(0, len(opcodes) - 1)]
                f.write("{}\n".format(opcode))
            else:
                f.write("{} {} \n".format(opcodes[random.randint(0, len(opcodes) - 1)], random.randint(0, 100)))
        f.write("{}\n".format("pint"))
