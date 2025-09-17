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
class Solution {
public:
    ListNode* findKthNode(ListNode* head,int k){
        ListNode* temp=head;
        k=k-1;
        while(k>0 && temp!=nullptr){
            temp=temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head,*prevNode=nullptr,*nextNode=nullptr;
        while(temp!=nullptr ){
            ListNode* kthNode=findKthNode(temp,k);
            if(kthNode==nullptr){
                if(prevNode!=nullptr) prevNode->next=temp;
                break;
            }
            nextNode=kthNode->next;
            kthNode->next=nullptr;
            reverse(temp);
            if(temp==head) head=kthNode;
            else prevNode->next=kthNode;
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};