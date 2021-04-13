//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。 
//
// 如果有两个中间结点，则返回第二个中间结点。 
//
// 
//
// 示例 1： 
//
// 输入：[1,2,3,4,5]
//输出：此列表中的结点 3 (序列化形式：[3,4,5])
//返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
//注意，我们返回了一个 ListNode 类型的对象 ans，这样：
//ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
// 
//
// 示例 2： 
//
// 输入：[1,2,3,4,5,6]
//输出：此列表中的结点 4 (序列化形式：[4,5,6])
//由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
// 
//
// 
//
// 提示： 
//
// 
// 给定链表的结点数介于 1 和 100 之间。 
// 
// Related Topics 链表

// 思想： 双指针 一个指针每次走一步 一个指针每次走2不
//      1. 链表节点个数为偶数: 走的快的指针会走到倒数第二个节点 走的慢的指针会走到中间两个节点的前一个
//      2. 链表节点个数为奇数: 走的快的指针走到最后一个节点，走的慢的指针会走到中间的一个节点



//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    if (!head) return NULL;
    struct ListNode* step_1 = head;
    struct ListNode* step_2 = head;
    while (step_2 && step_2->next) {
        step_1 = step_1->next;
        step_2 = step_2->next->next;
    }
    return step_1;
}


//leetcode submit region end(Prohibit modification and deletion)
