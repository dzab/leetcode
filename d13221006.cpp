//maximum-depth-of-binary-tree
#include <algorithm>
#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root)
{
    if (!root) return 0;
    int depth1 = 1;
    int depth2 = 1;
    if (root->left) { 
        depth1 = maxDepth(root->left)+1;
    }
    if (root->right) {
        depth2 = maxDepth(root->right)+1;
    }
    return std::max(depth1, depth2);
}

int main()
{
    TreeNode node[10] = { 1,2,3,4,5,6,7,8,9,10 };
    node[0].left = &node[1];
    node[0].right = &node[2];
    node[2].left = &node[3];
    node[2].right = &node[4];
    printf("%d\n", maxDepth(&node[0]));

    return 0;
}
