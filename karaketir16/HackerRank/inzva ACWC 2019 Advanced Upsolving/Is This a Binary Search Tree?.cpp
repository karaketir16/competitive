/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
bool result = true;
pair<int,int> fonk(Node* root) // min,max
{
        if(root->left&&fonk(root->left).second>=root->data) result = false;
        if(root->right&&fonk(root->right).first<=root->data) result = false;
        
        return make_pair(
        	min3((root->left)? 
        		fonk(root->left).first : (int)1e5, (root->right) ? fonk(root->right).first : (int)1e5 , root->data) , 
        	max3((root->left)?
        		fonk(root->left).second : -1, (root->left)?fonk(root->right).second : -1, root->data)
        	);
}
    bool checkBST(Node* root) {
        if(!root) return 0;
        fonk(root);
        return result;
    }