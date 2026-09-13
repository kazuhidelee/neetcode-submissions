# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        q = deque()
        if root:
            q.append(root)
        while len(q) > 0:
            curr_size = len(q)
            curr_list = []
            for i in range(curr_size):
                curr = q.popleft()
                curr_list.append(curr.val)
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            res.append(curr_list)

        return res


        