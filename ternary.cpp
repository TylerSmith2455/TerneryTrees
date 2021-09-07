#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>

using namespace std;

// Define Node struct
struct Node {
	int leftVal;                   // Holds the left value of the node
	int rightVal;                  // Holds the right value of the node
	struct Node *leftChild;        // Pointers to left, middle, and right child nodes
	struct Node *middleChild;
	struct Node *rightChild;
}*temp = NULL;

// Create a new node
struct Node* newNode(int left) {      // Nodes are created with only one value inside
	temp = new Node;
	temp->leftVal = left;         // Put the value into the node's left value
	temp->rightVal = -1;          // Set the node's right value as an invlaid value
	temp->leftChild = NULL;       // Set child nodes to NULL
	temp->rightChild = NULL;
	temp->middleChild = NULL;
	return temp;
}

// Insert Function
void insert(struct Node** root, int val) {
	// Check to see if the current is NULL
	if (!(*root)) {
		*root = newNode(val);
		return;
	}
        
	// Check to see if the current node only has one value
	if ((*root)->rightVal == -1) {
		if ((*root)->leftVal > val) {
			(*root)->rightVal = (*root)->leftVal;
			(*root)->leftVal = val;
		}
		else (*root)->rightVal = val;
		return;
	}
        
	// Is the new value less than or euqal to the current leftVal of the node
	if (val <= (*root)->leftVal)
		insert(&( (*root)->leftChild ), val);      // If so, go to the current node's left child
        
	// If the new value greater than the leftVal and less than or equal to the rightVal
	else if ((val > (*root)->leftVal) && (val <= (*root)->rightVal))
		insert(&( (*root)->middleChild ), val);    // If so, go to the current node's middle child
	
	// Go to the current node's right child
	else insert(&( (*root)->rightChild ), val);
} // Insert Function

// Print Function
 void print(struct Node** root) {
	 // Check to see if current node is NULL
	 if (*root == NULL)           
		 return;
	 else {
		 // Check if the current node's left child is NULL
		 if ((*root)->leftChild == NULL) {
			 cout << "(";
		 }
		 else { 
			 cout << "(";
			 print(& (*root)->leftChild); // If node isn't NULL, go to the current node's left child
		 }
		 cout << (*root)->leftVal;            // Print the current node's left value

		 // Check if the current node has one or two values
		 if ((*root)->rightVal != -1)
			 cout << " ";

		 // Check if the current node's middle child is NULL
		 if ((*root)->middleChild != NULL)
		 	print(& (*root)->middleChild); // Go to the current node's middle child

		 // If the current node has a right value, then print it
		 if ((*root)->rightVal != -1)
                         cout << (*root)->rightVal; 
                 
		 // Check if the current node's right child is not NULL
		 if ((*root)->rightChild != NULL){
			 cout << " ";
        		 print(& (*root)->rightChild); // Go to the currrent node's right child
                         cout << ")";
		 }
		 else {
			 cout << ") ";
		 }
	 }
 } // Print Function

// Main
int main(int argc, char *argv[]) {
	int n = stoi(argv[1]);           // Hold user input of the amount of numbers they wish to insert
	int vals;                       
	struct Node *root = NULL;        // Set the root node to NULL

	// Loop to continue taking in user input until max number is reached
	for (int i = 0; i < n; i++){
		cin >> vals;             
		insert(&root, vals);     // Insert each value into the tree
	}
	print(&root);                    // Print the ternary tree
	cout << endl;
	return 0;
} // Main
	
