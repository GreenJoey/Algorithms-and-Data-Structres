class Node:
    def __init__(self, data=None):
        self.next = []
        self.prev = []
        self.data = data
        self.height = 0

    def __str__(self):
        return f"Node {self.data}"


class SkipList:
    def __init__(self):
        self.head = Node()

    def find(self, key):
        current = self.head  # Ponts to the current node
        layer = head.height  # The current link layer

        while layer >= 0:
            if current.key == key:
                # We found the key
                return True
            if current.next[layer] is None or current.next[layer].data > key:
                # We reached a link where the next elements are either
                # unavaliable or are greater than the key element
                # GO down a layer
                layer -= 1
            else:
                # We are in a correct layer, keep moving next
                current = current.next[layer]

        # If we are here, then it means that the key can't be found
        return False


