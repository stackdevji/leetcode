//给定一个二叉树，检查它是否是镜像对称的。 
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
//
//     1
//   / \
//  2   2
// / \ / \
//3  4 4  3
// 
//
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
//
//     1
//   / \
//  2   2
//   \   \
//   3    3
// 
//
// 说明: 
//
// 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。 
// Related Topics 树 深度优先搜索 广度优先搜索

// 思想：
// 1. 一课树的前序遍历是根左右
// 2. 我们可以定义一个根右左的遍历顺序
// 3. 如果前序遍历和我们自己定义的遍历结果一样，那就说明是对称二叉树
// 4. 要考虑叶子节点的空指针

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSymmetrical(struct TreeNode* root_1, struct TreeNode* root_2) {
    if (root_1 == NULL && root_2 == NULL) return true;
    if (root_1 == NULL || root_2 == NULL) return false;
    if (root_1->val != root_2->val) return false;
    return isSymmetrical(root_1->left, root_2->right) && isSymmetrical(root_1->right, root_2->left);
}

bool isSymmetric(struct TreeNode* root){
    return isSymmetrical(root, root);
}


//leetcode submit region end(Prohibit modification and deletion)
