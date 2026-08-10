class Solution {
  public:
    Node* merge(Node* node1, Node* node2){
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        
        while(node1 != NULL && node2 != NULL){
            if(node1->data < node2->data){
                temp->bottom = node1;
                temp = temp->bottom;
                node1 = node1->bottom;
            }
            else{
                temp->bottom = node2;
                temp = temp->bottom;
                node2 = node2->bottom;
            }
            temp->bottom = NULL;
        }
        
        if(node1) temp->bottom = node1;
        if(node2) temp->bottom = node2;
        
        return dummyNode->bottom;
    }
    
    Node* flatten(Node* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node* newHead = flatten(head->next);
        Node* mergedHead = merge(head, newHead);
        
        return mergedHead;
    }
};