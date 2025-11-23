/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int m;
    vector<int> nex, s;
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        for (auto p = head; p; p = p->next)
            s.push_back(p->val);
        m = s.size();
        nex.resize(m + 1);
        for (int i = 1, j = 0; i < m; i++)
        {
            while (j > 0 && s[i] != s[j])
                j = nex[j];
            if (s[i] == s[j])
                j++;
            nex[i + 1] = j;
        }
        return find(root, 0);
    }
    bool find(TreeNode *root, int j)
    {
        if (j == m)
            return true;
        if (!root)
            return false;
        while (j > 0 && root->val != s[j])
            j = nex[j];
        if (root->val == s[j])
            j++;
        return find(root->left, j) || find(root->right, j);
    }
};