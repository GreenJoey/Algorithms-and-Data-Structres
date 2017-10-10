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

    def height(self):
        h = 1
        left = right = 0

        if self.left is None and self.right is None:
            return 0

        if self.left:
            left += self.left.height()

        if self.right:
            right += self.right.height()

        h += max((left, right))

        return h

    def __str__(self):
        data = ""
        if self.right:
            data += self.right.__str__()

        data += self.data.__str__()

        if self.left:
            data += self.left.__str__()

        return data

    def __repr__(self):
        return self.__str__()


if __name__ == '__main__':
    tree = Tree(3)

    for v in [5, 2, 1, 4, 6, 7]:
        tree.append(v)

    print(tree)

    print(tree.height())
