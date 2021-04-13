//根据一棵树的前序遍历与中序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
// Related Topics 树 深度优先搜索 数组

// 思想：
// 前序遍历： 根->左->右 所以前序遍历数组第一个元素是根节点
// 中序遍历： 左->根->右 在中序遍历数组中找到根节点的位置，可以区分左右子树的数量 （当数量为1时说明是叶子节点，返回）
// 根据左右子树数量到前序遍历数组可以找到对应子树的开始位置和结束位置，然后进行递归
// 递归思想：



//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* constructTree(int *preorder, int *inorder, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd) {
    // 创建节点
    int rootValue = preorder[preorderStart]; // 前序遍历数组的开始索引对应的元素就是根节点
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = rootValue;
    root->left = NULL;
    root->right = NULL;

    // 1. 前序遍历数组中开始索引=结束索引 一个元素（一个节点）
    // 2.中序遍历数组中开始索引=结束索引 一个元素（一个节点）
    // 3. 并且这个元素应该=前序遍历中的元素
    if (preorderStart == preorderEnd && inorderStart == inorderEnd && preorder[preorderStart] == inorder[inorderStart]) return root;

    // 在中序遍历数组中找到根节点的下表
    int moveIndex = inorderStart;
    while (moveIndex <= inorderEnd && inorder[moveIndex] != rootValue) {
        moveIndex++;
    }
    // moveIndex索引对应元素是根节点，所以左子树长度如下
    int leftSize = moveIndex - inorderStart;
    int rightSize = inorderEnd - moveIndex;
    if (leftSize > 0) {
        int preLeftStart = preorderStart + 1;
        int preLeftEnd = preLeftStart + leftSize - 1; // = preLeftStart + leftSize
        int inLeftStart = inorderStart;
        int inLeftEnd = moveIndex - 1;
        root->left = constructTree(preorder, inorder, preLeftStart, preLeftEnd, inLeftStart, inLeftEnd);
    }
    if (rightSize > 0) {
        int preRightStart = preorderEnd - rightSize + 1;
        int preRightEnd = preorderEnd;
        int inRightStart = moveIndex + 1;
        int inRightEnd = inorderEnd;
        root->right = constructTree(preorder, inorder, preRightStart, preRightEnd, inRightStart, inRightEnd);
    }
    return root;
}

/**
 * buildTree
 * @param preorder
 * @param preorderSize
 * @param inorder
 * @param inorderSize
 * @return
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (!preorder || !inorder || preorderSize <= 0 || inorderSize <= 0) return NULL;
    if (preorderSize != inorderSize) return NULL;

    int preorderStart, inorderStart = 0;
    int preorderEnd = preorderSize - 1;
    int inorderEnd = inorderSize - 1;
    return constructTree(preorder, inorder, preorderStart, preorderEnd, inorderStart, inorderEnd);
}


//leetcode submit region end(Prohibit modification and deletion)
