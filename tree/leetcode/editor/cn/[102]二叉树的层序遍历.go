//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例： 
//二叉树：[3,9,20,null,null,15,7], 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其层序遍历结果： 
//
// 
//[
//  [3],
//  [9,20],
//  [15,7]
//]
// 
// Related Topics 树 广度优先搜索 
// 👍 839 👎 0

// 层序遍历借助队列思想，先进先出


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}

	result := make([][]int, 0) // 结果集
	queue := []*TreeNode{root} // 队列
	for len(queue) > 0 {
		l := len(queue) // 每一层元素都会入队，用来控制循环遍历当前层的数据
		list := make([]int, 0)
		for i := 0; i < l; i++ {
			// 当前出队
			node := queue[0]
			queue = queue[1:]
			list = append(list, node.Val)

			// 当前节点左右子节点入队
			if node.Left != nil {
				queue = append(queue, node.Left)
			}

			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}

		result = append(result, list)
	}
	return result
}
//leetcode submit region end(Prohibit modification and deletion)
