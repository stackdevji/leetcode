//给定一个二叉树，返回它的 后序 遍历。 
//
// 示例: 
//
// 输入: [1,null,2,3]  
//   1
//    \
//     2
//    /
//   3 
//
//输出: [3,2,1] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 
// 👍 565 👎 0

// 后序遍历：左右根
// 根节点最后遍历, 所以非递归方法需要记录上一个节点

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}

	result := make([]int, 0)
	stack := make([]*TreeNode, 0)
	var lastNode *TreeNode
	for root != nil || len(stack) != 0 {
		for root != nil {
            // 当前节点入栈
			stack = append(stack, root)
			// 遍历左节点
			root = root.Left
		}

		node := stack[len(stack) - 1]
		// 左->右-> 根
		// 1. 没有右节点，当前左节点出栈，遍历左节点对应的根节点
		// 2. 有右子节点，右子节点==上一次遍历节点，说明当前节点是根节点，出栈
		if node.Right == nil || node.Right == lastNode {
			stack = stack[:len(stack) - 1]
			result = append(result, node.Val)
			lastNode = node
		} else { // 如果有右节点，右节点开始入栈
			root = node.Right
		}
    }
    return result
}
//leetcode submit region end(Prohibit modification and deletion)
