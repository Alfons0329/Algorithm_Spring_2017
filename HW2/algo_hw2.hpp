
// change this to your id
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
static const char* student_id = "0416324" ;


// do not edit prototype
void Insert(int *, int);
void Delete(int *, int);
int Select(int *, int;
int Rank(int *, int);

// data structure :
// tree is an array with enough space
// tree[0] is the array size
// bundle three attribute as a node data
// First attribute is color, "0" means black, "1" means red , NIL is also "0", "-1" means no data
// Second attribute is key, "0" means NIL, "1"~"999" means data,  "-1" means no data
// Third attribute is size, for Dynamic Order Statistics, "0" means NIL , "-1" means no data
//
// for example,
// if tree[0] is "256" says that the array size is 256
//
// if tree[1] is "1" says that the place of 1 is a red node
//
// if tree[2] is "5" says that the place of 1 is key of 5
//
// if tree[8] is "-1" says that the place of 3 has nothing
//
// if tree[14] is "-1" says that the place of 5 is a node of NIL
//
// if tree[19] is "66" says that the place of 7 is key of 66


//
// do your homework here
//
class node
{
public:
    int data;
    int color; // for color: 0: black, 1: red
    node* left_ch;
    node* right_ch;
    node* parent;
    bool isnil;

};
class RBT
{
public:
    node* root;
    node* nil;

    void LeftRotation(node *x);
    void RightRotation(node *x);
    void RBTInsert(int key_in);
    void RBTInsertFixUp(node* current);
    void RBTDelete(int key_in);
    void RBTDeleteFixUp(node* current);
    node* Predecessor(node* current);
    node* Leftmost(node* curent);
    node* Search(int key_in);

    RBT()
    {
        nil = new node; //give nil a space
        nil->color = 0; //nil is black
        root=nil //the very first situation
        root->parent=nil; //the very first situation
    }

};

void RBT::LeftRotation(node *x) //x is the rotation point current in
{
    node *y = x->right_ch;  //locate position

    x->right_ch = y->left_ch; //reconnection
    if (y->left_ch != nil)
    {
        y->left_ch->parent = x;
    }

    y->parent = x->parent; //set the parent for rotation

    if (x->parent == nil)//if root
    {
        root = y; //then root will be y
    }
    else if (x == x->parent->left_ch) //reconnection for parent-child relationship
    {
        x->parent->left_ch = y;
    }
    else //reconnection for parent-child relationship
    {
        x->parent->right_ch = y;
    }
    y->left_ch = x;//reconnection for parent-child relationship
    x->parent = y;//reconnection for parent-child relationship
}
//mirror to RightRotation
void RBT::RightRotation(node *x) //x is the rotation point current in
{
    node *y = x->left_ch;  //locate position

    x->left_ch = y->right_ch; //reconnection
    if (y->right_ch != nil)
    {
        y->right_ch->parent = x;
    }

    y->parent = x->parent; //set the parent for rotation

    if (x->parent == nil)//if root
    {
        root = y; //then root will be y
    }
    else if (x == x->parent->right_ch) //reconnection for parent-child relationship
    {
        x->parent->right_ch = y;
    }
    else //reconnection for parent-child relationship
    {
        x->parent->left_ch = y;
    }
    y->right_ch = x;//reconnection for parent-child relationship
    x->parent = y;//reconnection for parent-child relationship
}
void RBT::RBTInsert(int key_in)
{
    node* y = nil;
    node* x = root;
    node* insert_node = new node;

    while (x != nil)
    {
        y = x;
        if (insert_node->key < x->key)
        {
            x = x->left_ch;
        }
        else
        {
            x = x->right_ch;
        }
    }

    insert_node->parent = y;

    if (y == nil)
    {
        this->root = insert_node;
    }
    else if (insert_node->key < y->key)
    {
        y->left_ch = insert_node;
    }
    else{
        y->right_ch = insert_node;
    }

    //set the newly inserted node's properties
    insert_node->data = key_in;
    insert_node->left_ch = nil;
    insert_node->right_ch = nil;
    insert_node->color = 1;
    //the upper part is just the normal BST insertion
    RBTInsertFixUp(insert_node);
}
void RBT::RBTInsertFixUp(node *current)
{
    while(current->parent->color==1) //if parent is red go loop
    {
        //block one, parent is at grandparent's left_ch
        if(current->parent=current->parent->parent->left_ch)
        {
            node* uncle = current->parent->parent->right_ch;
            //case1 uncle is red
            if(uncle->color==1)
            {
                current->parent->color=0; //bubble up the black color
                uncle->color=0;
                curent->parent->parent=1;
                current=curent->parent->parent;
            }
            //case 2 3 uncle is black , and 2 kinds of rotation
            else
            {
                if(curent=current->parent->right_ch)//case 2 (actually tuen into case 3)
                {
                    current=current->parent;
                    LeftRotation(current); //swap to left side and same as case 3
                }
                //case 3
                current->parent->color=0;
                current->parent->parent->color=1;
                RightRotation(current->parent->parent);
            }
        }
        //block two symmetric to阿 top, parent is at grandparent's right_ch;
        else
        {
            node* uncle = current->parent->parent->left_ch;
            //case1 uncle is red
            if(uncle->color==1)
            {
                current->parent->color=0; //bubble up the black color
                uncle->color=0;
                curent->parent->parent=1;
                current=curent->parent->parent;
            }
            //case 2 3 uncle is black , and 2 kinds of rotation
            else
            {
                if(curent=current->parent->left_ch)//case 2 (actually tuen into case 3)
                {
                    current=current->parent;
                    RightRotation(current); //swap to right side and same as case 3
                }
                //case 3
                current->parent->color=0;
                current->parent->parent->color=1;
                LeftRotation(current->parent->parent);
            }
        }
    }
}
void RBT::RBTDeleteFixUp(node* current)
{

}
node* RBT::Predecessor(node *current)
{

}
node* RBT::Leftmost(node *current)
{


}
node* Search(int key_in)
{
        node* current = root;

        while(current!=NULL && key_in != current->data)
        {
            if (KEY < current->data)
            {
                current = current->leftchild;   // 向左走
            }
            else
            {
                current = current->rightchild;  // 向右走
            }
        }
        return current;
}
void Insert(int * tree, int key)
{
    RBT RBTree;
    for(int i=0;i<tree[0];i++) //build the tree from a given array's data
    {
        if((i+1)%3==0)
        {
            RBTree.RBTInsert(tree[i]);
        }
    }
    RBTree.RBTInsert(key);

    //write back to the given array using level order traversal
    unsigned int bundle_index=1;
    node* current=RBTree.root;
    queue<node* > bfs_q;
    q.push(current);
    while(q.size())
    {
        current=q.front();
        q.pop();
        tree[bundle_index]=current->color;
        if(current=nil)
        {
            tree[bundle_index+1]=0;
        }
        else if(current=NULL)
        {
            tree[bundle_index+1]=-1
        }
        else
        {
            tree[bundle_index+1]=current->data;
        }
        bundle_index+=3;
    }
}

void Delete(int * tree, int key)
{
	//
	// if there is ambiguous situation, choose the smaller or left one
	//
    //search the key first
    node* delete_node = Search(key);

    if (delete_node == NULL)
    {
        std::cout << "data not found.\n";
        return;
    }
    node* to_be_deleted = NULL;
    node* to_be_deleted_child = NULL;     //to_be_deleted_child to be deleted's child

    if (delete_node->leftchild == nil || delete_node->rightchild == nil) //not the 2 children case
    {
        to_be_deleted = delete_node;
    }
    else   //2 child case turn to 1 thild, assign its data and delete its Predecessor
    {
        to_be_deleted = Predecessor(delete_node);
    }


    if (to_be_deleted->leftchild != nil)
    {
        //set the connectivity
        to_be_deleted_child = to_be_deleted->leftchild;
    }
    else
    {
        to_be_deleted_child = to_be_deleted->rightchild;
    }


    to_be_deleted_child->parent = to_be_deleted->parent;//re-connection

    if (to_be_deleted->parent == nil)  //if to_be_deleted is the root then set the root as to_be_deleted_child
    {
        this->root = to_be_deleted_child;
    }
    else if (to_be_deleted == to_be_deleted->parent->leftchild)
    {
        to_be_deleted->parent->leftchild = to_be_deleted_child; //connectivity of to_be_deleted_parent's leftchild
    }
    else
    {
        to_be_deleted->parent->rightchild = to_be_deleted_child; //connectivity of to_be_deleted_parent's rightchild
    }

    if (to_be_deleted != delete_node)
    {
        delete_node->data = to_be_deleted->data;         // overwrite the two child's case
        //delete_node->element = y->element;
    }

    if (to_be_deleted->color == 0)
    {
        DeleteFixedUpRBT(to_be_deleted_child); //if the node deleted is black ,then fix it from
        //fix up from its child
    }
    delete to_be_deleted;

}

int Select(int * tree, int i) //from the samllest to count
{
	// use Dynamic Order Statistics to tell me the i'th smallest element
	int output_key;
	return output_key;
}

int Rank(int * tree, int x)
{

	// use Dynamic Order Statistics to tell me the rank of element x in the tree
	int output_rank;
	return output_rank;
}
