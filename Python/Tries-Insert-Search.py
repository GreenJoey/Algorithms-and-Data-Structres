class Node:
    def __init__(self):
        self.children = [None,]*26
        self.is_end = False



class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word):
        length = len(word)
        curr = self.root

        for c in word:
            pos = ord(c) - ord('a')

            if curr.children[pos] is None:
                curr.children[pos] = Node()

            curr = curr.children[pos]

        curr.is_end = True

    def search(self, word):
        length = len(word)
        curr = self.root

        for c in  word:
            pos = ord(c) - ord('a')

            if curr.children[pos] is None:
                return False

            curr = curr.children[pos]

        return (curr is not None) and (curr.is_end is True)


if __name__ == '__main__':
    root = Trie()

    for word in ["hello", "hi", "wow", "world"]:
        root.insert(word)

    for word in ["hello", "hi", "world", "wow", "hola", "what"]:
        if root.search(word):
            print(word, "Present")
        else:
            print("Absent")

