//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。 
//
// 示例1： 
//
// 输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4 
//
// 限制： 
//
// 0 <= 链表长度 <= 1000 
//
// 注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/ 
// Related Topics 分治算法 
// 👍 115 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL && l2 != NULL) return l2;
    if (l1 != NULL && l2 == NULL) return l1;

    struct ListNode* head = NULL;
    struct ListNode* node = NULL;
    struct ListNode* tmpNode = NULL;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tmpNode = l1;
            l1 = l1->next;
        } else {
            tmpNode = l2;
            l2 = l2->next;
        }

        if (head == NULL) {
            head = node = tmpNode;
        } else {
            node->next = tmpNode;
            node = tmpNode;
        }
    }

    // 判断l1或者l2是否有剩余节点
    if (l1 != NULL) {
        node->next = l1;
    }

    if (l2 != NULL) {
        node->next = l2;
    }

    return head;
}


//leetcode submit region end(Prohibit modification and deletion)
