//给定一个二叉树，判断其是否是一个有效的二叉搜索树。 
//
// 假设一个二叉搜索树具有如下特征： 
//
// 
// 节点的左子树只包含小于当前节点的数。 
// 节点的右子树只包含大于当前节点的数。 
// 所有左子树和右子树自身必须也是二叉搜索树。 
// 
//
// 示例 1: 
//
// 输入:
//    2
//   / \
//  1   3
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//    5
//   / \
//  1   4
//     / \
//    3   6
//输出: false
//解释: 输入为: [5,1,4,null,null,3,6]。
//     根节点的值为 5 ，但是其右子节点值为 4 。
// 
// Related Topics 树 深度优先搜索 递归 
// 👍 1019 👎 0


// 左 < 根 < 右
// 思路一： 中序遍历，判断是否有序
// 思路二：分治法 左边最大的 < root < 右边最小的

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Helper struct {
    IsValid bool
    MaxNode *TreeNode // 防止有负值所以使用节点
    MinNode *TreeNode
}

func do(root *TreeNode) Helper {
    if root == nil {
        return Helper{IsValid:true}
    }

    leftRes := do(root.Left)
    rightRes := do(root.Right)

    result := Helper{}
    if !leftRes.IsValid || !rightRes.IsValid {
        result.IsValid = false
        return result
    }

    // 左最大不能大于根
    if leftRes.MaxNode != nil   && leftRes.MaxNode.Val >= root.Val {
        result.IsValid = false
        return result
    }

    // 右最小不能小于跟
    if rightRes.MinNode != nil && rightRes.MinNode.Val <= root.Val {
        result.IsValid = false
        return result
    }

    // 当前节点子树的最大值和最小值
    result.IsValid = true
    result.MinNode = root
    result.MaxNode = root

    if leftRes.MinNode != nil {
        result.MinNode = leftRes.MinNode
    }
    if rightRes.MaxNode != nil {
        result.MaxNode = rightRes.MaxNode
    }

    return result
}

func isValidBST(root *TreeNode) bool {
    is := do(root)
    return is.IsValid
}
//leetcode submit region end(Prohibit modification and deletion)
