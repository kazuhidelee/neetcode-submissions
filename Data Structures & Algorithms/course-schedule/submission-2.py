class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        in_degree = [0] * numCourses
        graph = defaultdict(list)
        for course, prereq in prerequisites:
            in_degree[course] += 1
            graph[prereq].append(course)
        
        bfs = deque()
        # visited = [0] * numCourses
        for i in range(0, numCourses):
            if in_degree[i] == 0:
                bfs.append(i)
                # visited[i] = 1

        numCompleted = 0
        while len(bfs) > 0:
            curr = bfs.popleft()
            numCompleted += 1
            for courses in graph[curr]:
                in_degree[courses] -= 1
                if in_degree[courses] == 0:
                    # visited[courses] = 1
                    bfs.append(courses)


        return numCompleted == numCourses