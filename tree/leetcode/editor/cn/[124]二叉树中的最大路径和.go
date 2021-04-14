//路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不
//一定经过根节点。 
//
// 路径和 是路径中各节点值的总和。 
//
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3]
//输出：6
//解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6 
//
// 示例 2： 
//
// 
//输入：root = [-10,9,20,null,null,15,7]
//输出：42
//解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目范围是 [1, 3 * 104] 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 深度优先搜索 递归 
// 👍 1013 👎 0

// 分治法
// 1. 左子树最大路径和最大
// 2. 右子树最大路径和最大
// 3. 1和2+根节点路径最大

// 提供两个变量，一个存储子树最大路径和，一个保存左右加根节点和，然后比较大小

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 type ResultMaxSum struct {
    SideMaxSum int // 单边-子树最大路径和+自己
    MaxSum int // （左最大路径和 + 右最大路径和 + 根节点值）和 左右最大值做比较，因为有的节点是负数
 }

 func max (a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
 }

 func GetMaxSum(root *TreeNode) ResultMaxSum {
    if root == nil {
        // tips: MaxSum 等于int类型最小的负数，防止节点有负数值
        return ResultMaxSum{SideMaxSum:0, MaxSum:-(1 << 31)}
    }

    // 分治计算左右子树的单边最大路径和
    leftResult := GetMaxSum(root.Left)
    rightResult := GetMaxSum(root.Right)

    result := ResultMaxSum{}

    // 计算当前节点的最大单边最大值
    if leftResult.SideMaxSum > rightResult.SideMaxSum {
        result.SideMaxSum = max(leftResult.SideMaxSum + root.Val, 0)
    } else {
        result.SideMaxSum = max(rightResult.SideMaxSum + root.Val, 0)
    }

    // 两边加根最大和
    maxSum := max(leftResult.MaxSum, rightResult.MaxSum)
    result.MaxSum = max(maxSum, leftResult.SideMaxSum + rightResult.SideMaxSum + root.Val)
    return result
 }

func maxPathSum(root *TreeNode) int {
    result := GetMaxSum(root)
    return result.MaxSum
}
//leetcode submit region end(Prohibit modification and deletion)
