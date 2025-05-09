from queue import PriorityQueue
class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n = len(moveTime)
        m = len(moveTime[0])
        pq = PriorityQueue()
        pq.put((0,(0,0),0))
        maxi = float('inf')
        dist = [[maxi] * m for _ in range(n)]
        dist[0][0] = 0

        r = [-1,0,1,0]
        c = [0,1,0,-1]
        while not pq.empty():
            time,(row,col),turn = pq.get()
            if row==n-1 and col==m-1:
                return time
            
            for ri,ci in zip(r,c):
                nr = row + ri
                nc = col + ci
                if 0<=nr<n and 0<=nc<m:
                    step = 2 if (nr + nc)%2==0 else 1
                    wait = max(0, moveTime[nr][nc] - time)
                    newTime = time + wait + step
                    if dist[nr][nc]>newTime:
                        dist[nr][nc] = newTime
                        pq.put((newTime,(nr,nc),1-turn))
            
        return -1

        