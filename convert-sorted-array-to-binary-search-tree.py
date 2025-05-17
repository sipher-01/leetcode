# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def bst(self,nums,l,r):
        if l>r:
            return None
        mid = int((l + r)/2)
        left = self.bst(nums,l,mid-1)
        right = self.bst(nums,mid+1,r)
        node = TreeNode(nums[mid],left,right)
        return node

    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        n = len(nums)
        return self.bst(nums,0,n-1)

        