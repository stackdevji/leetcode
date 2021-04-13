//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。 
//
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。 
//
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 示例： 
//
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出：7 -> 0 -> 8
// 原因：342 + 465 = 807
// 
// Related Topics 链表 数学
// 思想考察的是链表的操作
// 需要注意如下几点：
// 1. 每位数相加可能会产生进位
// 2. 两个链表长度可能不相等，链表移动需要考虑会不会报错
// 3. 循环条件要判断节点不为空，而不是节点的前进指针不为空
// 4. 循环不能只判断两个链表是否结束，当链表结束之后产生进位，是否还需要在执行申请节点


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
        int x,y,carry = 0;
        int sum,units = 0;
        struct ListNode *result = NULL;
        struct ListNode *currentNode = NULL;
        while(l1 != NULL || l2 != NULL || carry > 0)
        {
            x = (l1 != NULL) ? l1->val : 0;
            y = (l2 != NULL) ? l2->val : 0;
            sum = x + y + carry;
            carry = sum / 10;
            units = sum % 10;

            struct ListNode *Node = (struct ListNode *)malloc(sizeof(struct ListNode));
            Node->val = units;
            Node->next = NULL;
            if(result == NULL)
            {
                result = Node;
                currentNode = Node;
            }
            else
            {
                currentNode->next = Node;
                currentNode = Node;
            }
            l1 = (l1 != NULL) ? l1->next : NULL;
            l2 = (l2 != NULL) ? l2->next : NULL;
        }
        return result;
}


//leetcode submit region end(Prohibit modification and deletion)
