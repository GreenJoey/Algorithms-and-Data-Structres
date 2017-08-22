from .Node import Node


class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def insert_start(self, data):
        nextNode = Node(data)

        if self.head is None:
            self.head = nextNode
        else:
            newNode .nextnode = self.head
            self.head = newNode

        self.size += 1

    def __len__(self):
        return self.size

    def insert_end(self, data):
        pass

