#include<iostream>
#define SPACE 10

using namespace std;

class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};

class BST {
  public:
    TreeNode * root;
  BST() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }

  void insertNode(TreeNode * new_node) {
    if (root == NULL) {
      root = new_node;
      cout << "Value Inserted as root node!" << endl;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (new_node -> value == temp -> value) {
          cout << "Value Already exist," <<
            "Insert another value!" << endl;
          return;
        } else if ((new_node -> value < temp -> value) && (temp -> left == NULL)) {
          temp -> left = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        } else if (new_node -> value < temp -> value) {
          temp = temp -> left;
        } else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) {
          temp -> right = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        } else {
          temp = temp -> right;
        }
      }
    }
  }
  	TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node)
	{
		if(r==NULL)
		{
			r=new_node;
			cout <<"Insertion successful"<<endl;
			return r;
		}
	
		if(new_node->value < r->value)
		{
			r->left = insertRecursive(r->left,new_node);
		}
		else if (new_node->value > r->value)  
		{
			r->right = insertRecursive(r->right,new_node);
		}
	   else
	   {
	     	cout << "No duplicate values allowed!" << endl;
	     	return r; 
		}
		return r;
	}

  void printPreorder(TreeNode * r) 
  {
    if (r == NULL)
      return;
    
    cout << r -> value << " ";
   
    printPreorder(r -> left);
   
    printPreorder(r -> right);
  }

  void printInorder(TreeNode * r) 
  {
    if (r == NULL)
      return;
    
    printInorder(r -> left);
    
    cout << r -> value << " ";
    
    printInorder(r -> right);
  }
  void printPostorder(TreeNode * r) 
  {
    if (r == NULL)
      return;
  
    printPostorder(r -> left);
    
    printPostorder(r -> right);
    
    cout << r -> value << " ";
  }
  
};

int main() {
  BST obj;
  int option, val;

  do {
    cout << "\n" << endl;
    cout << "-- Menu -- \n" << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Display its preorder, postorder and inorder traversals" << endl;
    cout << "0. Exit Program \n" << endl;

    cin >> option;
    
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      	cout <<"INSERT\n"<<endl;
	      cout <<"Enter value of TREE NODE : ";
	      cin >> val;
	      new_node->value = val;
	      obj.root= obj.insertRecursive(obj.root,new_node);
	      cout<<endl;
    		break;
   
    case 2:
              cout <<"\n ";
      	      cout <<"PRE-ORDER: ";
      	      obj.printPreorder(obj.root);
      	      cout<<endl;
      	      cout <<"IN-ORDER: ";
      	      obj.printInorder(obj.root);
      	      cout<<endl;
      	      cout <<"POST-ORDER: ";
      	      obj.printPostorder(obj.root);
      break;
   
    default:
      cout << "Enter correct option " << endl;
    }

  } while (option != 0);

  return 0;
}
