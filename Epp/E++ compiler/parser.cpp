/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "parser.h"
// #include<iostream>
// using namespace std;
//Write your code below this line
int stroi(string s){
  int sum=0;
  for(int i=0;i<s.size();i++){
    sum+=(s[i]-'0');
    sum*=10;
  }
  return sum/10;
}
ExprTreeNode *parsetree(vector<string> s)
{
    vector<ExprTreeNode *> stack;
    ExprTreeNode *temp=new ExprTreeNode();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == "(")
        {
            // //cout<<"rr"<<endl;
            ExprTreeNode* a=new ExprTreeNode();
          temp->left=a;  
            stack.push_back(temp);
            temp=a;
            // //cout<<stack.size()<<endl;
          
        }
        else if (s[i] == ")")
        {
            // //cout<<"ty"<<endl;
            // //cout<<stack.size()<<endl;
            if(!stack.empty()){
            temp = stack.back();
            stack.pop_back();
            }
        }
        else if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/")
        {
            // //cout<<"gueg"<<endl;
            // //cout<<stack.size()<<endl;
            if (s[i] == "+")
            {
                temp->type = "ADD";
            }
            else if (s[i] == "-")
            {
                temp->type = "SUB";
            }
            else if (s[i] == "*")
            {
                temp->type = "MUL";
            }
            else
            {
                temp->type = "DIV";
            }
            // UnlimitedInt* h=NULL;
            ExprTreeNode *a = new ExprTreeNode();
            temp->right = a;
             stack.push_back(temp);
            temp = a;
           
        }
        else
        {
            // //cout<<"gfds"<<endl;
            // //cout<<stack.size()<<endl;
            int y = 1;
            for (int j = 0; j < s[i].size(); j++)
            {
                // //cout<<"anu"<<endl;
                if (int(s[i][j] - '0') > 9 || int(s[i][j] - '0') < 0)
                {
                    if (s[i][j] == '-')
                    {
                        continue;
                    }
                    y = 0;
                    break;
                }
            }
            // //cout<<s[i]<<endl;
            // //cout<<y<<endl;
            // //cout<<"tony"<<endl;
            if (y)
            {
                //  //cout<<"tony1"<<endl;
                
                // //cout<<"tony3"<<endl;
                temp->type = "VAL";
                temp->num=stoi(s[i]);
                // //cout<<"tony4"<<endl;
                if(!stack.empty()){
                temp=stack.back();
                stack.pop_back();
                }
                // //cout<<"tony5"<<endl;
                
            
            }
            else
            {
                //  //cout<<"tony1"<<endl;
                temp->id = s[i];
                // //cout<<"tony1"<<endl;
                temp->type = "VAR";
                // //cout<<"tony1"<<endl;
                if(!stack.empty()){
                temp = stack.back();
                // //cout<<"tony1"<<endl;
                stack.pop_back();
                // //cout<<"tony1"<<endl;
                }
            }
        }
    }
    // //cout<<"di"<<endl;
    return temp;
}
Parser::Parser(){
symtable=new SymbolTable();
}

void Parser::parse(vector<string> expression){
      // //cout<<"bi"<<endl;
    ExprTreeNode *root = new ExprTreeNode();
    // //cout<<"hii"<<endl;
    root->type = "Equal";
    
    // //cout<<"bye1"<<endl;
    ExprTreeNode *le = new ExprTreeNode();
     if(expression[0]=="del"){
        le->type="DEL";
     }
     else if(expression[0]=="ret"){
        le->type="RET";
     }
     else{
        le->id=expression[0];
        le->type="VAR";
     }
   
    root->left = le;
    // //cout<<"hii3"<<endl;
    vector<string> k(expression.size()-2);
    for (int i = 2; i < expression.size(); i++)
    {
        k[i - 2] = expression[i];
        // //cout<<k[i-2]<<" ";
    }
    // //cout<<endl;
    // //cout<<"hii4"<<endl;
    ExprTreeNode *ri = parsetree(k);
    // //cout<<"hii5"<<endl;
    root->right = ri;
    // //cout<<"hii6"<<endl;
    expr_trees.push_back(root);
    // //cout<<"hii7"<<endl;
    // //cout<<"bi1"<<endl;UnlimitedInt*) 
}

Parser::~Parser(){ 
  if(symtable){
    delete symtable;
  }
   for (int i = 0; i < expr_trees.size(); i++)
    {
        ExprTreeNode* temp=expr_trees[i];
       delete temp;
    }
}
void inorder(ExprTreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    inorder(node->left);
    //cout << node->type << endl;
    inorder(node->right);
    return;
}

// int main(){
//   Parser p;
//   vector<string> s={"a",":=","(","1","+","2",")"};
//  p.parse(s);
//   //cout<<p.expr_trees.back()->left->id<<endl;
//   inorder(p.expr_trees.back());

// }