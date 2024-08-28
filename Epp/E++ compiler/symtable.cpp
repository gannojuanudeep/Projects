/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"

// Write your code below this line
// #include <iostream>
// using namespace std;
int heightcal_table(SymNode* node){
   int a,b;
   if(node->left!=NULL){
    a=node->left->height;
   }
   else{
    a=-1;
   }
   if(node->right!=NULL){
    b=node->right->height;
   }
   else{
    b=-1;
   }
   node->height=max(a,b)+1;
   return node->height;
}
void replace(SymNode *node, SymNode *rep_node)
{ // check if rep_node if right of node;
    ////////cout << "replace enter" << endl;
    rep_node->par = node->par;
    if (rep_node != node->left && node->left != NULL)
    {
        rep_node->left = node->left;
    }
    if (rep_node != node->right && node->right != NULL)
    {
        rep_node->right = node->right;
    }
    if (rep_node != node->left && node->left != NULL)
    {
        node->left->par = rep_node;
    }
    if (rep_node != node->right && node->right != NULL) // can combine two
    {
        node->right->par = rep_node;
    }
    if (node->par != NULL)
    {
        if (node->par->left == node)
        {
            node->par->left = rep_node;
        }
        else
        {
            node->par->right = rep_node;
        }
    }
    node->par = NULL;
    node->left = NULL;
    node->right = NULL;
    delete node; //---------delete node;
}
SymNode *sucessor(SymNode *node)
{
    //////cout << "sucessor enter" << endl;
    SymNode *temp = node;
    temp = temp->right;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
SymNode *balance(SymNode *node)
{
    //cout << "enter balance" << endl;
    SymNode *temp = node;
    if(node==NULL){
        //cout<<"NULL"<<endl;
        // return ;
    }
    //cout <<"yo" << endl;
    while (temp != NULL)
    {
        //cout<<"enetr while"<<endl;
        int a, b;
        if (temp->left != NULL)
        {
            a = temp->left->height;
        }
        else
        {
            a = -1;
        }
        //cout << "hi" << endl;
        if (temp->right != NULL)
        {
            
            b = temp->right->height;
        }
        else
        {
            b = -1;
        }
        temp->height = max(a, b) + 1;
        //cout<<"here a and b are "<<a<<" "<<b<<endl;
        //cout<<temp->height<<endl;
        if (abs((a) - (b)) <= 1)
        {
            if (temp->par == NULL)
            {
                //cout << "hiiiii" << endl;
                //cout << temp->key << endl;
                return temp;
            }
            temp = temp->par;
        }
        else
        {
            int c, d;
            if ((a) > (b))
            {
                if (temp->left->left != NULL)
                {
                    c = temp->left->left->height;
                }
                else
                {
                    c = -1;
                }
                if (temp->left->right != NULL)
                {
                    d = temp->left->right->height;
                }
                else
                {
                    d = -1;
                }
                //cout<<"here c and d are "<<c<<" "<<d<<endl;
                if (c > d)
                {
                    //////cout<<"enter llr"<<endl;
                    temp = temp->LeftLeftRotation();
                    if (temp->par == NULL)
                    {
                        SymNode *temp1 = temp;
                        return temp1;
                    }
                    temp = temp->par;
                }
                else
                {
                    //cout<<"enter lrr"<<endl;
                    //cout<<temp->key<<endl;
                    temp = temp->LeftRightRotation();
                    //cout<<"end llr"<<endl;
                    //cout<<temp->key<<endl;
                    if (temp->par == NULL)
                    {
                        SymNode *temp1 = temp;
                        return temp1;
                    }
                    //cout<<temp->height<<endl;
                    //cout<<temp->par->right->key<<endl;
                    temp = temp->par;
                }
            }
            else
            {
                //cout<<"a<b"<<endl;
                if (temp->right->right != NULL)
                {
                    c = temp->right->right->height;
                }
                else
                {
                    c = -1;
                }
                if (temp->right->left != NULL)
                {
                    d = temp->right->left->height;
                }
                else
                {
                    d = -1;
                }
                //cout<<"here c and d are "<<c<<" "<<d<<endl;
                if (c > d)
                {
                    //cout<<"rrr enter"<<endl;
                    //cout<<temp->key<<endl;
                    temp = temp->RightRightRotation();
                    if (temp->par == NULL)
                    {
                        SymNode *temp1 = temp;
                        return temp1;
                    }
                    temp = temp->par;
                }
                else
                {
                    //cout<<"rrl enter"<<endl;
                    temp = temp->RightLeftRotation();  //getting error
                    if (temp->par == NULL)
                    {
                        SymNode *temp1 = temp;
                        return temp1;
                    }
                    temp = temp->par;
                }
            }
        }
    }
}
SymbolTable::SymbolTable()
{
    size = 0;
    root = NULL;
}

void SymbolTable::insert(string k)
{
    SymNode *temp = this->get_root();
    SymNode *inse = new SymNode(k); // created a new node

    if (size == 0)
    {
        //////cout << "geto" << endl;
        root = inse;
        size++;
        return;
    }
    //////cout << "enter insert" << endl;
    while (temp != NULL)
    {
        // //////cout<<"enter while"<<endl;
        if (temp->key == k)
        {
            return;
        }

        else if (temp->key > k)
        {
            //////cout << "else if enter" << endl;
            if (temp->left == NULL)
            {
                temp->left = inse;
                inse->par = temp;
                size++;
                break;
            }
            temp = temp->left;
        }
        else
        {
            //////cout << "else enter" << endl;
            //////cout << temp->key << endl;
            if (temp->right == NULL)
            {
                //////cout << "fun" << endl;
                temp->right = inse;
                inse->par = temp;
                size++;
                break;
            }
            //////cout << "inter" << endl;
            temp = temp->right;
            //////cout << temp->key << endl;
            //////cout << "exit else" << endl;
        }
    }
    // //////cout << "here1" << endl;
    // //////cout << temp->key << endl;
    // //////cout << size << endl;
    // //////cout << "hi" << endl;
    int h_var = temp->height;
    //////cout << "here h_var " << h_var << endl;
    int a, b;
    if (temp->left != NULL)
    {
        a = temp->left->height;
    }
    else
    {
        a = -1;
    }
    // //////cout << "hi" << endl;
    if (temp->right != NULL)
    {
        b = temp->right->height;
    }
    else
    {
        b = -1;
    }
    //////cout << "here a and b are " << a << " " << b << endl;
    temp->height = max(a, b) + 1;
    //////cout << "here new temp-height " << temp->height << endl;
    while (temp->height != h_var)
    {
        //////cout << "enter height while" << endl;
        if (abs((a) - (b)) <= 1)
        {
            //////cout << "enter if" << endl;
            //////cout << temp->key << endl;
            if (temp->par == NULL)
            {
                //////cout << "enter iff" << endl;
                return;
            }
            else
            {
                //////cout << "enter elseee" << endl;
                temp = temp->par;
                //////cout << temp->key << endl;
                h_var = temp->height;
                //////cout << h_var << endl;
                if (temp->left != NULL)
                {
                    a = temp->left->height;
                }
                else
                {
                    a = -1;
                }
                if (temp->right != NULL)
                {
                    b = temp->right->height;
                }
                else
                {
                    b = -1;
                }
                //////cout << "here a and b are " << a << " " << b << endl;
                temp->height = max(a, b) + 1;
                //////cout << temp->height << endl;
            }
        }
        else
        { // should we check after rotation??
            //////cout << "enter rotation else" << endl;
            int c, d;
            if ((a) > (b))
            {
                //////cout << "a>b" << endl;
                if (temp->left->left != NULL)
                {
                    c = temp->left->left->height;
                }
                else
                {
                    c = -1;
                }
                if (temp->left->right != NULL)
                {
                    d = temp->left->right->height;
                }
                else
                {
                    d = -1;
                }
                if (c > d)
                {
                    temp = temp->LeftLeftRotation();
                    if (temp->par == NULL)
                    {
                        root = temp;
                    }
                }
                else
                {
                    temp = temp->LeftRightRotation();
                    if (temp->par == NULL)
                    {
                        root = temp;
                    }
                }
            }
            else
            {
                //////cout << "a<b" << endl;
                if (temp->right->right != NULL)
                {
                    c = temp->right->right->height;
                }
                else
                {
                    c = -1;
                }
                if (temp->right->left != NULL)
                {
                    d = temp->right->left->height;
                }
                else
                {
                    d = -1;
                }
                //////cout << "here c is " << c << " here d is " << d << endl;
                if (c > d)
                {
                    //////cout << "enetr" << endl;
                    temp = temp->RightRightRotation();

                    if (temp->par == NULL)
                    {
                        root = temp;
                    }
                }
                else
                {
                    temp = temp->RightLeftRotation();
                    if (temp->par == NULL)
                    {
                        root = temp;
                    }
                }
            }
            return;
        }
    }
    return;
}

void SymbolTable::remove(string k)
{
    SymNode *temp = root;

    if (size == 0)
    {
        return;
    }
    //////cout << "remove enter" << endl;
    while (temp->key != k)
    {
        if (temp->key > k)
        {
            if (temp->left == NULL)
            {
                return;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                return;
            }
            temp = temp->right;
        }
    }
    //////cout << "while completed" << endl;
    //////cout << temp->key << endl;
    if (temp->left == NULL && temp->right == NULL)
    {
        //////cout << "eneter no child" << endl;
        SymNode *temp1 = temp->par;
        if(temp1!=NULL){
        if (temp1->left == temp)
        {
            temp1->left = NULL;
        }
        else
        {
            temp1->right = NULL;
        }
        
        //////cout<<temp1->key<<endl;
        //cout << "before balance for no child" << endl;
        root = balance(temp1);
        temp->par = NULL;
        size--;  
        }
        else{
            size--;
        }
        delete temp; // deleting temp--symnode;
    }
    else if (temp->left != NULL && temp->right != NULL)
    {
        //////cout << "enter bpth childs" << endl;
        SymNode *temp_succ = sucessor(temp);
        //////cout << "sucessor comp" << temp_succ->key << endl;
        SymNode *temp2 = temp_succ->par;
        //////cout << "his" << endl;
        if (temp2 != temp)
        {
            temp2->left = temp_succ->right;
            if (temp_succ->right != NULL)
            {
                temp_succ->right->par = temp2;
            }

            size--;
            //////cout << "before replace" << endl;
            replace(temp, temp_succ); // deleting temp---symnode
            //cout << "balance from 2 childs" << endl;
            root = balance(temp2);
            //////cout << "balance compl" << endl;
        }
        else{
            //////cout<<"else"<<endl;
            size--;
            replace(temp, temp_succ);
              //cout << "balance from 2 child" << endl;
            root=balance(temp_succ);
            //////cout << "balance compl" << endl;
        }
    }
    else
    {
        //////cout<<"removal one child enter"<<endl;
        if (temp->left == NULL)
        {
            SymNode *temp3 = temp->right;
            size--;
            // ////cout<<"hi"<<endl;
            replace(temp, temp3);
            // ////cout<<"replace completed"<<endl;
            // ////cout<<temp3->key<<endl;
            if(temp3->par==NULL){
                root=temp3;
                return;
            }
              //cout << "balance from 1 childs" << endl;
            root = balance(temp3->par);
        }
        else
        {
            //////cout<<"yo"<<endl;
            SymNode *temp4 = temp->left;
            size--;
            //////cout<<"enter removal replace"<<endl;
            replace(temp, temp4);
            //////cout<<temp4->key<<endl;
            //////cout<<temp4->par->key<<endl;
            //////cout<<temp4->par->left->key<<endl;
            //////cout<<"enter removal replace comp"<<endl;
            if(temp4->par==NULL){
                root=temp4;
                return;
            }
              //cout << "balance from 1 child" << endl;
            root = balance(temp4->par);
            //////cout<<"enter removal balance comp"<<endl;
        }
    }
}

int SymbolTable::search(string k)
{ ////cout<<"enetr search"<<endl;
    SymNode *temp = root;
   
    if (size == 0)
    {
        // //cout<<"return -2"<<endl;
        return -2;
    }
    while (temp->key != k)
    {
        if (temp->key > k)
        {

            if (temp->left == NULL)
            {
                return -2;
            }
            temp = temp->left;
        }
        else
        {

            if (temp->right == NULL)
            {
                return -2;
            }
            temp = temp->right;
        }
    }
    return temp->address;
}

void SymbolTable::assign_address(string k, int idx)
{
    SymNode *temp = root;

    if (size == 0)
    {
        return;
    }
    while (temp->key != k)
    {
        if (temp->key > k)
        {

            if (temp->left == NULL)
            {
                return;
            }
            temp = temp->left;
        }
        else
        {

            if (temp->right == NULL)
            {

                return;
            }
            temp = temp->right;
        }
    }
    temp->address = idx;
}

int SymbolTable::get_size()
{
    return size;
}

SymNode *SymbolTable::get_root()
{
    return root;
}

SymbolTable::~SymbolTable() // check destructors
{
    if(root){
        delete root;
    }
    size=0;
}
void inorder(SymNode *node)
{
    if (node == NULL)
    {
        return;
    }

    inorder(node->left);
    //////cout << node->key <<" root height is "<<node->height<< endl;
    if(node->par!=NULL){
        //////cout<<"par of node "<<node->key <<" is "<<node->par->key<<endl;
    }
    else{
        //////cout<<"no par"<<endl;
    }
    if(node->left!=NULL){
        //////cout<<"left of node "<<node->key <<" is "<<node->left->key<<endl;
    }
    else{
        //////cout<<"no left"<<endl;
    }
    if(node->right!=NULL){
        //////cout<<"right of node "<<node->key <<" is "<<node->right->key<<endl;
    }
    else{
        //////cout<<"no right"<<endl;
    }
    inorder(node->right);
    return;
}
// int main()
// {
//     SymbolTable *s = new SymbolTable();
//     s->insert("a");
//     //////cout << "mainsns......" << endl;
//     s->insert("b");
//     //////cout << "mainsnsd......" << endl;
//     //////cout << s->get_size() << endl;
//     //////cout << "mai2sbxn....." << endl;
//     // s->insert("c");

//     // s->insert("d");
//     // // // //////cout << "eeeee" << endl;
//     // s->insert("g");
//     // s->insert("h");
//     // s->insert("e");
//     // s->insert("f");
//     //////cout << "insert complete.............................." << endl;
//     // s->remove("b");
//     //////cout<<"enter the remoaval of c"<<endl;
//     // s->remove("c");
//     s->remove("a");
//     // s->remove("d");

//     // //////cout<<s->get_root()->left->key<<endl;
//     // //////cout<<"hi"<<endl;
//     // //////cout<<s->get_root()->left->right->key<<endl;
//     // s->insert("g");
//     ////cout << "here size of the symtable is " << s->get_size() << endl;
//     ////cout << "here root of the symtable is " << s->get_root()->key << endl;
//     // //////cout << "here root of the symtable is " << s->get_root()->left->right->key << endl;
//     inorder(s->get_root());
// }