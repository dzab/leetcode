#include <cstdio>
//populating-next-right-pointers-in-each-node

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root)
{
    TreeLinkNode *p = root;
    TreeLinkNode *pMostLeft = p;
    TreeLinkNode *pCurL;
    TreeLinkNode *pCurR;
    while (pMostLeft) {
        p = pMostLeft;
        printf("level:%d\n", pMostLeft->val);
        pCurR = NULL;
        do {
            printf("p=%d ", p->val);
            pCurL = p->left;
            if (pCurR) pCurR->next = pCurL;
            pCurR = p->right;
            if (pCurL) pCurL->next = pCurR;
            p = p->next;
        }while(p);
        printf("\n");
        pMostLeft = pMostLeft->left;
    }
}

void printTree(TreeLinkNode *root)
{
    TreeLinkNode *p = root;
    if (p) {
        printf("node[%d]->next=%d\n", p->val, (p->next)? p->next->val : 0);
        printTree(p->left);
        printTree(p->right);
    }
}

int main()
{
    TreeLinkNode *p = new TreeLinkNode(1);
    p->left = new TreeLinkNode(2);
    TreeLinkNode *pL = p->left;
    pL->left = new TreeLinkNode(4);
    pL->right = new TreeLinkNode(5);

    p->right = new TreeLinkNode(3);
    TreeLinkNode *pR = p->right;
    pR->left = new TreeLinkNode(6);
    pR->right = new TreeLinkNode(7);

    connect(p);
    printf("\n--------------\n");
    printTree(p);

    return 0;
}
