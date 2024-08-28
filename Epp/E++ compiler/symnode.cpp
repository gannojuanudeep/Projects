/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symnode.h"
// #include <iostream>
// using namespace std;
// Write your code below this line
int heightcal_node(SymNode* node){
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
SymNode::SymNode()
{
  key = "";
  height = 0;
}

SymNode::SymNode(string k)
{
  key = k;
  height = 0;
  par = NULL;
  left = NULL;
  right = NULL;
}

// SymNode *LLR(SymNode* node) {
//   SymNode *temp = node->right;
//   temp->par = node->par;
//   node->right = temp->left;
//   if(temp->left != NULL) temp->left->par = node;
//   temp->left = node;
//   node->par = temp;

//   node->height = max(node->left == nullptr ? -1 : node->left->height, node->right == nullptr ? -1 : node->right->height) + 1;
//   temp->height = max(temp->left == nullptr ? -1 : temp->left->height, temp->right == nullptr ? -1 : temp->right->height) + 1;

//   return temp;
// }

SymNode *SymNode::LeftLeftRotation()
{
  //cout<<this->key<<" kaks"<<endl;
  SymNode *temp=this->left;
  temp->par=this->par;
  this->par=temp;
  this->left=temp->right;
  if(temp->right!=NULL){
    temp->right->par=this;
  }
  temp->right=this;
  if(temp->par!=NULL){
    if(temp->par->left==this){
      temp->par->left=temp;
    }
    else{
      temp->par->right=temp;
    }
  }
  heightcal_node(temp);
  heightcal_node(temp->right);
  // cout << "here1" << endl;

  // cout << this->key << " " << this->right->key << endl;

  // this->left->par = this->par;
  // this->par = this->left;
  // this->left = this->left->right;
  //   cout << "here2" << endl;

  // if (this->par->right != NULL)
  // {
  //   this->par->right->par = this;
  // }
  // this->par->right = this;
  // if (this->par->par != NULL)
  // {
  //   //cout<<"gojo"<<endl;
  //   //cout<<this->par->par->key<<endl;
  //   //cout<<this->par->par->left->key<<endl;
  //   //cout<<this->par->key<<endl;
  //   //cout<<this->par->left->key<<endl;
  //   //cout<<this->key<<endl;
  //   if (this->par->par->left == this)
  //   {
  //     //cout<<"naruto"<<endl;
  //     this->par->par->left = this->par;
  //   }
  //   else
  //   {
  //     //cout<<"itachi"<<endl;
  //     //cout<<this->par->key<<endl;
  //     this->par->par->right = this->par;
  //     //cout<<this->par->par->right->key<<endl;
  //   }
  // }
  //   cout << "here3" << endl;

  // int a, b;
  // if (this->left != NULL)
  // {
  //   a = this->left->height;
  // }
  // else
  // {
  //   a = -1;
  // }
  // if (this->right != NULL)
  // {
  //   b = this->right->height;
  // }
  // else
  // {
  //   b = -1;
  // }
  //  //cout<<"here a and b are "<<a<<" "<<b<<endl;
  //  //cout<<this->key<<endl;
  // this->height = max(a, b) + 1;
  // if (this->par->left != NULL)
  // {
  //   a = this->par->left->height;
  // }
  // else
  // {
  //   a = -1;
  // }
  // if (this->par->right != NULL)
  // {
  //   b = this->par->right->height;
  // }
  // else
  // {
  //   b = -1;
  // }
  //  //cout<<"here a and b are "<<a<<" "<<b<<endl;
  //  //cout<<this->par->key<<endl;
  // this->par->height = max(a, b) + 1;
  return temp;
}

SymNode *SymNode::RightRightRotation()
{ // need to check
  // //cout << "enter rrr" << endl;
  // if(this->par!=NULL){
    // if(this->par!=NULL){
    //   //cout<<this->par->key<<endl;
    // }
    //cout<<this->key<<endl;
    SymNode *temp=this->right;
    temp->par=this->par;
    this->par=temp;
    this->right=temp->left;
    if(temp->left!=NULL){
      temp->left->par=this;
    }
    temp->left=this;
    if(temp->par!=NULL){
    if(temp->par->left==this){
      temp->par->left=temp;
    }
    else{
      temp->par->right=temp;
    }
  }
  heightcal_node(temp);
  heightcal_node(temp->left);
  return temp;
  // this->right->par = this->par;
  // }
  // else{

  // }
  // //cout << "1st if" << endl;
  // if(this->right!=NULL){
  // this->par = this->right;
  // // }
  // // else{
  // //   this->par=NULL;
  // // }
  // // //cout << "2st if" << endl;
  // // if(this->right->left!=NULL){
  // this->right = this->right->left;
  // // }
  // // else{
  // //   this->right==NULL;
  // // }
  // // //cout << "3st if" << endl;
  // // //cout << this->par->key << endl;
  // if (this->par->left != NULL)
  // {
  //   //cout<<"king enetr"<<endl;
  //   this->par->left->par = this;
  // }
  // // //cout << "4st if" << endl;
  // this->par->left = this;
  // // //cout << "5st if" << endl;
  // if (this->par->par != NULL)
  // {
  //   //cout<<"SHIFT"<<endl;
  //   if(this!=NULL){
  //       //cout<<this->key<<endl;
  //     }
  //     if(this->par!=NULL){
  //       //cout<<this->par->key<<endl;
  //     }
  //     //cout<<this->par->par->left->key<<endl;
  //   if (this->par->par->left== this)
  //   {
  //     //cout<<"hdg"<<endl;
      
  //     this->par->par->left = this->par;
  //     //cout<<this->par->par->left->key<<endl;
  //     //cout<<"lkkkgfdhn"<<endl;
  //   }
  //   else
  //   {
  //     //cout<<"fgs"<<endl;
  //     this->par->par->right = this->par;
  //   }
  // }
  // // //cout << "6st if" << endl;

  // int a, b;
  // if (this->left != NULL)
  // {
  //   a = this->left->height;
  // }
  // else
  // {
  //   a = -1;
  // }
  // if (this->right != NULL)
  // {
  //   b = this->right->height;
  // }
  // else
  // {
  //   b = -1;
  // }
  //  //cout<<"here a and b are "<<a<<" "<<b<<endl;
  //  //cout<<this->key<<endl;
  // this->height = max(a, b) + 1;
  // if (this->par->left != NULL)
  // {
  //   a = this->par->left->height;
  // }
  // else
  // {
  //   a = -1;
  // }
  // if (this->par->right != NULL)
  // {
  //   b = this->par->right->height;
  // }
  // else
  // {
  //   b = -1;
  // }
  //  //cout<<"here a and b are "<<a<<" "<<b<<endl;
  //  //cout<<this->par->key<<endl;
  // this->par->height = max(a, b) + 1;
  // return this->par;
}

SymNode *SymNode::LeftRightRotation()
{
  // int a,b;
  // if(this->left->right->left!=NULL){
  //   a=this->left->right->left->height;
  // }
  // else{
  //   a=-1;
  // }
  // if(this->left->right->right!=NULL){
  //   b=this->left->right->right->height;
  // }
  // else{
  //   b=-1;
  // }
  // if(a>b){
  //  this->right->left->LeftLeftRotation();
  // }
 SymNode *l= this->left->RightRightRotation();
 //cout<<l->key<<endl;
 //cout<<l->left->key<<endl;
 //cout<<l->par->left->key<<endl;
 //cout<<"first"<<endl;
 SymNode *k= this->LeftLeftRotation();
 //cout<<k->key<<endl;
 //cout<<k->par->right->key<<endl;
 //cout<<this->par->key<<endl;
 //cout<<this->par->right->key<<endl;
 //cout<<"second"<<endl;
  return this->par;
}

SymNode *SymNode::RightLeftRotation()
{
  // int a,b;
  // if(this->right->left->left!=NULL){
  //   a=this->right->left->left->height;
  // }
  // else{
  //   a=-1;
  // }
  // if(this->right->left->right!=NULL){
  //   b=this->right->left->right->height;
  // }
  // else{
  //   b=-1;
  // }
  // if(a<b){
  //   //cout<<"kohli"<<endl;
  // SymNode* j= this->right->left->RightRightRotation();
  // //cout<<j->key<<endl;
  // }
  //cout<<"end a<b"<<endl;
   SymNode *l= this->right->LeftLeftRotation();
 //cout<<l->key<<endl;
 //cout<<l->left->key<<endl;
 //cout<<l->par->left->key<<endl;
 //cout<<"first"<<endl;
 SymNode *k= this->RightRightRotation();
  ////cout<<k->key<<endl;
//  //cout<<k->par->right->key<<endl;
 //cout<<this->par->key<<endl;
 //cout<<this->par->right->key<<endl;
 //cout<<"second"<<endl;
  return this->par;
}

SymNode::~SymNode()
{ // check destructors
  if(left){
  delete left;
  }
  if(right){
    delete right;
  }
  
}