class Tree:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def append(self, data):
        root = self

        if data < root.data:
            if root.left:
                root.left.append(data)
            else:
                root.left = Tree(data)
        else:
            if root.right:
                root.right.append(data)
            else:
                root.right = Tree(data)
    
    def print(self):
        print(self.data)

        if self.left:
            self.left.print()
        
        if self.right:
            self.right.print()

def construct(data):
    root = Tree(data[0])
    index = 1

    left_elem = [i for i in data[1:] if i <= root.data]
    right_elem = [i for i in data[1:] if i > root.data]

    print(right_elem, left_elem)



if __name__ == '__main__':
        tree = construct([10, 5, 1, 7, 40, 50])
        tree.print()
