# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.a = float('inf')
    
    def mini(self,root,depth):
        if root is None:
            return
        if not root.left and not root.right:
            self.a = min(self.a,depth)
        
        self.mini(root.left,depth+1)
        self.mini(root.right,depth+1)
    
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        self.mini(root,1)
        return self.a
        