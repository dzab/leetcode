#include <queue>
#include <vector>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//用数组内容构造一棵complete binary tree
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
    return 0;
}
