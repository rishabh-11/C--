/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        Node* prev=NULL;
        Node* temp3 = NULL;
        Node* head1=head;
        vector<Node*> v1,v2;
        while(head!=NULL)
        {
            Node* temp2= new Node(head->val);
            Node* temp5 = head1;
            Node* temp4 = temp3;
            while(temp4!=NULL)
            {
                if(temp5->random==head)
                {
                    temp4->random=temp2;
                }
                temp5 = temp5->next;
                temp4 = temp4->next;
            }
            v2.push_back(temp2);
            v1.push_back(head);
            for(int i=0;i<v1.size();i++)
            {
                if(v1[i]==head->random)
                {
                    temp2->random=v2[i];
                    break;
                }
            }
            if(prev!=NULL)
                prev->next=temp2;
            else
                temp3=temp2;
            prev=temp2;
            head = head->next;   
        }
        return temp3;
    }
};