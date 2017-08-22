class Node:
    def __init__(self, name):
        self.data = name
        self.nextnode = None

    def remove(self, data, previous):
        if self.data == data:
            previous.nextnode = self.nextnode
            del self.data
        else:
            if self.nextnode is not None:
                self.nextnode.remove(data, self)

