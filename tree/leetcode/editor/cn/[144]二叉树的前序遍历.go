//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,null,2,3]
//输出：[1,2,3]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 示例 5： 
//
// 
//输入：root = [1,null,2]
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 
// 👍 553 👎 0

// 前序遍历：根->左->右
// 中序遍历：左->根->右
// 后续遍历：左->右->根

// 迭代写法思想：
// 1. 借助栈
// 2. 无论前中后遍历，都是先遍历左子树直到叶子节点（入栈），然后在一个节点一个节点出栈做处理
// 2.1：前序遍历要优先遍历根节点，所以在入栈时，就打印
// 2.2：中遍历要优先遍历左节点，所以在出栈时，打印根节点
// 2.3：后续遍历左右根，所以需要记录上一次遍历的节点是什么，才能找到对应根节点，
// 入栈，获取栈顶元素，判断有没有右节点，有则继续入栈，没有则判断当前节点是叶子节点还是根节点（node->right == lastNode）
// 3. 处理右子树

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}

	result := make([]int, 0)
	stack := make([]*TreeNode, 0)
	for root != nil || len(stack) > 0 {
		for root != nil {
			result = append(result, root.Val)
			stack = append(stack, root)
			root = root.Left
		}

		node := stack[len(stack) - 1]
		stack = stack[:len(stack) - 1]

		root = node.Right
    }

    return result
}
//leetcode submit region end(Prohibit modification and deletion)
