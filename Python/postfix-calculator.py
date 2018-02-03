import operator


ops = {
        "+": operator.add,
        "-": operator.sub,
        "*": operator.mul,
        "/": operator.truediv,
}
stack = []

expr = input("Enter a postfix expression: ")


for token in expr:
    if token in ops.keys():
        left_side = int(stack.pop())
        right_side = int(stack.pop())
        res = ops[token](right_side, left_side)
        stack.append(res)
    else:
        stack.append(token)


print("Result is %d" % stack.pop())
