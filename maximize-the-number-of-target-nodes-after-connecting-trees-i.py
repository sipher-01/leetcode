from collections import defaultdict
class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        def solve(node,depth,visi,x,graph):
            if depth>x:
                return 0
            count = 1
            for adj in graph[node]:
                if not visi[adj]:
                    visi[adj] = True
                    count += solve(adj,depth+1,visi,x,graph)
            
            return count
        
        def build(edges,x):
            graph = defaultdict(list)
        
            n = len(edges)+1

            for u,v in edges:
                graph[u].append(v)
                graph[v].append(u)
        
            ans = [0]*n
            for i in range(n):
                visi = [False]*n
                visi[i] = True
                ans[i] =  solve(i,0,visi,x,graph)
            
            return ans

        n = len(edges1) + 1
        count1 = build(edges1, k)
        count2 = build(edges2, k - 1)
        maxCount2 = max(count2)
        res = [count1[i] + maxCount2 for i in range(n)]
        return res






        