## Level Order Traversal


> In level Order Traversal we basically store the nodes of each of the level together . 
> It is a bfs algorithm
```cpp
class Solution {    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>  ans ;
       if(root == NULL) return ans ;
        queue<TreeNode*> q ;
      
        q.push(root) ;
       
        while(!q.empty()){
          int size = q.size() ;
          vector<int>  res ;
          
          for(int i = 0 ; i < size ; i++){
            auto top = q.front();
            q.pop();
            if(top->left != NULL) q.push(top->left);
            if(top->right != NULL) q.push(top->right);
            res.push_back(top->val) ;
          }
            ans.push_back(res); 
        }
        return ans ;
    }
};
```