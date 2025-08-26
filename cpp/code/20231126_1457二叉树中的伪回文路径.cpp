#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

TreeNode *createTree(const vector<int> &nodes) {
    if (nodes.empty()) return nullptr;

    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode *> q;
    q.push(root);

    size_t i = 1;
    while (i < nodes.size()) {
        TreeNode *current = q.front();
        q.pop();

        if (nodes[i] != NULL) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != NULL) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void inorderTraversal(TreeNode *root) {

    // 深度优先
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

class Solution {
public:


    // 判断路径是否为伪回文
    int countPseudoPalindromic1(TreeNode *root, vector<int> &count) {
        // 该结点为空则返回0
        if (root == nullptr) return 0;

        // 值计数+1
        count[root->val]++;
        // 判定叶子结点
        if (root->left == nullptr && root->right == nullptr) {
            // 到达叶子节点时检查路径的伪回文性质
            int oddCount = 0; //记录伪路径数
            for (int i = 1; i <= 9; ++i) {
                if (count[i] % 2 != 0) { //存在奇数  233->323(1+0) yes 1232(1+0+1) no
                    oddCount++;
                }
            }
            count[root->val]--;//返还个数
            return oddCount <= 1 ? 1 : 0;//N个对数+1个单数
        }

        int leftCount = countPseudoPalindromic1(root->left, count);
        int rightCount = countPseudoPalindromic1(root->right, count);

        count[root->val]--;
        return leftCount + rightCount;
    }

    /*
     * 伪回文数：N个对数+1个单数

        采用vector给1-9的数字计数，定义变量count

        为叶子结点时，判断计数count的各个数字的计数是否满足条件

        然后递归
     */
    int pseudoPalindromicPaths1(TreeNode *root) {
        vector<int> count(10, 0); // 存储节点值的出现次数
        return countPseudoPalindromic1(root, count);
    }


    int countPseudoPalindromic2(TreeNode *root, int count[]) {
        // 该结点为空则返回0
        if (root == nullptr) return 0;

        // 值计数+1
        count[root->val]++;
        // 判定叶子结点
        if (root->left == nullptr && root->right == nullptr) {
            // 到达叶子节点时检查路径的伪回文性质
            int oddCount = 0; //记录伪路径数
            for (int i = 1; i <= 9; ++i) {
                if (count[i] % 2 != 0) { //存在奇数  233->323(1+0) yes 1232(1+0+1) no
                    oddCount++;
                }
            }
            count[root->val]--;//返还个数
            return oddCount <= 1 ? 1 : 0;//N个对数+1个单数
        }

        int leftCount = countPseudoPalindromic2(root->left, count);
        int rightCount = countPseudoPalindromic2(root->right, count);

        count[root->val]--;
        return leftCount + rightCount;
    }

    // 2. 代码优化有限，vector变为原生数组，基本没有太大效果
    int pseudoPalindromicPaths2(TreeNode *root) {
        int count[10] = {0};
        return countPseudoPalindromic2(root, count);
    }








    void judgement() {
        int oddCount = 0; //记录伪路径数
        for (int i = 1; i <= 9; ++i) { // N个对数+1个单数
            if (counts[i] % 2 != 0) { //==1 存在奇数且是3  233->323(1+0) yes 1232(1+0+1) no
                oddCount++; //记录单个数的个数
            }
        }
        res+= (oddCount <= 1) ? 1 : 0;//N个对数+1个单数
    }

    void countPseudoPalindromic(TreeNode *root) {

        // 空结点情况
        if (root == nullptr) return;

        // 叶子结点情况
        if (root->left == nullptr && root->right == nullptr) {
            counts[root->val]++; // 值计数+1
            judgement();
            counts[root->val]--;//返还个数
            return;
        }

        // 普通结点情况
        counts[root->val]++;
        countPseudoPalindromic(root->left);
        countPseudoPalindromic(root->right);
        counts[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root) {
        counts.resize(10);//修改大小
        countPseudoPalindromic(root);
        return res;
    }

private:
    vector<int> counts;
    int res=0;

};


int main1457() {
    Solution solution = *new Solution;
    vector<int> nodes = {2, 3, 1, 3, 1, NULL, 1};
    TreeNode *root = createTree(nodes);
    int res = solution.pseudoPalindromicPaths(root);
    cout << res << endl;
    return -1;
}
