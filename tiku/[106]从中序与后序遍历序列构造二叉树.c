//根据一棵树的中序遍历与后序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
// Related Topics 树 深度优先搜索 数组



//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* constructTree(int *inorder, int *postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd) {
    // 创建节点
    int rootValue = postorder[postorderEnd]; // 后序遍历数组的结束索引对应的元素就是根节点
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = rootValue;
    root->left = NULL;
    root->right = NULL;

    // 1. 前序遍历数组中开始索引=结束索引 一个元素（一个节点）
    // 2.中序遍历数组中开始索引=结束索引 一个元素（一个节点）
    // 3. 并且这个元素应该=前序遍历中的元素
    if (postorderStart == postorderEnd && inorderStart == inorderEnd && postorder[postorderEnd] == inorder[inorderStart]) return root;

    // 在中序遍历数组中找到根节点的下表
    int moveIndex = inorderStart;
    while (moveIndex <= inorderEnd && inorder[moveIndex] != rootValue) {
        moveIndex++;
    }
    // moveIndex索引对应元素是根节点，所以左子树长度如下
    int leftSize = moveIndex - inorderStart;
    int rightSize = inorderEnd - moveIndex;
    if (leftSize > 0) {
        int postLeftStart = postorderStart;
        int postLeftEnd = postLeftStart + leftSize - 1;
        int inLeftStart = inorderStart;
        int inLeftEnd = moveIndex - 1;
        root->left = constructTree(inorder, postorder, inLeftStart, inLeftEnd, postLeftStart, postLeftEnd);
    }
    if (rightSize > 0) {
        int postRightEnd = postorderEnd - 1;
        int postRightStart = postRightEnd - rightSize + 1; // = postorderEnd - rightSize
        int inRightStart = moveIndex + 1;
        int inRightEnd = inorderEnd;
        root->right = constructTree(inorder, postorder, inRightStart, inRightEnd, postRightStart, postRightEnd);
    }
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (!postorder || !inorder || inorderSize <= 0 || postorderSize <= 0) return NULL;
    if (postorderSize != inorderSize) return NULL;

    int postorderStart, inorderStart = 0;
    int postorderEnd = postorderSize - 1;
    int inorderEnd = inorderSize - 1;
    return constructTree(inorder, postorder, inorderStart, inorderEnd, postorderStart, postorderEnd);
}


//leetcode submit region end(Prohibit modification and deletion)
