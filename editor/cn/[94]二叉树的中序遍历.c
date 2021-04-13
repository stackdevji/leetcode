//给定一个二叉树，返回它的中序 遍历。 
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
//输出: [1,3,2] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 哈希表

// 思想：左->根->右

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int getTreeSize(struct TreeNode* root) {
    if (!root) return 0;
    return getTreeSize(root->left) + getTreeSize(root->right) + 1;
}

void inOrder(struct TreeNode* root, int *res, int *returnSize) {
    if (!root) return;
    inOrder(root->left, res, returnSize);
    res[(*returnSize)++] = root->val;
    inOrder(root->right, res, returnSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int treeSize = getTreeSize(root);
    int *res = malloc(sizeof(int) * treeSize);
    *returnSize = 0;

    inOrder(root, res, returnSize);
    return res;
}


//leetcode submit region end(Prohibit modification and deletion)
