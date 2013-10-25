#include <queue>
#include <vector>
//binary-tree-level-order-traversal
using std::vector;
using std::queue;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > vv;

//recursive approach
void PrintNodes(TreeNode *root, int level)
{
    if (!root) return;
    if (level+1 > vv.size()) 
        vv.push_back(vector<int>()); 
    vv[level].push_back(root->val);
    PrintNodes(root->left, level+1);
    PrintNodes(root->right, level+1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    vv.clear();
    PrintNodes(root, 0);
    return vv;
}

//putting null into queue to indicate level
vector<vector<int> > levelOrder2(TreeNode *root) {
    vv.clear();
    if (!root) return vv;
    vv.push_back(vector<int>());
    std::queue<TreeNode *> qu;
    qu.push(root);
    qu.push(NULL);
    while (!qu.empty()) {
        TreeNode *p = qu.front();
        qu.pop();
        if (!p) {
            if (!qu.empty()) {
                qu.push(NULL);
                vv.insert(vv.begin(), vector<int>());
            }
        } else {
            vv[0].push_back(p->val);
            if (p->left) qu.push(p->left);
            if (p->right) qu.push(p->right); 
        }
    }
    return vv;
}

//use two queues, current level, next level
/*
void printLevelOrder(BinaryTree *root) {
    if (!root) return;
    queue<BinaryTree*> currentLevel, nextLevel;
    currentLevel.push(root);
    while (!currentLevel.empty()) {
        BinaryTree *currNode = currentLevel.front();
        currentLevel.pop();
        if (currNode) {
            cout << currNode->data << " ";
            nextLevel.push(currNode->left);
            nextLevel.push(currNode->right);
        }
        if (currentLevel.empty()) {
            cout << endl;
            swap(currentLevel, nextLevel);
        }
    }
}
*/


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
    levelOrder2(p);
    for (int i = 0; i < vv.size(); ++i)  {
        printf("[");
        for (int j = 0; j < vv[i].size(); ++j) 
            printf("%d ", vv[i][j]);
        printf("]\n");
    }
    return 0;
}
