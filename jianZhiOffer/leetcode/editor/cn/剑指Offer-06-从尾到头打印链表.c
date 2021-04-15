//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 
//
// 
//
// 示例 1： 
//
// 输入：head = [1,3,2]
//输出：[2,3,1] 
//
// 
//
// 限制： 
//
// 0 <= 链表长度 <= 10000 
// Related Topics 链表 
// 👍 135 👎 0

// returnSize是记录连表大小

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    if (!head) {
        *returnSize = 0;
        return NULL;
    }

    struct ListNode *newHead = NULL;
    struct ListNode *preNode = NULL;

    int i = 0;
    while (head != NULL)
    {
        // 计算连表长度
         i++;

         preNode = head;
         head = head->next;

         preNode->next = newHead;
         newHead = preNode;
    }
    *returnSize = i;

    int* res = (int*)malloc(sizeof(int) * i);
    if (res == NULL) {
        *returnSize = 0;
        return NULL;
    }

    i = 0;
    while(newHead != NULL)
    {
        printf("%d", newHead->val);
        res[i] = newHead->val;
        i++;
        newHead = newHead->next;
    }
    return res;
}
//leetcode submit region end(Prohibit modification and deletion)
