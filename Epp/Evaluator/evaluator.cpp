/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "evaluator.h"
#include<bits/stdc++.h>
using namespace std;
void postord(ExprTreeNode* root){
   if(root==NULL){
    return;
   }
   else{
     postord(root->left);
     postord(root->right);
    delete root;
   }
 }
UnlimitedRational *evaluate(ExprTreeNode *root, SymbolTable *sym)
{
    // cout<<"evaluate function  enter"<<endl;

    if (root->left == NULL && root->right == NULL)
    {
        // cout<<"base case"<<endl;
        if (root->type == "VAR" )
        {
            UnlimitedRational *k = sym->search(root->id);
            UnlimitedRational* h=new UnlimitedRational(k->get_p(),k->get_q()); //here
            return h;
        }
        else
        {
            // cout<<"value"<<endl;
            // cout<<root->val->get_frac_str()<<endl;
            UnlimitedRational* f=new UnlimitedRational(root->val->get_p(),root->val->get_q()); //here
            return f;
        }
    }

    else
    {
        // cout<<"else"<<endl;
        if (root->type == "ADD")
        {
            UnlimitedRational* tempee1=evaluate(root->left, sym);
            UnlimitedRational* tempee2=evaluate(root->right, sym);
            UnlimitedRational *res = res->add(tempee1, tempee2);
            UnlimitedRational *eva= new UnlimitedRational(res->get_p(),res->get_q());
            root->evaluated_value=eva;
            delete tempee1;
            delete tempee2;
            return res;
        }
        else if (root->type == "SUB")
        {
             UnlimitedRational* tempee1=evaluate(root->left, sym);
            UnlimitedRational* tempee2=evaluate(root->right, sym);
            UnlimitedRational *res = res->sub(tempee1,tempee2);
             UnlimitedRational *eva= new UnlimitedRational(res->get_p(),res->get_q());
            root->evaluated_value=eva;
            delete tempee1;
            delete tempee2;
            return res;
        }
        else if (root->type == "MUL")
        {
             UnlimitedRational* tempee1=evaluate(root->left, sym);
            UnlimitedRational* tempee2=evaluate(root->right, sym);
            UnlimitedRational *res = res->mul(tempee1,tempee2);
             UnlimitedRational *eva= new UnlimitedRational(res->get_p(),res->get_q());
            root->evaluated_value=eva;
            delete tempee1;
            delete tempee2;
            return res;
        }
        else if (root->type == "DIV")
        {
             UnlimitedRational* tempee1=evaluate(root->left, sym);
            UnlimitedRational* tempee2=evaluate(root->right, sym);
            UnlimitedRational *res = res->div(tempee1,tempee2);
             UnlimitedRational *eva= new UnlimitedRational(res->get_p(),res->get_q());
            root->evaluated_value=eva;
            delete tempee1;
            delete tempee2;
            return res;
        }
    }
}
ExprTreeNode *parsetree(vector<string> s)
{
    vector<ExprTreeNode *> stack;
    ExprTreeNode *temp=new ExprTreeNode();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == "(")
        {
            // cout<<"rr"<<endl;
            ExprTreeNode* a=new ExprTreeNode();
          temp->left=a;  
            stack.push_back(temp);
            temp=a;
            // cout<<stack.size()<<endl;
          
        }
        else if (s[i] == ")")
        {
            // cout<<"ty"<<endl;
            // cout<<stack.size()<<endl;
            if(!stack.empty()){
            temp = stack.back();
            stack.pop_back();
            }
        }
        else if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/")
        {
            // cout<<"gueg"<<endl;
            // cout<<stack.size()<<endl;
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
            // cout<<"gfds"<<endl;
            // cout<<stack.size()<<endl;
            int y = 1;
            for (int j = 0; j < s[i].size(); j++)
            {
                // cout<<"anu"<<endl;
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
            // cout<<s[i]<<endl;
            // cout<<y<<endl;
            // cout<<"tony"<<endl;
            if (y)
            {
                //  cout<<"tony1"<<endl;
                UnlimitedInt *one = new UnlimitedInt("1");
                UnlimitedInt *nu = new UnlimitedInt(s[i]);
                // cout<<"tony2"<<endl;
                temp->val = new UnlimitedRational(nu, one);
                // cout<<"tony3"<<endl;
                temp->type = "VAL";
                // cout<<"tony4"<<endl;
                
                if(!stack.empty()){
                temp=stack.back();
                stack.pop_back();
                }
                // cout<<"tony5"<<endl;
                delete one;
                delete nu;
            
            }
            else
            {
                //  cout<<"tony1"<<endl;
                temp->id = s[i];
                // cout<<"tony1"<<endl;
                temp->type = "VAR";
                // cout<<"tony1"<<endl;
                if(!stack.empty()){
                temp = stack.back();
                // cout<<"tony1"<<endl;
                stack.pop_back();
                // cout<<"tony1"<<endl;
                }
            }
        }
    }
    // cout<<"di"<<endl;
    return temp;
}
void Evaluator::parse(vector<string> code)
{
    // cout<<"bi"<<endl;
    ExprTreeNode *root = new ExprTreeNode();
    // cout<<"hii"<<endl;
    root->type = "Equal";
    root->id = code[1];
    UnlimitedInt *h = NULL;
    // cout<<"bye1"<<endl;
    ExprTreeNode *le = new ExprTreeNode("VAR", h);
    // cout<<"hii2"<<endl;
    le->id = code[0];
    root->left = le;
    // cout<<"hii3"<<endl;
    vector<string> k(code.size()-2);
    for (int i = 2; i < code.size(); i++)
    {
        k[i - 2] = code[i];
        // cout<<k[i-2]<<" ";
    }
    // cout<<endl;
    // cout<<"hii4"<<endl;
    ExprTreeNode *ri = parsetree(k);
    // cout<<"hii5"<<endl;
    root->right = ri;
    // cout<<"hii6"<<endl;
    expr_trees.push_back(root);
    // cout<<"hii7"<<endl;
    // cout<<"bi1"<<endl;UnlimitedInt*) 
}
void Evaluator::eval()
{
    // cout<<"ci"<<endl;
    // cout<<"gojo"<<endl;
    // cout<<expr_trees.back()->type<<endl;
    // cout<<expr_trees.back()->id<<endl;
    // cout<<expr_trees.back()->left->id<<endl;
    // cout<<expr_trees.back()->right->type<<endl;
    // cout<<symtable->get_size()<<endl;
   
    UnlimitedRational *val = evaluate(expr_trees.back()->right, symtable);
    // cout<<"hiiiiii"<<endl;
    UnlimitedRational* n=new UnlimitedRational(val->get_p(),val->get_q());
    UnlimitedRational *fd =new UnlimitedRational(val->get_p(),val->get_q());
    // cout<<val->get_frac_str()<<endl;
    // cout<<"jjk"<<endl;
    string key = expr_trees.back()->left->id;
    // cout<<key<<endl;
    // cout<<"naruto"<<endl;
    expr_trees.back()->left->evaluated_value=n;
    expr_trees.back()->evaluated_value=fd;
    // cout<<"king"<<endl;
    symtable->insert(key, val);
    // cout<<"kohli"<<endl;
    // cout<<symtable->get_size()<<endl;
    //  cout<<symtable->search("v")->get_frac_str()<<endl;
}
Evaluator::Evaluator()
{
    symtable =new SymbolTable();
    vector<ExprTreeNode*> expr_trees={};
}
Evaluator::~Evaluator()
{            
    // cout<<"hi"<<endl;
    if(symtable){      // check
    delete symtable;
    } // check symtable;
    // cout<<"evad<"<<endl;
    for (int i = 0; i < expr_trees.size(); i++)
    {
        ExprTreeNode* temp=expr_trees[i];
       delete temp;
    }
}
// int main(){
//     vector<string>code1{"v",":=","(","-13","+","(","2","/","51",")",")"};//v:=(13+(2/51))
//     cout<<code1[0]<<endl;
//     Evaluator e;
//     cout<<"hi"<<endl;
//     e.parse(code1);
//     cout<<"bye"<<endl;
//     e.eval();
//     cout<<"hello"<<endl;
//     ExprTreeNode* tree=e.expr_trees.back();
//     cout<<e.expr_trees.size()<<endl;
//     cout<<"ke"<<endl;
//     cout<<tree->left->evaluated_value->get_frac_str()<<endl;
//     cout<<"end"<<endl;
//     vector<string> code2{"g",":=","(","2","*","v",")"};
//     cout<<"ere"<<endl;
//     e.parse(code2);
//     cout<<"here"<<endl;
//     e.eval();
//     cout<<"here2"<<endl;
//     tree=e.expr_trees.back();
//     cout<<tree->left->evaluated_value->get_frac_str()<<endl;
// //     g:=(2*v)
// // x:=(g+6)
// // y:=x
//     vector<string> code3{"x",":=","(","g","+","6",")"};
//     e.parse(code3);
//     e.eval();
//     tree=e.expr_trees.back();
//     cout<<tree->left->evaluated_value->get_frac_str()<<endl;
//     vector<string> code4{"y",":=","x"};
//     e.parse(code4);
//     e.eval();
//     tree=e.expr_trees.back();
//     cout<<tree->left->evaluated_value->get_frac_str()<<endl;
//     cout<<"hi"<<endl;
//     cout<<e.expr_trees.size()<<endl;
//     cout<<e.symtable->get_size()<<endl;
//     for (int i = 0; i < e.expr_trees.size(); i++)
//     {
//         cout<<e.expr_trees[i]->left->id<<" "<<e.expr_trees[i]->left->type<<" "<<e.expr_trees[i]->left->evaluated_value->get_frac_str()<<endl;
//     }
    
//     cout<<"hi"<<endl;
//     // vector<string> code5{"pow5",":=","(","(","5","","42",")","/","(","pow4","","pow4",")",")"};
//     // e.parse(code5);
//     // e.eval();
//     // tree=e.expr_trees.back();
//     // cout<<tree->left->evaluated_value->get_frac_str()<<endl;
// }
