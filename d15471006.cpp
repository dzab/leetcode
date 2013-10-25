#include <cstdio>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head) 
{
    if (NULL == head) return NULL;
    ListNode *pCurrent = head;
    ListNode *pNext;
    while (pCurrent->next) {
        pNext = pCurrent->next;
        if (pCurrent->val==pNext->val) {
            pCurrent->next = pNext->next;
            delete pNext;
        }
        else {
            pCurrent = pCurrent->next;
        }
    }
    return head;
}

void printList(ListNode *head)
{
    ListNode *p = head;
    while (p) {
        printf("%d,", p->val);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    static const int n = 12;
    int a[] = { 1,2,2,3,4,5, 6,6,6,7,8,8 };
    ListNode *pNode = new ListNode(a[0]);
    ListNode *pHead = pNode;
    for (int i = 1; i < n; ++i) {
        pNode->next = new ListNode(a[i]);
        pNode = pNode->next;
    } 
    printList(pHead);
    printList(deleteDuplicates(pHead));
    return 0;
}
