from collections import defaultdict
from collections import deque
class Solution:

    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        # INF = float('inf')
        adj = defaultdict(list)
        n = len(colors)
        indegree = [0]*n
        count = [[0]*26 for _ in range(n)]
        for i,j in edges:
            adj[i].append(j)
            indegree[j]+=1
        
        ans = 0
        count_node = 0 
        q = deque()
        for i in range(n):
            if indegree[i]==0:
                q.append(i)
                count[i][ord(colors[i]) - ord('a')] = 1
        
        while q:
            node = q.popleft()
            count_node += 1
            ans = max(ans,count[node][ord(colors[node]) - ord('a')])
            for ngbr in adj[node]:
                indegree[ngbr]-=1
                if indegree[ngbr]==0:
                    q.append(ngbr)
                for i in range(26):
                    count[ngbr][i] = max(count[ngbr][i],count[node][i]+(1 if (ord(colors[ngbr])-ord('a')) == i else 0))
                    
        

        if count_node<n:
            return -1
        return ans
        # vis = [0]*n
        # ans = 0
        # def dfs(node):
        #     if vis[node] == 1:
        #         return INF   
        #     if vis[node] == 2:
        #         return count[node][ord(colors[node]) - ord('a')]
            
        #     vis[node] = 1
        #     for nxt in adj[node]:
        #         res = dfs(nxt)
        #         if res == INF:
        #             return INF
        #         for c in range(26):
        #             count[node][c] = max(count[node][c], count[nxt][c])
            
        #     col = ord(colors[node]) - ord('a')
        #     count[node][col] += 1
        #     vis[node] = 2  
            
        #     return count[node][col]

        # for i in range(n):
        #     if ans == inf:
        #         break
        #     ans = max(ans,dfs(i))
        
        # return -1 if ans==inf else ans
        
        
