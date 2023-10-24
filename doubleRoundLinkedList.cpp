#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
};

class douLinkList{
    public:
    node* first;
    node* last;
};

node* initNode(int x){
    node* p = new node;
    (*p).data = x;
    (*p).next = NULL;
    (*p).prev = NULL;
    return p; 
}

douLinkList* initList(int x){
    douLinkList* l = new douLinkList;
    (*l).first = initNode(x);
    (*l).last = (*l).first;
    return l;
}

douLinkList* makeCircular(douLinkList* dll){
	(*(*dll).first).prev = (*dll).last;
	(*(*dll).last).next = (*dll).first;
	return dll;
}

int listSize(douLinkList* dll){
    int count = 0;
    node* p = (*dll).first;
    while(p != NULL){
        p = (*p).next;
        count++;
    }
    return count;
}

douLinkList* addFirst(douLinkList* dll, int x){
    node* p = initNode(x);
    (*p).next = (*dll).first;
    (*(*dll).first).prev = p;
    (*dll).first = p;
    return dll;
}

douLinkList* addLast(douLinkList* dll, int x){
    node* p = initNode(x);
    (*p).prev = (*dll).last;
    (*(*dll).last).next = p;
    (*dll).last = p;
    return dll;
}

douLinkList* addMiddle(douLinkList* dll, int k, int x){
    node* p = (*dll).first;
    for(int i = 1; i < k; i++)
        p = (*p).next;
    node* temp = (*p).next;
    node* newNode = initNode(x);
    (*p).next = newNode;
    (*newNode).prev = p;
    (*newNode).next = temp;
    (*temp).prev = newNode;
    return dll;
}

douLinkList* addAny(douLinkList* dll, int k, int x, int n){
    if(k == 0) dll = addFirst(dll, x);
    else if(k == n) dll = addLast(dll, x);
        else dll = addMiddle(dll, k, x);
    return dll;
}

void printList(douLinkList* dll){
    node* p = (*dll).first;
    while(p != NULL){
        cout << (*p).data << " ";
        p = (*p).next;
    }
}

int main(){
    int n, inp;
    cin >> n >> inp;
    douLinkList* dll = initList(inp);
    for(int i = 1; i < n; i++){
        cin >> inp;
        dll = addLast(dll, inp);
    }
    dll = makeCircular(dll);
    int k;
    cin >> k;
    
    node* p = (*dll).first;
    for(int i = 0; i < k; i++)
    	p = (*p).next;
    for(int i = 0; i < n; i++){
    	cout << (*p).data;
    	p = (*p).next;
	}	
    return 0;
}
