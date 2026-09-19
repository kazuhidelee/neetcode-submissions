class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        bfs = deque()
        total = 0
        for i in range(0, n):
            for j in range(0, m):
                if grid[i][j] == 1:
                    total += 1
                if grid[i][j] == 2:
                    bfs.append([i,j])
        directions = [[0, 1], [1, 0], [-1, 0], [0, -1]]
        time = -1
        while len(bfs) > 0:
            s = len(bfs)
            for i in range(0, s):
                curr = bfs.popleft()
                for x, y in directions:
                    new_x = curr[0] + x
                    new_y = curr[1] + y
                    if new_y >= 0 and new_x >= 0 and new_y < m and new_x < n:
                        if grid[new_x][new_y] == 1:
                            grid[new_x][new_y] = 2
                            bfs.append([new_x, new_y])
                            total -= 1
            time += 1
        if total == 0:
            return max(time, 0)
        else:
            return -1
            