#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

node* initNode(int x){
    node* res = new node;
    (*res).data = x;
    (*res).next = NULL;
    return res;
}

node* addNode(node* last, int x){
    node* res = initNode(x);
    (*last).next = res;
    return res;
}

void printList(node* head){
    node* p = head;
    while(p != NULL){
        cout << (*p).data << " ";
        p = (*p).next;
    }
}

int listSize(node* head){
	int count = 0;
	node* p = head;
	while(p != NULL){
		p = (*p).next;
		count++;
	}
	return count;
}

node* addFirst(node* head, int x){
    node* res = initNode(x);
    (*res).next = head;
    return res;
}

node* addLast(node* head, int x){
    node* p = head;
    while((*p).next != NULL)
        p = (*p).next;
    node* res = addNode(p, x);
    return head;
}

node* addMiddle(node* head, int k, int x){
    node* p = head;
    for(int i = 0; i < k - 1; i++){
        p = (*p).next;
    }
    node* temp = initNode(x);
    (*temp).next = (*p).next;
    (*p).next = temp;
    return head;
}

node* eraseFirst(node* head){
	node* temp = (*head).next;
	delete(head);
    return temp;
}

node* eraseLast(node* head){
    node* p = head;
    node* temp;
    while((*(*p).next).next != NULL){
    	p = (*p).next;
	}
	delete( (*p).next );
	(*p).next = NULL;
	return head;
}

node* eraseMiddle(node* head, int k){
	node* p = head;
	for(int i = 0; i < k - 1; i++){
		p = (*p).next;
	}
	node* temp = (*(*p).next).next;
	delete( (*p).next );
	(*p).next = temp;
	return head;
}

node* eraseAny(node* head, int k, int n){
	if(k == 0) return eraseFirst(head);
	else if(k == n - 1) return eraseLast(head);
	else return eraseMiddle(head, k);
}

node* atIndex(node* head, int k){
	node* p = head;
	for(int i = 0; i < k; i++)
		p = (*p).next;
	return p;
}

//node* morph(node* head, int a, int b){
//	node* p = head;
//	while(p != NULL){
//		if((*p).data == a)
//			(*p).data = b;
//		p = (*p).next;
//	}
//	return head;
//}

//node* delLarger(node* head, int k, int n){
//	node* p = atIndex(head, k);
//	const int val = (*p).data;
//	p = head;
//	int count = 0;
//	while(p != NULL){
//		if((*p).data > val){
//			p = (*p).next;
//			head = eraseAny(head, count, listSize(head));
//			continue;
//		}
//		p = (*p).next;
//		count++;
//	}
//	return head;
//}

int main(){
    int n, inp;
    cin >> n >> inp;
    node* linkedList = initNode(inp);
    node* ptr = linkedList;
    for(int i = 1; i < n; i++){
        cin >> inp;
        ptr = addNode(ptr, inp);
    }
//    cout << listSize(linkedList);
    int k;
    cin >> k;
    linkedList = delLarger(linkedList, k, n);
//	linkedList = eraseAny(linkedList, k, n);
//	cout << endl << listSize(linkedList);
//	linkedList = eraseAny(linkedList, k + 1, n);
//	cout << endl << listSize(linkedList);
    printList(linkedList);
    return 0;
}
