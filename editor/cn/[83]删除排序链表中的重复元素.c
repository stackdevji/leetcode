//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。 
//
// 示例 1: 
//
// 输入: 1->1->2
//输出: 1->2
// 
//
// 示例 2: 
//
// 输入: 1->1->2->3->3
//输出: 1->2->3 
// Related Topics 链表



//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head) return NULL;
    struct ListNode* node = head;
    while (node) {
        bool needDelNode = false;
        struct ListNode* nextNode = node->next;
        if (nextNode && nextNode->val == node->val) needDelNode = true;
        if (needDelNode) {
            int val = node->val;
            // 要保留一个重复节点，从下一个节点删除
            struct ListNode* delNode = nextNode;
            while (delNode && delNode->val == val) {
                // 记录要删除节点的下一个节点
                nextNode = delNode->next;
                // 删除节点
                free(delNode);
                delNode = NULL;
                // 判断下一个节点是否重复
                delNode = nextNode;
            }
            // 保持每个节点项链
            node->next = nextNode;
        }
        // 移动节点
        node = nextNode;
    }
    return head;
}


//leetcode submit region end(Prohibit modification and deletion)
