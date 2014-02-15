#include<iostream>
#include<map>

using namespace std;

struct Node{
    int key;
    int val;
    struct Node *next;
    struct Node *pre;
};

class LRUCache{
    private:
	int capacity;
	map<int,Node*> cache;
	//the access sequence,from oldest to newest
	struct Node *head;//use to invalidate 
	struct Node *tail;//use to append or move to

    public:   
	LRUCache(int _capacity) {
	    capacity = _capacity;
	    head = NULL;
	    tail = NULL;
	}

	int get(int key) {
	    map<int,Node*>::iterator it;
	    it = cache.find(key);

	    if(it == cache.end()){
		return -1;
	    }else{
		//update access sequence
		//p != NULL && tail != NULL
		struct Node *p = it->second;

		if(p != tail){
		    //extract p,p->next != NULL
		    if(p->pre != NULL){
			p->pre->next = p->next;
		    }

		    p->next->pre = p->pre;

		    //move Node to tail
		    tail->next = p;
		    p->pre = tail;
		    p->next = NULL;

		    tail = p;
		}

		return p->val;
	    }
	}

	void set(int key, int value) {
	    //first check whether need to lru
	    if(cache.size() >= capacity){
		//lru
		if(head != NULL){
		    struct Node *p = head;
		    head = head->next;

		    if(tail == p){
			tail = NULL;
		    }

		    p->pre = NULL;
		    p->next = NULL;

		    cache.erase(p->key);
		    free(p);

		}
	    }

	    //check if the key already exists
	    if(get(key) != -1){
		//get will automatically update access sequence
		cache[key]->val = value;	
	    }else{
		struct Node *p = (Node*)calloc(1,sizeof(Node));
		p->key = key;
		p->val = value;

		if(tail != NULL){
		    tail->next = p;
		    p->pre = tail;
		    tail = p;
		}else{
		    //the first insert
		    tail = p;
		    head = tail;
		}

		cache[key] = p;
	    }
	}

	void display(){
	    cout<<"*****display("<<cache.size()<<")*******"<<endl;
	    struct Node *p = head;
	    while(p != NULL){
		cout<<p->val<<endl;
		p = p->next;
	    }
	}
};

int main(){
    LRUCache lru(3);
    lru.display();

    lru.set(1,1);
    lru.set(2,2);
    lru.set(3,3);
    lru.get(2);
    lru.display();

    lru.set(4,4);
    lru.display();
    lru.set(5,5);
    lru.display();
    lru.set(1,100);
    lru.display();

    return 0;
}
