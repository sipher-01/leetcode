from collections import defaultdict
class Solution:
    # def dfs(self,node,colors,graph,count,visi):
    #     if not visi[node]:
    #         visi[node] = 1
    #         for adj in graph[node]:
    #             if self.dfs(adj,colors,graph,count,visi) == inf:
    #                 return inf
    #             for c in range(26):
    #                 count[node][c] = max(count[node][c],count[adj][c])
            
    #         count[node][ord(colors[node]) - ord('a')]
    #         visi[node] = 2
        
    #     return count[node][ord(colors[node]) - ord('a')] if visi[node]==2 else inf

    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        INF = float('inf')
        adj = defaultdict(list)
        for i,j in edges:
            adj[i].append(j)
        
        n = len(colors)
        vis = [0]*n
        count = [[0]*26 for _ in range(n)]
        ans = 0
        def dfs(node):
            if vis[node] == 1:
                return INF   
            if vis[node] == 2:
                return count[node][ord(colors[node]) - ord('a')]
            
            vis[node] = 1
            for nxt in adj[node]:
                res = dfs(nxt)
                if res == INF:
                    return INF
                for c in range(26):
                    count[node][c] = max(count[node][c], count[nxt][c])
            
            col = ord(colors[node]) - ord('a')
            count[node][col] += 1
            vis[node] = 2  
            
            return count[node][col]

        for i in range(n):
            if ans == inf:
                break
            ans = max(ans,dfs(i))
        
        return -1 if ans==inf else ans
        
        
