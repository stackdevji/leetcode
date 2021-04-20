//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。 
//
// 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
// Related Topics 树 递归 
// 👍 417 👎 0

// 思想：
// 1. 前序遍历数组第一个元素为根节点 （后续遍历数组最后一个节点为根节点）
// 2. 根节点在中序遍历数组中的位置 将数组分为左右区间，左区间为左子树中序遍历结果，右区间为右子树中序遍历结果
// 3. 统计在中序遍历数组左右区间 【个数】 去前序或者后序数组中获取对应个数的左右子树区间
// 4. 递归判断子区间
// 5. 递归条件结束：区间只有一个元素 （叶子节点）前序数组中的start=end; 中序数组中的start=end;  preOrder[start] = inorder[start];

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 构建树
struct TreeNode* createTree(int* preOrder, int* inOrder, int preStart, int preEnd, int inStart, int inEnd) {
    // 构建根节点
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preOrder[preStart];
    root->left = NULL; root->right = NULL;

    // 当前是叶子节点
    if (preStart == preEnd && inStart == inEnd && preOrder[preStart] == inOrder[inStart])
    {
        return root;
    }

    // 统计根节点在中序数组中的位置
    int inOrderIndex = 0;
    while(inOrderIndex <= inEnd && inOrder[inOrderIndex] != root->val) {
        inOrderIndex++;
    }

    int leftTreeSize = inOrderIndex - inStart;
    int rightTreeSize = inEnd - inOrderIndex;

    if (leftTreeSize > 0) {
        int preNewStart = preStart + 1;
        int preNewEnd = preNewStart + leftTreeSize - 1;
        int inNewStart = inStart;
        int inNewEnd = inOrderIndex - 1;
        root->left = createTree(preOrder, inOrder, preNewStart, preNewEnd, inNewStart, inNewEnd);
    }

    if (rightTreeSize > 0) {
        int preNewStart = preEnd - rightTreeSize + 1;
        int preNewEnd = preEnd;
        int inNewStart = inOrderIndex + 1;
        int inNewEnd = inEnd;
        root->right = createTree(preOrder, inOrder, preNewStart, preNewEnd, inNewStart, inNewEnd);
    }

    return root;
}

// 入参校验
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (!preorder || preorderSize <= 0 || !inorder || inorderSize <= 0) return NULL;
    if (preorderSize != inorderSize) return NULL;

    int preStart, inStart = 0;
    int preEnd = preorderSize - 1;
    int inEnd = inorderSize - 1;
    return createTree(preorder, inorder, preStart, preEnd, inStart, inEnd);
}


//leetcode submit region end(Prohibit modification and deletion)
