/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"
// #include<iostream>
// using namespace std;


ExprTreeNode:: ExprTreeNode(){
  type="";
  id="";
  val=NULL;
  evaluated_value=NULL;
  left=NULL;
  right=NULL;
   } 
ExprTreeNode::ExprTreeNode(string t, UnlimitedInt* v){
      if(t!="VAL"){
        type=t;
         id="";
  val=NULL;
  evaluated_value=NULL;
  left=NULL;
  right=NULL;
    }
    else{
   type=t;
   UnlimitedInt* one=new UnlimitedInt("1");
   val=new UnlimitedRational(v,one);
     evaluated_value=NULL;
  left=NULL;
  right=NULL;
  id="";
    }
   }
   ExprTreeNode:: ExprTreeNode(string t, UnlimitedRational* v){
    if(t!="VAL"){
        type=t;
         id="";
  val=NULL;
  evaluated_value=NULL;
  left=NULL;
  right=NULL;
    }
    else{
   type=t;
   val=v;
   evaluated_value=NULL;
  left=NULL;
  right=NULL;
  id="";
   }
   }
   ExprTreeNode::  ~ExprTreeNode(){
    // cout<<"exprd3"<<endl;
    if(val){
   delete val;
    }
    // cout<<"exprd"<<endl;
    if(evaluated_value){
   delete evaluated_value;
    }
    // cout<<"exprd1"<<endl;
    if(left){
   delete left;
    }
    // cout<<"exprd4"<<endl;
    if(right){
   delete right;
    }
    // cout<<"exprd5"<<endl;

   }