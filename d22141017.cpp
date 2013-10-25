#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
//binary-tree-inorder-traversal

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//recursive

void inorder(TreeNode *root, std::vector<int>& v) {
    if (NULL == root) return;
    if (root->left) inorder(root->left, v);
    v.push_back(root->val);
    if (root->right) inorder(root->right, v);
    return;
}
    
std::vector<int> inorderTraversal1(TreeNode *root) {
    std::vector<int> v;
    inorder(root, v);
    return v;
}

//iterate
std::vector<int> inorderTraversal2(TreeNode *root) {
    if (NULL == root) return std::vector<int>();
    std::stack<TreeNode *> *pST = new std::stack<TreeNode *>();
    std::vector<int> v;
    TreeNode *p = root;
    while (p || !(*pST).empty()) {
        if (p) {
            (*pST).push(p); p = p->left; 
        } else {
            p = (*pST).top();
            (*pST).pop();
            v.push_back(p->val);
            p = p->right;
        }
    }
    return v;
}

TreeNode *ConstructBST(std::vector<int> &num) {
    if (num.empty()) return NULL;
    int n = num.size();
    std::queue<TreeNode *> qu;
    TreeNode *pRoot = new TreeNode(num[0]);
    qu.push(pRoot);
    TreeNode *p;
    int idx = 0;
    while (!qu.empty()) {
        p = qu.front();
        qu.pop();
        if (++idx < n) {
            p->left = new TreeNode(num[idx]);
            qu.push(p->left);
        } else break;
        if (++idx < n) {
            p->right = new TreeNode(num[idx]);
            qu.push(p->right);
        } else break;
    }
    return pRoot;
}

void PrintTree(TreeNode *root)
{
    if (NULL == root) return;
    printf("%d,", root->val);
    if (root->left) PrintTree(root->left); else printf("#L,");
    if (root->right) PrintTree(root->right); else printf("#R,");
    return;
}

int main()
{
    std::vector<int> v;
    for (int i = 1; i <= 12; ++i) {
        v.push_back(i);
    }
    TreeNode *p = ConstructBST(v);
    PrintTree(p);
    printf("\n");
    std::vector<int> v2;
    v2 = inorderTraversal1(p);    
    for (int i = 0; i < v2.size(); ++i) {
        printf("%d ", v2[i]);
    }
    printf("\n");

    v2 = inorderTraversal2(p);
    for (int i = 0; i < v2.size(); ++i) {
        printf("%d ", v2[i]);
    }
    printf("\n");

    return 0;
}

