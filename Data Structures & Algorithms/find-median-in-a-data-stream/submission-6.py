class MedianFinder:

    def __init__(self):
        # for the bigger half
        self.minHeap = []
        # for the smaller half
        self.maxHeap = []

    def addNum(self, num: int) -> None:
        if len(self.maxHeap) > 0 and num <= self.maxHeap[0] * -1:
            heapq.heappush(self.maxHeap, num * -1)
        elif len(self.minHeap) > 0 and num >= self.minHeap[0]:
            heapq.heappush(self.minHeap, num)
        else:
            heapq.heappush(self.minHeap, num)
        
        if abs(len(self.minHeap) - len(self.maxHeap)) > 1:
            if len(self.minHeap) > len(self.maxHeap):
                top = heapq.heappop(self.minHeap)
                heapq.heappush(self.maxHeap, top * -1)
            else:
                top = heapq.heappop(self.maxHeap)
                heapq.heappush(self.minHeap, top * -1)

    def findMedian(self) -> float:
        if len(self.minHeap) == len(self.maxHeap):
            return (self.minHeap[0] + self.maxHeap[0] * -1) / 2
        elif len(self.minHeap) > len(self.maxHeap):
            return self.minHeap[0]
        else:
            return self.maxHeap[0] * -1
        