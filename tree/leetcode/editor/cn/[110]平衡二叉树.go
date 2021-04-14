//给定一个二叉树，判断它是否是高度平衡的二叉树。 
//
// 本题中，一棵高度平衡二叉树定义为： 
//
// 
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,2,3,3,null,null,4,4]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数在范围 [0, 5000] 内 
// -104 <= Node.val <= 104 
// 
// Related Topics 树 深度优先搜索 递归 
// 👍 663 👎 0

// 分治法

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 获取最大深度
func maxDepPath(root *TreeNode) (bool, int) {
	if root == nil {
		return true, 0
	}

	leftBalance, leftDep := maxDepPath(root.Left)
	rightBalacne, rightDep := maxDepPath(root.Right)

	// 计算最大深度
	dep := rightDep
	if leftDep > rightDep {
		dep = leftDep
	}
	dep = dep + 1

	// 左子树或者右子树不平衡
	if !leftBalance || !rightBalacne {
		return false, dep
	}

	// 左子树和右子树对比
	if leftDep - rightDep > 1 || rightDep - leftDep > 1 {
		return false, dep
	}

	return true, dep
}

func isBalanced(root *TreeNode) bool {
	balance, _ := maxDepPath(root);
	return balance
}
//leetcode submit region end(Prohibit modification and deletion)
