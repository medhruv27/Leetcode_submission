class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        adjacency_list = defaultdict(list)
        for (num, den), val in zip(equations, values):
            adjacency_list[num].append([den, val])
            adjacency_list[den].append([num, 1 / val])
        # {'a': [['b', 2.0]], 'b': [['a', 0.5], ['c', 3.0]], 'c': [['b', 0.3333333333333333]]}

        def bfs(source: str , target: str) -> int:
            if source not in adjacency_list or target not in adjacency_list:
                return -1.00000
            queue, visited = deque(), set()
            queue.append([source, 1])
            visited.add(source)
            while queue:
                element, weight_so_far = queue.popleft()
                if element == target:
                    return weight_so_far
                for neighbor, weight in adjacency_list[element]:
                    if neighbor not in visited:
                        queue.append([neighbor, weight_so_far * weight])
                        visited.add(neighbor)
            return -1.00000

        return [bfs(source=query[0], target=query[1]) for query in queries]