class Solution:
    def watchedVideosByFriends(self, wv: List[List[str]], adj: List[List[int]], id: int, level: int) -> List[str]:
        vis = set()
        q = deque([(id,0)])
        c = Counter()
        vis.add(id)
        while q:
            node , depth = q.popleft()
            if depth == level:
                c.update(wv[node])
            for adjn in adj[node]:
                if adjn not in vis:
                    q.append([adjn,depth+1])
                    vis.add(adjn)

        sorted_items = sorted(c.items(), key=lambda x: (x[1], x[0]))
        
        # 4. Extract names and return
        return [item[0] for item in sorted_items]