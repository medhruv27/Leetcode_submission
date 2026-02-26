class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        
        def dfs(vis : set(),root: int,rooms: List[List[int]]):
            vis.add(root)
            for node in rooms[root]:
                if node not in vis:
                    dfs(vis,node,rooms)
            return
        
        n = len(rooms)
        vis = set()
        dfs(vis,0,rooms)
        if len(vis) == len(rooms):
            return True
        return False
    