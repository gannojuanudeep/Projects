/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"
// #include <bits/stdc++.h>
// using namespace std;
void postord(SymEntry *root)
{
  if (root == NULL)
  {
    return;
  }
  else
  {
    postord(root->left);
    postord(root->right);
    delete (root);
  }
}
void SymbolTable::insert(string k, UnlimitedRational *v)
{
  SymEntry *temp = root;
  SymEntry *inse = new SymEntry(k, v);
  //    SymEntry* temp1;
  if (size == 0)
  {
    // cout << "geto" << endl;
    root = inse;
    size++;
    // delete inse;
    return;
  }
  while (temp != NULL)
  {
    if (temp->key > k)
    {
      // temp1=temp;
      // cout<<"run"<<endl;
      if (temp->left == NULL)
      {
        temp->left = inse;
        size++;
        // delete inse;
        return;
      }
      temp = temp->left;
    }
    else
    {
      // temp1=temp;
      // cout<<"run2"<<endl;
      if (temp->right == NULL)
      {
        temp->right = inse;
        size++;
        // delete inse;
        return;
      }
      temp = temp->right;
    }
  }
}
void SymbolTable::remove(string k)
{ 
  SymEntry *temp = root;
  // int check;
  SymEntry *temp1 = NULL;
  if (size == 0)
  {
    return;
  }
  while (temp->key != k)
  {
    // check=0;
    if (temp->key > k)
    {
      temp1 = temp;
      if (temp->left == NULL)
      {
        return;
      }
      temp = temp->left;
      // check=1;
    }
    else
    {
      temp1 = temp;
      if (temp->right == NULL)
      {

        return;
      }
      temp = temp->right;
      // check=-1;
    }
  }
  // if(check==1){

  if (temp->left != NULL)
  {
    SymEntry *c = temp->left;
    SymEntry *d = NULL;
    if (c->right == NULL)
    {
      temp1->left = c;
      c->right = temp->right;
    }
    else
    {
      while (c->right != NULL)
      {
        d = c;
        c = c->right;
      }
      if (c->left == NULL)
      {
        temp1->left = c;
        c->right = temp->right;
        c->left = temp->left;
        d->right = NULL;
      }
      else
      {
        d->right = c->left;
        temp1->left = c;
        c->right = temp->right;
        c->left = temp->left;
      }
    }
  
  }
  else
  {
    temp1->left = temp->right;
   // should we need to call destructor of exprtree node 
  }
    temp->left = NULL;
    temp->right = NULL;
    delete temp;
  size--;
  return;
}
UnlimitedRational *SymbolTable::search(string k)
{
  SymEntry *temp = root;
  // if(root==NULL){
  //   return;
  // }
  while (temp->key != k)
  {
    if (temp->key > k)
    {
      temp = temp->left;
    }
    else
    {
      temp = temp->right;
    }
  }
  return temp->val;
}
int SymbolTable::get_size()
{
  return size;
}
SymEntry *SymbolTable::get_root()
{
  return root;
}
SymbolTable::SymbolTable()
{
  size = 0;
  root = NULL;
}
SymbolTable::~SymbolTable()
{
  // cout<<"sym"<<endl;
  if (root)
  {
    // cout<<"root"<<endl;
    delete root;
  }
  size=0;
}

// int main(){
//   SymbolTable a;
//   UnlimitedInt* num=new UnlimitedInt("5");
//   UnlimitedInt* den=new UnlimitedInt("9");
//   UnlimitedRational* p=new UnlimitedRational(num,den);
//    UnlimitedInt* num1=new UnlimitedInt("6");
//   UnlimitedInt* den1=new UnlimitedInt("11");
//   UnlimitedRational* p1=new UnlimitedRational(num1,den1);
//   a.insert("x",p);
//   a.insert("y",p1);
//  cout<<a.get_size()<<endl;
//  cout<<a.get_root()->val->get_frac_str()<< " "<<a.get_root()->key<<endl;
//  cout<<a.search("y")->get_frac_str()<<endl;
//  cout<<a.get_root()->right->key<<endl;
// // a.~SymbolTable();
// // delete num;
// // delete den;
// // delete p;
// // delete num1;
// // delete den1;
// // delete p1;
// }