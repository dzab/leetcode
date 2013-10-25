#include <cstdio>
#include <vector>
//swap-nodes-in-pairs

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void SwapNextTwo(ListNode *pNode) {
    ListNode *pTemp = pNode->next;
    pNode->next = pTemp->next;
    pTemp->next = pTemp->next->next;
    pNode->next->next = pTemp;
}

//iterate // not good
ListNode *swapPairs1(ListNode *head) {
    if (NULL == head || NULL == head->next) return head;
    //swap first two
    ListNode *p = head->next; 
    head->next = p->next;
    p->next = head;
    head = p;
    p = p->next;
    while (NULL != p->next && NULL != p->next->next) {
        printf("+%d %d\n", p->next->val, p->next->next->val);
        SwapNextTwo(p);
        p = p->next->next;
    }
    printf("done\n");
    return head;
}

//recursive approach
ListNode *swapPairs2(ListNode *head) {
    if (NULL == head || NULL == head->next) return head;
    ListNode *p = swapPairs2(head->next->next);
    head->next->next = head;
    head = head->next;
    head->next->next = p;
    return head;
}
//use dummy head
ListNode *swapPairs3(ListNode *head) {
    //if (NULL == head || NULL == head->next) return head;
    ListNode *pDummy = new ListNode(-1);
    pDummy->next = head;
    ListNode *p = pDummy;
    while (NULL != p && NULL != p->next) {
        SwapNextTwo(p);
        p = p->next->next;
    }
    return pDummy->next;
}
//without dummy head
ListNode *swapPairs4(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *pPrev = NULL;
    ListNode *pCurr = head;
    ListNode *pNext = pCurr->next;
    while (pCurr && (pNext = pCurr->next)) {
        if (pPrev) pPrev->next = pNext; else head = pNext;
        pCurr->next = pNext->next;
        pNext->next = pCurr;
        pPrev = pCurr;
        pCurr = pCurr->next;
    }
    return head;
}

void PrintSList(ListNode *pHead)
{
    while (pHead) {
        printf("%d ", pHead->val);
        pHead = pHead->next;
    }
}

int main()
{
    int n = 12;
    ListNode *p = new ListNode(0);
    ListNode *pHead = p;
    for (int i = 1; i < n; ++i) {
        p->next = new ListNode(i);
        p = p->next;
    }
    PrintSList(swapPairs4(pHead));
    return 0;
}
