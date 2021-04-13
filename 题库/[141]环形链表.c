//给定一个链表，判断链表中是否有环。 
//
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。 
//
// 
//
// 示例 1： 
//
// 输入：head = [3,2,0,-4], pos = 1
//输出：true
//解释：链表中有一个环，其尾部连接到第二个节点。
// 
//
// 
//
// 示例 2： 
//
// 输入：head = [1,2], pos = 0
//输出：true
//解释：链表中有一个环，其尾部连接到第一个节点。
// 
//
// 
//
// 示例 3： 
//
// 输入：head = [1], pos = -1
//输出：false
//解释：链表中没有环。
// 
//
// 
//
// 
//
// 进阶： 
//
// 你能用 O(1)（即，常量）内存解决此问题吗？ 
// Related Topics 链表 双指针

// 思想:
// 双指针：一个指针step_1走一步  一个指针step_2走2步
// 如果链表有环，那么step_2最终会追上step_1指针，两个指针相遇
// 如果step_2->next都为空了 还没有追上step_1说明链表没有环

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head) return false;

    struct ListNode* step_1 = head->next;
    if (!step_1) return false; // 一个节点
    struct ListNode* step_2 = step_1->next;
    while (step_2 && step_1) {
        if (step_1 == step_2) return true;
        step_1 = step_1->next;
        step_2 = step_2->next;
        if (step_2) {
            step_2 = step_2->next;
        }
    }
    return false;
}

//leetcode submit region end(Prohibit modification and deletion)
