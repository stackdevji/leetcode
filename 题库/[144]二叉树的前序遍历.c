//给定一个二叉树，返回它的 前序 遍历。 
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
//输出: [1,2,3]
// 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树

// 前序遍历思想
// 根节点->左节点->右节点


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * 获取目标树的节点个数
 * @param root
 * @return
 */
int getTreeSize(struct TreeNode* root) {
    if (!root) return 0;
    return getTreeSize(root->left) + getTreeSize(root->right) + 1;
}

/**
 * 递归前序遍历二叉树并保存输出值和数组长度
 * @param root
 * @param res
 * @param returnSize
 */
void preOrder(struct TreeNode* root, int *res, int *returnSize) {
    if (!root) return;
    res[(*returnSize)++] = root->val;
    preOrder(root->left, res, returnSize);
    preOrder(root->right, res, returnSize);
}

/**
 * * 二叉树的前序遍历递归算法
 * Note: The returned array must be malloced, assume caller calls free().
 * @param root : 树的根节点
 * @param returnSize : 返回数组的长度用来在递归过程中记录当前数组的下标
 * @return
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int treeSize = getTreeSize(root);
    int *res = malloc(sizeof(int) * treeSize);
    *returnSize = 0;

    preOrder(root, res, returnSize);
    return res;
}


//leetcode submit region end(Prohibit modification and deletion)
