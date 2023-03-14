# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        def getHeight(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            return max(getHeight(node.left), getHeight(node.right)) + 1

        height = getHeight(root) - 1
        width = 2 ** (height + 1) - 1
        result = [[''] * width for _ in range(height + 1)]

        def placeNode(node: Optional[TreeNode], r: int, c: int):
            if not node:
                return
                
            result[r][c] = str(node.val)
            placeNode(node.left,  r + 1, c - 2 ** (height - r - 1))
            placeNode(node.right, r + 1, c + 2 ** (height - r - 1))
    
        placeNode(root, 0, int(width / 2))

        return result


