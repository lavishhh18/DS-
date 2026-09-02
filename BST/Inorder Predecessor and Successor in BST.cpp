/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pred = NULL;
        Node* succ = NULL;
        
        Node* curr = root;
        
        while(curr != NULL){
            if(curr->data < key){
                pred = curr;
                curr = curr ->right;
            }
            
            else if(curr->data > key) {
                succ = curr;
                curr = curr->left;
            }
            
            else {
                Node* temp = curr->left;
                while(temp != NULL){
                    pred = temp;
                    temp = temp ->right;
                }
                
                temp = curr->right;
                while(temp != NULL){
                    succ = temp;
                    temp = temp->left;
                }
                break;
            }
        }
        
        return {pred, succ};
    }
};