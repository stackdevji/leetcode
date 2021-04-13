//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。 
//
// 要求返回这个链表的深拷贝。 
//
// 
//
// 示例： 
//
// 
//
// 输入：
//{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
//
//解释：
//节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
//节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
// 
//
// 
//
// 提示： 
//
// 
// 你必须返回给定头的拷贝作为对克隆列表的引用。 
// 
// Related Topics 哈希表 链表



//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    /**
     * 克隆链表的每一个节点
     * eg: 1->1'->2->2'->3->3'  N'是N的clone节点
     * @param head
     * @return
     */
    void cloneRandomList(Node* head) {
        Node* node = head;
        while (node != NULL) {
            Node* clone = new Node(node->val, NULL, NULL);
            clone->next = node->next;

            node->next = clone;
            node = clone->next;
        }
        return;
    }

    /**
     * 连接克隆节点的随机指针
     * @param head
     */
    void connectRandomPos(Node* head) {
        Node* node = head;
        while(node) {
            // 当前节点的克隆节点
            Node* cloneNode = node->next;
            // 如果当前节点的随机指针不为空，那么克隆节点应该是当前节点随机指针指向节点的下一个节点
            if (node->random != NULL) {
                cloneNode->random = node->random->next;
            }
            // 当前节点进行移动
            node = cloneNode->next;
        }
        return;
    }

    /**
     * 拆分链表中原始节点和克隆节点
     * @param head
     * @return
     */
    Node* splitRandomList(Node* head) {
        Node* node = head;
        Node* cloneHead = NULL;
        Node* cloneNode = NULL;

        // 初始化克隆链表节点
        if (node != NULL) {
            cloneHead = cloneNode = node->next;
            node->next = cloneNode->next;
            node = node->next;
        }

        while (node) {
            cloneNode->next = node->next;
            cloneNode = cloneNode->next;

            node->next = cloneNode->next;
            node = node->next;
        }
        return cloneHead;
    }

    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        this->cloneRandomList(head);
        this->connectRandomPos(head);
        Node* copyHead = this->splitRandomList(head);
        return copyHead;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
