//请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。 
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
//
// 1 
// / \ 
// 2 2 
// / \ / \ 
//3 4 4 3 
//但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
//
// 1 
// / \ 
// 2 2 
// \ \ 
// 3 3 
//
// 
//
// 示例 1： 
//
// 输入：root = [1,2,2,3,4,4,3]
//输出：true
// 
//
// 示例 2： 
//
// 输入：root = [1,2,2,null,3,null,3]
//输出：false 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 1000 
//
// 注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/ 
// Related Topics 树 
// 👍 164 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 思想1：中序遍历 + 双指针判断值是否相等，注意，NULL要补0, 防止7 7 7 7 7 7 7这种
// 思想2， 判断每个子树是否对称

bool doSymmetric(struct TreeNode* A, struct TreeNode* B) {
    if (A == NULL && B == NULL) return true;

    if (A == NULL || B == NULL) return false;

    if (A->val != B->val) return false;

    // 判断每个子树是否对称
    return doSymmetric(A->left, B->right) && doSymmetric(A->right, B->left);
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;

    return doSymmetric(root, root);
}


//leetcode submit region end(Prohibit modification and deletion)
