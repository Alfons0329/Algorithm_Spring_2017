
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
int Select(int *, int);
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
    node():left_ch(0),right_ch(0),parent(0),data(0),color(0){};

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
    bool IsEmptyTree();
    node* Predecessor(node* current);
    node* Rightmost(node* current);
    node* Search(int key_in);

    RBT()
    {
        nil = new node; //give nil a space
        nil->color = 0; //nil is black
        root=nil; //the very first situation
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
    insert_node->data = key_in;
    while (x != nil)
    {
        y = x;
        if (insert_node->data <= x->data)
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
        root = insert_node;
    }
    else if (insert_node->data <= y->data)
    {
        y->left_ch = insert_node;
    }
    else{
        y->right_ch = insert_node;
    }

    //set the newly inserted node's properties

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
        if(current->parent==current->parent->parent->left_ch)
        {
            node* uncle = current->parent->parent->right_ch;
            //case1 uncle is red
            if(uncle->color==1)
            {
                current->parent->color=0; //bubble up the black color
                uncle->color=0;
                current->parent->parent->color=1;
                current=current->parent->parent;
            }
            //case 2 3 uncle is black , and 2 kinds of rotation
            else
            {
                if(current==current->parent->right_ch)//case 2 (actually tuen into case 3)
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
        //block two symmetric to top, parent is at grandparent's right_ch;
        else
        {
            node* uncle = current->parent->parent->left_ch;
            //case1 uncle is red
            if(uncle->color==1)
            {
                current->parent->color=0; //bubble up the black color
                uncle->color=0;
                current->parent->parent->color=1;
                current=current->parent->parent;
            }
            //case 2 3 uncle is black , and 2 kinds of rotation
            else
            {
                if(current==current->parent->left_ch)//case 2 (actually tuen into case 3)
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
    root->color=0;
}
// for color: 0: black, 1: red
void RBT::RBTDeleteFixUp(node* current)
{
    if(current->color==1) //if current to fix is red, mark it as black
    {
        current->color=0;
    }
    if(current->parent==nil) //if current to fix is root, mark it as black
    {
        current->color=0;
    }
    while(current != root &&current->color==0)
    {
        if (current == current->parent->left_ch)
        {
            node *sibling = current->parent->right_ch;
            // Case1: Iif sibling  is red
            if (sibling->color == 1)
            {
                sibling->color = 0;
                current->parent->color = 1;
                LeftRotation(current->parent);
                sibling = current->parent->right_ch;
            }
            // Case2、3、4: sibling is black
            // Case2: sibling's 2 child are all black node
            if (sibling->left_ch->color == 0 && sibling->right_ch->color == 0)
            {
                sibling->color = 1;
                current = current->parent;           // if update till root,than exit the loop
            }
            else //case 3 4 ,only on of the child of the sibling is black
            {
                //case3: siblinf's right child is black
                if (sibling->right_ch->color == 0)
                {
                    sibling->left_ch->color = 0;
                    sibling->color = 1;
                    RightRotation(sibling);
                    sibling = current->parent->right_ch;
                }
                // After case3 will become case 4
                // Case 4: sibling's right child is red, left childis black
                sibling->color = current->parent->color;
                current->parent->color = 0;
                sibling->right_ch->color = 0;
                LeftRotation(current->parent);
                current = root;     // After to root, jump out the loop
            }
        }
        else
        {

        }
    }
}
bool RBT::IsEmptyTree()
{
    return (this->root==this->nil) ? 1 : 0;
}
node* RBT::Predecessor(node *current)
{
    if (current->left_ch != NULL)
    {
        return Rightmost(current->left_ch);
    }
    //if it has no
}
node* RBT::Rightmost(node *current)
{
    while(current->right_ch!=NULL)
    {
        current=current->right_ch;
    }
    return current;
}
node* RBT::Search(int key_in)
{
        node* current = root;

        while(current!=NULL && key_in != current->data)
        {
            if (key_in < current->data)
            {
                current = current->left_ch;   // go l
            }
            else
            {
                current = current->right_ch;  // go r
            }
        }
        return current;
}
void Insert(int* tree, int key)
{

    RBT RBTree;
    for(int i=2;i<tree[0];i+=3) //build the tree from a given array's data
    {
        if(tree[i]!=-1&&tree[i]!=0)
        {
            cout<<"\nInserting "<<tree[i]<<endl;
            RBTree.RBTInsert(tree[i]);
        }
    }
    if(key!=-999)//for self-debugging test
        RBTree.RBTInsert(key);

    //write back to the given array using level order traversal
    unsigned int bundle_index=1;
    node* current=RBTree.root;
    queue<node* > q;
    q.push(current);
    while(q.size())
    {
        current=q.front();
        q.pop();
        tree[bundle_index]=current->color;
        //for size
        unsigned int count_size=0;
        node* current2=current;
        queue<node* > q2;
        q2.push(current2);
        while(q2.size())
        {
            current2=q2.front();
            q2.pop();
            tree[bundle_index]=current2->color;
            if(current2->left_ch!=NULL)
                q2.push(current2->left_ch);
            if(current2->right_ch!=NULL)
                q2.push(current2->right_ch);
            if(current2!=NULL&&current2!=RBTree.nil)
            {
                count_size++;
            }
        }
        tree[bundle_index+2]=count_size;
        //for size end
        if(current->left_ch!=NULL)
            q.push(current->left_ch);
        if(current->right_ch!=NULL)
            q.push(current->right_ch);


        if(current==RBTree.nil)
        {
            tree[bundle_index+0]=0;
            tree[bundle_index+1]=0;
        }
        else if(current==NULL)
        {
            tree[bundle_index+0]=-1;
            tree[bundle_index+1]=-1;
        }
        else
        {
            tree[bundle_index+0]=current->color;
            tree[bundle_index+1]=current->data;
        }
        bundle_index+=3;
    }
    cout<<"Write back procedure OK ALL DONE, after WB, tree data to be: "<<endl;
    for(int i=0;i<tree[0];i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";
}

void Delete(int * tree, int key)
{
	//
	// if there is ambiguous situation, choose the smaller or left one
	//
    //search the key first
    //tree reconstruction
    RBT RBTree;
    for(int i=0;i<tree[0];i++) //build the tree from a given array's data
    {
        if((i+1)%3==0&&tree[i]!=-1&&tree[i]!=0)
        {
            RBTree.RBTInsert(tree[i]);
        }
    }
    //cout<<"delete reconstruction ok "<<endl;
    node* delete_node = RBTree.Search(key);
    cout<<"delete search ok "<<endl;
    if (delete_node == NULL)
    {
        std::cout << "data not found.\n";
        return;
    }
    node* to_be_deleted = NULL;
    node* to_be_deleted_child = NULL;     //to_be_deleted_child to be deleted's child
    cout<<"Start delete"<<endl;
    if (delete_node->left_ch == RBTree.nil || delete_node->right_ch == RBTree.nil) //not the 2 children case
    {
        to_be_deleted = delete_node;
    }
    else   //2 child case turn to 1 thild, assign its data and delete its Predecessor
    {
        to_be_deleted = RBTree.Predecessor(delete_node);
    }
    cout<<"assign deletion node ok "<<endl;

    if (to_be_deleted->left_ch != RBTree.nil)
    {
        //set the connectivity
        to_be_deleted_child = to_be_deleted->left_ch;
    }
    else
    {
        to_be_deleted_child = to_be_deleted->right_ch;
    }


    to_be_deleted_child->parent = to_be_deleted->parent;//re-connection

    cout<<"assign deletion connectivity ok "<<endl;

    if (to_be_deleted->parent == RBTree.nil)  //if to_be_deleted is the root then set the root as to_be_deleted_child
    {
        RBTree.root = to_be_deleted_child;
    }
    else if (to_be_deleted == to_be_deleted->parent->left_ch)
    {
        to_be_deleted->parent->left_ch = to_be_deleted_child; //connectivity of to_be_deleted_parent's left_ch
    }
    else
    {
        to_be_deleted->parent->right_ch = to_be_deleted_child; //connectivity of to_be_deleted_parent's right_ch
    }

    if (to_be_deleted != delete_node)
    {
        delete_node->data = to_be_deleted->data;         // overwrite the two child's case
        //delete_node->element = y->element;
    }

    if (to_be_deleted->color == 0)
    {
        RBTree.RBTDeleteFixUp(to_be_deleted_child); //if the node deleted is black ,then fix it from
        //fix up from its child
    }
    cout<<"Delete data is "<<to_be_deleted->data<<endl;
    delete to_be_deleted;
    //assign to be all null first, then WB
    for(int i=1;i<tree[0];i++)
    {
        tree[i]=-1;
    }

    unsigned int bundle_index=1;
    node* current=RBTree.root;
    queue<node* > q;
    q.push(current);
    while(q.size())
    {
        current=q.front();
        q.pop();
        tree[bundle_index]=current->color;
        //for size
        unsigned int count_size=0;
        node* current2=current;
        queue<node* > q2;
        q2.push(current2);
        while(q2.size())
        {
            current2=q2.front();
            q2.pop();
            tree[bundle_index]=current2->color;
            if(current2->left_ch!=NULL)
                q2.push(current2->left_ch);
            if(current2->right_ch!=NULL)
                q2.push(current2->right_ch);
            if(current2!=NULL&&current2!=RBTree.nil)
            {
                count_size++;
            }
        }
        tree[bundle_index+2]=count_size;
        //for size end
        if(current->left_ch!=NULL)
            q.push(current->left_ch);
        if(current->right_ch!=NULL)
            q.push(current->right_ch);


        if(current==RBTree.nil)
        {
            tree[bundle_index+0]=0;
            tree[bundle_index+1]=0;
        }
        else if(current==NULL)
        {
            tree[bundle_index+0]=-1;
            tree[bundle_index+1]=-1;
        }
        else
        {
            tree[bundle_index+0]=current->color;
            tree[bundle_index+1]=current->data;
        }
        bundle_index+=3;
    }
    cout<<"Write back procedure OK ALL DONE, after WB, tree data to be: "<<endl;
    for(int i=0;i<tree[0];i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------";
}

int Select(int * tree, int ith) //from the samllest to count
{
	// use Dynamic Order Statistics to tell me the i'th smallest element
	int output_key;
    vector<int> data_collection;
    for(int i=1;i<tree[0];i+=3)
    {
        if(tree[i]!=-1&&tree[i]!=0)
        {
            data_collection.push_back(tree[i]);
        }
    }
    sort(data_collection.begin(),data_collection.end());
    output_key=data_collection[ith-1];//since from 1 base to 0 base
	return output_key;
}

int Rank(int * tree, int key_in)
{

	// use Dynamic Order Statistics to tell me the rank of element x in the tree
    int output_rank=0;
    vector<int> data_collection;
    for(int i=1;i<tree[0];i+=3)
    {
        if(tree[i]!=-1&&tree[i]!=0)
        {
            data_collection.push_back(tree[i]);
        }
    }
    sort(data_collection.begin(),data_collection.end());
    for(;output_rank<tree[0];output_rank++)
    {
        if(key_in==data_collection[output_rank])
            break;
    }
    //using BFS algorithm to traverse down to see how many nodes are under the current root ith

	return output_rank+1;//since from 0 base to 1 base
}
