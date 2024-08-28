/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"

//Write your code below this line

ExprTreeNode::ExprTreeNode(){
  type="";
  id="";
  num=0;
  left=NULL;
  right=NULL;
}

ExprTreeNode::ExprTreeNode(string t,int v){
    
        type="VAL";
        num=v;
        id="";
   
}
ExprTreeNode::~ExprTreeNode(){
 if(left){
  delete left;
  }
  if(right){
    delete right;
  }
}

