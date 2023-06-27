## PostOrder Traversal

Recursive Code for it: 

```cpp
class Tree{
    public:
    vector<int> postOrderTraversal(TreeNode* root) {
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
        dfs(root->right,list);
        list.push_back(root);
    }   
}
```