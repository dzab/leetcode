#include <cstdio>
#include <queue>
//symmetric-tree
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode *pLeft, TreeNode *pRight)
{
    if (NULL == pLeft && NULL == pRight) 
        return true;
    if (NULL == pLeft || NULL == pRight) {
        return false;
    }
    if (pLeft->val != pRight->val) 
        return false;
    if (isSymmetric(pLeft->left, pRight->right) &&
        isSymmetric(pRight->left, pLeft->right))
        return true;
}

bool isSymmetric(TreeNode *root)
{
    if (NULL == root) return true;
    return isSymmetric(root->left, root->right);
}

bool isSymmetric2(TreeNode *root)
{
    if (root == NULL) return true;
    queue<TreeNode *> lf, rt;
    lf.push(root->left);
    rt.push(root->right);
    TreeNode *l, *r;
    while (!lf.empty() && !rt.empty()) {
        l = lf.front(); r = rt.front();
        lf.pop(); rt.pop();
        if (l == NULL && r == NULL) continue;
        if (l == NULL || r == NULL) return false;
        if (l->val != r->val) return false;
        lf.push(l->left); lf.push(l->right);
        rt.push(r->right); rt.push(r->left);
    }
    if (lf.empty() && rt.empty()) return true;
    else return false;
}
    

int main()
{
}
