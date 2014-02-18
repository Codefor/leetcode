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
	ListNode* reverseList(ListNode *head){
	    if(head == NULL){
		return NULL;
	    }

	    ListNode *p = head;
	    head = NULL;

	    ListNode *q;
	    while(p != NULL){
		q = p->next;
		p->next = head;
		head = p;
		p = q;
	    }
	    return head;
	}

	//head<-head2
	//do not change head & head2
	void mergeList(ListNode *head,ListNode *head2){
	    display(head);
	    display(head2);

	    if(head == NULL){
		return;
	    }

	    ListNode *p = head;
	    ListNode *q = head2;

	    ListNode *s,*t;
	
	    while(p != NULL && q != NULL){
		s = p->next;
		t = q->next;
		q->next = p->next;
		p->next = q;

		q = t;

		if(s == NULL){
		    p = q;
		    break;
		}else{
		    p = s;
		}
	    }
	}


	void reorderList(ListNode *head) {
	    if(head == NULL){
		return;
	    }

	    //split list into 2 half-list and merge
	    int n = 0;

	    ListNode *p = head;
	    while(p != NULL){
		n++;
		p = p->next;
	    }

	    //skip (n+1)/2
	    p = head;
	    int c = 0;
	    while(c++ < (n-1)/2){
		p = p->next;
	    }

	    ListNode *q = p->next;
	    p->next = NULL;

	    ListNode *head2 = reverseList(q);

	    mergeList(head,head2);
	}

	void display(ListNode *head) {
	    ListNode *p = head;
	    while(p != NULL){
		cout<<p->val<<" ";
		p = p->next;
	    }
	    cout<<endl;
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
    //d.next = &e;
    //e.next = &f;

    Solution s;
    s.display(&a);
    s.reorderList(&a);
    s.display(&a);

    s.reorderList(NULL);
    return 0;
}
