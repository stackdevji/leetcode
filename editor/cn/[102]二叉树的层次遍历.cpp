//给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。 
//
// 例如: 
//给定二叉树: [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其层次遍历结果： 
//
// [
//  [3],
//  [9,20],
//  [15,7]
//]
// 
// Related Topics 树 广度优先搜索



//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        std::deque<TreeNode* root> treeNodeQueue;
        treeNodeQueue.push(root);
        int currentToPrint = 1;
        int nextLevelNodeCnt = 0;
        while(!treeNodeQueue.empty()) {
            TreeNode* node = treeNodeQueue.front();

            // 将node->val存入结果数组 todo


            if (node->left != NULL) {
                treeNodeQueue.push(root->left);
                nextLevelNodeCnt++;
            }
            if (node->right != NULL) {
                treeNodeQueue.push(root->right);
                nextLevelNodeCnt++;
            }
            // 将当前元素出队
            treeNodeQueue.pop();
            // 当前要打印节点减一；
            currentToPrint--;
            //
            if (currentToPrint == 0) {
                // 当前层数节点并保存完毕记录下一层要打印的节点
                currentToPrint = nextLevelNodeCnt;
                // 从0开始从新计数
                nextLevelNodeCnt = 0;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
