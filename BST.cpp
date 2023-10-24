#include<bits/stdc++.h>
using namespace std;

struct nodeBST{
    int data;
    nodeBST* left;
    nodeBST* right;
};

nodeBST* initNode(int value){
    nodeBST* newNode = new nodeBST;
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

nodeBST* insertNode(nodeBST* root, int value){
    if(root == NULL){
        root = initNode(value); 
        return root;
    }
    if(value < root -> data)
        root -> left = insertNode(root -> left, value);
    else
        root -> right = insertNode(root -> right, value);
//    return root;
}

int height(nodeBST* root){
    if(root == NULL) return -1;
    if(root -> left == NULL && root -> right == NULL) return 0;
    return 1 + max(height(root -> left), height(root -> right));
}

void printInOrder(nodeBST* root){
    if(root != NULL){
        printInOrder(root -> left);
        cout << root -> data << " ";
        printInOrder(root -> right);
    }
}

int countLeaves(nodeBST* root){
    if(root == NULL) return 0;
    if(root -> left == NULL && root -> right == NULL) return 1;
    return countLeaves(root -> left) + countLeaves(root -> right);
}

int getMinValue(nodeBST* root){
	if(root -> left != NULL)
		return getMinValue(root -> left);
	else return root -> data;
}

int getMaxValue(nodeBST* root){
	if(root -> right != NULL)
		return getMaxValue(root -> right);
	else return root -> data;
}

bool checkBST(nodeBST* root){
	if(root == NULL) return 1;
	if(root -> left != NULL && root -> data < getMaxValue(root -> left)) return 0;
	if(root -> right != NULL && root -> data > getMinValue(root -> right)) return 0;
	if(!checkBST(root -> left) || !checkBST(root -> right)) return 0;
	return 1;
	
}

bool checkAVL(nodeBST* root){
    if(root == NULL) return 1;
    if(abs(height(root -> left) - height(root -> right)) > 1) return 0;
    return checkAVL(root -> left) && checkAVL(root -> right);
}

nodeBST* findMinNode(nodeBST* root){
	if(root -> left != NULL)
		return findMinNode(root -> left);
	else return root;
}

nodeBST* deleteNode(nodeBST* root, int value){
	if(root == NULL) return root;
	else if(root -> data < value) root -> right = deleteNode(root -> right, value);
	else if(root -> data > value) root -> left = deleteNode(root -> left, value);
	else{
		//case 1: leaf node
		if(root -> left == NULL && root -> right == NULL){
			delete root;
			root = NULL;
		}
		//case 2: 1 child
		else if(root -> left != NULL){
			nodeBST* temp = root;
			root = root -> left;
			delete temp;
		}
		else if(root -> right != NULL){
			nodeBST* temp = root;
			root = root -> right;
			delete temp;
		}
		//case 3: 2 child
		else{
			nodeBST* temp = findMinNode(root -> right);
			root -> data = temp -> data;
			root -> right = deleteNode(root -> right, temp -> data);
		}
		return root;
	}
}

nodeBST* rotateRight(nodeBST* root){
	nodeBST* temp1 = root;
	root = root -> left;
	nodeBST* temp2 = root -> right;
	root -> right = temp1;
	temp1 -> left = temp2;
	return root;
}

nodeBST* rotateLeft(nodeBST* root){
	nodeBST* temp1 = root;
	root = root -> right;
	nodeBST* temp2 = root -> left;
	root -> left = temp1;
	temp1 -> right = temp2;
	return root;
}

int main(){
    int n, inp;
    cin >> n >> inp;
    nodeBST* root = initNode(inp);
    for(int i = 1; i < n; i++){
        cin >> inp;
        root = insertNode(root, inp);
    }
    cout << height(root);
    return 0;
}
