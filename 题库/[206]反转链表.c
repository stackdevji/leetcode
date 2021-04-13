//反转一个单链表。 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL 
//
// 进阶: 
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？ 
// Related Topics 链表



//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if (!head) return NULL;
    if (!head->next) return head;

    struct ListNode* reverseHead = NULL;
    struct ListNode* preNode = NULL;
    struct ListNode* curNode = head;
    while(curNode) {
        struct ListNode* nextNode = curNode->next;
        if (!nextNode) reverseHead = curNode;
        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }
    return reverseHead;
}


//leetcode submit region end(Prohibit modification and deletion)
