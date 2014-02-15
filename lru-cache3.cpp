#include<iostream>
#include<map>
#include<time.h>

using namespace std;

class LRUCache{
    private:
	int capacity;
	map<int,int> cache;
	map<int,long long> key2seq;
	map<long long,int> seq2key;
	long long index;

    public:   
	LRUCache(int _capacity) {
	    capacity = _capacity;
	    index = 0;
	}

	int get(int key) {
	    map<int,int>::iterator it;
	    it = cache.find(key);

	    if(it == cache.end()){
		return -1;
	    }else{
		seq2key.erase(key2seq[it->first]);

		key2seq[it->first] = index++;
		seq2key[key2seq[it->first]] = it->first;

		return it->second;
	    }
	}

	void set(int key, int value) {
	    //first check if the key already exists
	    //get will automatically update access sequence
	    if(get(key) == -1){
		key2seq[key] = index++;
		seq2key[key2seq[key]] = key;

		//check whether need to lru
		if(full()){
		    //lru
		    int key;
		    map<long long,int>::iterator it = seq2key.begin();
		    //erase
		    seq2key.erase(it->first);
		    key2seq.erase(it->second);
		    cache.erase(it->second);
		}
	    }
	    
	    cache[key] = value;
	}

	bool full(){
	    return cache.size() == capacity;
	}

	void display(){
	    cout<<"*****display("<<cache.size()<<")*******"<<endl;

	    map<long long,int>::iterator it;
	    for(it = seq2key.begin();it!=seq2key.end();it++){
		cout<<cache[it->second]<<endl;
	    }
	}

	void clear(){
	    cache.clear();
	    seq2key.clear();
	    key2seq.clear();
	    index = 0;
	}
};

int main(){
    LRUCache lru(2);
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

    lru.clear();
    cout<<lru.get(2)<<endl;
    lru.set(2,6);
    cout<<lru.get(1)<<endl;
    lru.set(1,5);
    lru.set(1,2);
    cout<<lru.get(1)<<endl;
    cout<<lru.get(2)<<endl;

    return 0;
}
