### PreOrder Traversal

>Iterative Preorder
 * Order of traversal : root->left->right

```cpp
class Tree {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> tree;
        if(root==NULL)return tree;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            tree.push_back(root->val);
            if(root->right != NULL)st.push(root->right);
            if(root->left != NULL)st.push(root->left);
        }
        
        return tree;
    }
};
```
Recursive Code for it: 

```cpp
class Tree{
    public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> list;
        dfs(root,list);
        return list;
    }

    private:
    void dfs(TreeNode* root, vector<int> list){
        if(root == NULL){
            return;
        }
        list.push_back(root);
        dfs(root->left,list);
        dfs(root->right,list);
    }   
}
```
