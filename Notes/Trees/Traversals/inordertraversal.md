## Inorder Traversal


 Order of Traversal: left->root->right
>Iterrative DFS
* For iterative dfs traversals we use stack as a data structure to store the nodes of the binary tree


 Iterative Code for it: 

```cpp
class Tree{
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> list;
        stack<TreeNode*>st;
        
        while(!st.empty() or root !=NULL){
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            list.push_back(root->val);
            root= root->right;
        }
        return list;
    }   
}
```
 Recursive Code for it: 

```cpp
class Tree{
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> list;
        dfs(root,list);
        return list;
    }

    private:
    void dfs(TreeNode* root, vector<int> list){
        if(root == NULL){
            return;
        }
        dfs(root->left,list);
        list.push_back(root);
        dfs(root->right,list);
    }   
}
```
