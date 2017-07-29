class Node:
    def __init__(self, key: int, name: str):
        self.key = key
        self.name = name

        self.left = None
        self.right= None

    def __str__(self):
        return "%s has a key %d" %(self.name, self.key)


class BinaryTree:
    def __init__(self):
        self.root = None

    def addNode(self, key: int, name: str) -> None:
        newNode = Node(key, name)

        if self.root is None:
            self.root = newNode
        else:
            focus = self.root
            parent = None

            while True:
                parent = focus

                if key < focus.key:
                    focus = focus.left

                    if focus is None:
                        parent.left = newNode
                        return
                else:
                    focus = focus.right

                    if focus is None:
                        parent.right = newNode
                        return

    def inOrder(self, focus: Node):
        if focus is not None:
            self.inOrder(focus.left)
            print(focus)
            self.inOrder(focus.right)

    def preOrder(self, focus: Node):
        if focus is not None:
            print(focus)
            self.preOrder(focus.left)
            self.preOrder(focus.right)

    def postOrder(self, focus: Node):
        if focus is not None:
            self.postOrder(focus.left)
            self.postOrder(focus.right)
            print(focus)

    def findNode(self, key: Node) -> Node:
        focus = self.root

        while focus.key != key :
            if key < focus.key :
                focus = focus.left
            else:
                focus = focus.right

            if focus is None:
                return None
        return focus


if __name__ == '__main__':
    tree = BinaryTree()

    tree.addNode(50, "Boss")
    tree.addNode(25, "Vice President")
    tree.addNode(15, "Office Manager")
    tree.addNode(30, "Secretary")
    tree.addNode(75, "Sales Manager")
    tree.addNode(85, "Salesman 1")

    # tree.inOrder(tree.root)
    # tree.preOrder(tree.root)
    tree.postOrder(tree.root)

    print("", tree.findNode(30))
