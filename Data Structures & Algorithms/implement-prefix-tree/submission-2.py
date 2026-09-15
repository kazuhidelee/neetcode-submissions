class PrefixTree:
    class PrefixNode:
        def __init__(self):
            self.neighbors = defaultdict()
            self.is_last = False

    def __init__(self):
        self.root = self.PrefixNode()

    def insert(self, word: str) -> None:
        ptr = self.root
        for s in word:
            if s not in ptr.neighbors:
                ptr.neighbors[s] = self.PrefixNode()
            ptr = ptr.neighbors[s]
        ptr.is_last = True

    def search(self, word: str) -> bool:
        ptr = self.root
        for s in word:
            if s not in ptr.neighbors:
                return False
            ptr = ptr.neighbors[s]
        return ptr.is_last

    def startsWith(self, prefix: str) -> bool:
        ptr = self.root
        for s in prefix:
            if s not in ptr.neighbors:
                return False
            ptr = ptr.neighbors[s]
        return True
        