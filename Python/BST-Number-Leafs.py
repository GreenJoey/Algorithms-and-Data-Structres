class Tree:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def append(self, data):
        if data > self.data:
            if self.right is None:
                self.right = Tree(data)
            else:
                self.right.append(data)
        else:
            if self.left is None:
                self.left = Tree(data)
            else:
                self.left.append(data)

    def __str__(self):
        data = ""
        if self.right:
            data += self.right.__str__()

        data += self.data.__str__() + "->"

        if self.left:
            data += self.left.__str__()

        return data

    def get_leaves(self):
        leaves = 0
        if self.left is None and self.right is None:
            return 1

        if self.left:
            leaves += self.left.get_leaves()

        if self.right:
            leaves += self.right.get_leaves()

        return leaves


if __name__ == '__main__':
    tree = Tree(45)

    for v in [39, 78, 79, 80, 54, 55]:
        tree.append(v)

    print(tree)

    print("Number of Leaves:", tree.get_leaves())
