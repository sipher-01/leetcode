from queue import PriorityQueue
class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n=len(moveTime)
        m=len(moveTime[0])
        q = PriorityQueue()
        q.put((0,(0,0)))
        visi = [[0]*m for _ in range(n)]
        visi[0][0] = 1
        r = [-1,0,1,0]
        c = [0,1,0,-1]
        while not q.empty():
            time,(row,col) = q.get()

            if row==n-1 and col==m-1:
                return time

            for i in range(4):
                nr = row + r[i]
                nc = col + c[i]
                if 0 <= nr < n and 0 <= nc < m  and not visi[nr][nc]:
                    visi[nr][nc]=1
                    moreTime = moveTime[nr][nc]-time
                    if moreTime<=0:
                        moreTime = 0
                    newTime = time + moreTime + 1
                    q.put((newTime,(nr,nc)))
            
        return -1

        