//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。 
//
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。 
//
// 说明：不允许修改给定的链表。 
//
// 
//
// 示例 1： 
//
// 输入：head = [3,2,0,-4], pos = 1
//输出：tail connects to node index 1
//解释：链表中有一个环，其尾部连接到第二个节点。
// 
//
// 
//
// 示例 2： 
//
// 输入：head = [1,2], pos = 0
//输出：tail connects to node index 0
//解释：链表中有一个环，其尾部连接到第一个节点。
// 
//
// 
//
// 示例 3： 
//
// 输入：head = [1], pos = -1
//输出：no cycle
//解释：链表中没有环。
// 
//
// 
//
// 
//
// 进阶： 
//你是否可以不用额外空间解决此题？ 
// Related Topics 链表 双指针

// 思想
// 先用双指针确定链表确实有环，如果两个指针相交的节点一定是环中节点 返回该节点
// 计算环中的个数：从返回相交节点开始移动，当指针再次回到相交节点 即能统计出环中节点的个数n
// 知道环中节点个数n之后，还是利用双指针，开始都指向头结点，一个节点先走n步，然后两个指针开始每次向前移动一个节点
// 直到后走的节点到环入口的时候，由于先走的节点比后走先走环中节点个数，所以必定重合在入口节点
// 返回该节点即可

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * 获取环中的节点
 * @param head
 * @return
 */
struct LisNode *hasCycle(struct ListNode *head) {
    if (!head) return NULL;
    struct ListNode* step_1 = head->next;
    if (!step_1) return NULL;

    struct ListNode* step_2 = step_1->next;
    while (step_2 && step_1) {
        if (step_2 == step_1) return step_1;
        step_1 = step_1->next;
        step_2 = step_2->next;
        if (step_2) step_2 = step_2->next;
    }
    return NULL;
}

struct ListNode *detectCycle(struct ListNode *head) {
    // 获取环中的相交节点
    struct ListNode* nodeInCycle = hasCycle(head);
    if (!nodeInCycle) return NULL;

    int cycleCnt = 1; // 当前节点本身
    struct ListNode* tmpNode = nodeInCycle->next;
    while (tmpNode != nodeInCycle) {
        tmpNode = tmpNode->next;
        ++cycleCnt;
    }

    struct ListNode* front = head;
    struct ListNode* behind = head;
    while (cycleCnt > 0) {
        front = front->next;
        --cycleCnt;
    }
    while(front != behind) {
        front = front->next;
        behind = behind->next;
    }
    return front;
}
//leetcode submit region end(Prohibit modification and deletion)
