//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。 
//
// 示例 1: 
//
// 输入: 1->2->3->3->4->4->5
//输出: 1->2->5
// 
//
// 示例 2: 
//
// 输入: 1->1->1->2->3
//输出: 2->3 
// Related Topics 链表

// 由于要删除所有的重复节点，如果第一个节点就开始重复，需要移动head到不重复的节点
// 如果是中间开始，比如node(当前节点开始)出现重复节点，当前节点也会被删除，所以需要记住node节点的前一个节点
// preNode = NULL 如果删除完发现开始空 说明链表第一个节点就重复，直接移动head
// 删除完如果preNode不为空直接连接

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

    struct ListNode* preNode = NULL;
    struct ListNode* node = head;
    while (node != NULL) {
        bool needDelete = false;
        struct ListNode* nextNode = node->next;
        if (nextNode != NULL && node->val == nextNode->val)  needDelete = true;
        if (!needDelete) {
            // 记录当前节点之后，当前节点移动到下一个节点
            preNode = node;
        } else {
            // 不留重复节点，从当前节点开始删除
            int val = node->val;
            struct ListNode* delNode = node;
            while (delNode != NULL && delNode->val == val) {
                nextNode = delNode->next;
                // 删除当前节点
                free(delNode);
                delNode = NULL;
                // delNode移动到下一个节点继续比较
                delNode = nextNode;
            }
            if (preNode != NULL) preNode->next = nextNode; // 前一个节点不为空说明删除中间节点，需要连接
            else head = nextNode;
        }
        // 当前节点移动到下一个节点
        node = nextNode;
    }
    return head;
}


//leetcode submit region end(Prohibit modification and deletion)
