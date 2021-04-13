//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 示例： 
//
// 输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
// 
// Related Topics 链表

// 递归实现


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (!l1) return l2;
    if (!l2) return l1;

    struct ListNode *head = NULL;
    if (l1->val <= l2->val) {
        head = l1;
        head->next = mergeTwoLists(l1->next, l2);
    } else {
        head = l2;
        head->next = mergeTwoLists(l1, l2->next);
    }
    return head;
}


//leetcode submit region end(Prohibit modification and deletion)
