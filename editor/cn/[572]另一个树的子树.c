//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。 
//
// 示例 1: 
//给定的树 s: 
//
// 
//     3
//    / \
//   4   5
//  / \
// 1   2
// 
//
// 给定的树 t： 
//
// 
//   4 
//  / \
// 1   2
// 
//
// 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。 
//
// 示例 2: 
//给定的树 s： 
//
// 
//     3
//    / \
//   4   5
//  / \
// 1   2
//    /
//   0
// 
//
// 给定的树 t： 
//
// 
//   4
//  / \
// 1   2
// 
//
// 返回 false。 
// Related Topics 树

// 该题和剑指offer26题相似，但是剑指offer上是只要判断完子树的所有节点就行，这里还需要判断子树的叶子节点的空指针
bool isTreeSHaveTreeTFromJZOffer(struct TreeNode* s, struct TreeNode* t) {
    if (!t) return true;
    if (!s) return false;
    if (s->val != t->val) return false;
    return isTreeSHaveTreeT(s->left, t->left) && isTreeSHaveTreeT(s->right, t->right);
}


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isTreeSHaveTreeT(struct TreeNode* s, struct TreeNode* t) {
    if (t == NULL && s == NULL) return true;
    if (t != NULL && s == NULL) return false;
    if (s != NULL && t == NULL) return false;
    if (s->val != t->val) return false;
    return isTreeSHaveTreeT(s->left, t->left) && isTreeSHaveTreeT(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    bool flag = false;
    if (s && t) {
        // 如果在目标树中找出和子树根节点一样的值，如果相等去判断根节点开始
        // 左子树和右子树的每个节点是否相等
        if (s->val == t->val) flag = isTreeSHaveTreeT(s, t);
        if (!flag) flag = isSubtree(s->left, t);
        if (!flag) flag = isSubtree(s->right, t);
    }
    return flag;
}


//leetcode submit region end(Prohibit modification and deletion)
