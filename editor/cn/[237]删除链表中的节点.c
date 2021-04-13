//请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。 
//
// 现有一个链表 -- head = [4,5,1,9]，它可以表示为: 
//
// 
//
// 
//
// 示例 1: 
//
// 输入: head = [4,5,1,9], node = 5
//输出: [4,1,9]
//解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
// 
//
// 示例 2: 
//
// 输入: head = [4,5,1,9], node = 1
//输出: [4,5,9]
//解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
// 
//
// 
//
// 说明: 
//
// 
// 链表至少包含两个节点。 
// 链表中所有节点的值都是唯一的。 
// 给定的节点为非末尾节点并且一定是链表中的一个有效节点。 
// 不要从你的函数中返回任何结果。 
// 
// Related Topics 链表

// 思想：
// 1. 普通删除链表需要从头到尾遍历找到指定要删除的节点来删除 时间复杂度o(N)
// 2. o(1)的时间复杂度删除指定节点思想
//      要删除的节点为i,i的下一个节点为j ...->i->j-> ...
//      只需把j节点的值赋值给i,然后删除j节点，连接i->next = j->next即可
// 但是这种方法要考虑集中边界情况
//      a. 如果链表只有一个节点， 删除当前节点，要设置头结点为空避免野指针的出现
//      b. 如果要删除的节点是尾节点就需要 从头遍历到尾结点，然后删除尾结点即是我们要删除的前节点
// ps: leetcode上这道题的删除函数只给了一个要删除的节点，没有给链表的头结点就是想让我们通过
// o(1)时间复杂度删除链表节点，并且已经规避边界条件


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    free(nextNode);
    nextNode = NULL;
}
//leetcode submit region end(Prohibit modification and deletion)

// 给出没有规避边界条件的代码
void deleteNode(struct ListNode** head, struct ListNode* node) {
    if (head == NULL || *head == NULL) return;

    // 要删除的节点是尾结点
    if (node->next == NULL) {
        struct ListNode* curNode = *head;
        while (curNode->next != node) {
            curNode = curNode->next;
        }
        free(node);
        node = NULL;
        curNode->next = NULL;
    }
    // 当前链表只有一个节点
    else if (*head == node) {
        free(node);
        node = NULL;
        *head = NULL;
    }
    // 链表中有多个节点 并且当前节点不是尾节点 此处就是该leetcode的题解
    else {
        struct ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        free(nextNode);
        nextNode = NULL;
    }
}
