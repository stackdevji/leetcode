//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构) 
//
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。 
//
// 例如: 
//给定的树 A: 
//
// 3 
// / \ 
// 4 5 
// / \ 
// 1 2 
//给定的树 B： 
//
// 4 
// / 
// 1 
//返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。 
//
// 示例 1： 
//
// 输入：A = [1,2,3], B = [3,1]
//输出：false
// 
//
// 示例 2： 
//
// 输入：A = [3,4,5,1,2], B = [4,1]
//输出：true 
//
// 限制： 
//
// 0 <= 节点个数 <= 10000 
// Related Topics 树 
// 👍 258 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 根节点一样就要判断AB以根节点开始的所有节点是否一样，不一样则为false
bool hasEqualRoot(struct TreeNode* A, struct TreeNode* B) {
    if (B == NULL) return true;

    if (A == NULL) return false;

    if (A->val != B->val) {
        return false;
    }

    return hasEqualRoot(A->left, B->left) && hasEqualRoot(A->right, B->right);
}

// 第一层递归：前序遍历思想 判断AB根节点是否一样（一样则判断AB根节点延续的左右节点是否一样）
// 不一样则分别判断左子树和右子树
bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    bool res = false;

    if (A != NULL && B != NULL) {
        // 根节点相同，则直接从根节点判断
        if (A->val == B->val) {
            res = hasEqualRoot(A, B);
        }

        // 根节点值不同，对应比较左子树
        if (!res) {
            res = isSubStructure(A->left, B);
        }

        // 对应比较右子树
        if (!res) {
            res = isSubStructure(A->right, B);
        }
    }

    return res;
}


//leetcode submit region end(Prohibit modification and deletion)
