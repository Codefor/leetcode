#include<iostream>
#include<vector>

using namespace std;

//Definition for singly-linked list.

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
    public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }

        ListNode* p = head;
        ListNode* q = head;
        while(p != NULL && q != NULL){
            //a circle's never to be NULL
            if(p->next == NULL){
                return false;
            }

            if(q->next == NULL){
                return false;
            }
            
            p = p->next;
            q = q->next->next;

            if(p == q){
                return true;
            }
        }
        return false;
    }
};

int main(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &b;
    //d.next = &e;
    //e.next = &f;

    Solution s;
    cout<<s.hasCycle(&a)<<endl;
    d.next = &d;
    cout<<s.hasCycle(&a)<<endl;
    d.next = &c;
    cout<<s.hasCycle(&a)<<endl;
    d.next = &a;
    cout<<s.hasCycle(&a)<<endl;
    return 0;
}
