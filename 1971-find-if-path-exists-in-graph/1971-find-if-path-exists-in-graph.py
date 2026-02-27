class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        #adj list->vis push ->bfs ->mark vis-> if vis of that node false return false
        adj = defaultdict(list)
        for edge in edges:
            # edge is [u, v]. Unpack them or use edge[0], edge[1]
            u, v = edge[0], edge[1]
            adj[u].append(v)
            adj[v].append(u)
        vis = {source}
        q = deque([source])
        while q:
            node = q.popleft()
            for adjn in adj[node]:
                if adjn not in vis:
                    vis.add(adjn)
                    q.append(adjn)
        return destination in vis