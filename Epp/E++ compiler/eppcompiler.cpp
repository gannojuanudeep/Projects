/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "eppcompiler.h"
// #include<iostream>
// #include<fstream>
// using namespace std;
// Write your code below this line
vector<string> right_postord(ExprTreeNode *node, Parser &p, vector<string> &v)
{ // id should only store variables and num should only store values;
// cout<<"enetr right postorder"<<endl;
// cout<<node->type<<endl;
// cout<<v.size()<<endl;
    if (node->left == NULL && node->right == NULL)
    {
        // cout<<"enetr if"<<endl;
        if (node->type == "VAR")
        {
            // cout<<"enetred"<<endl;
            int d = p.symtable->search(node->id);
            // cout<<"d "<<d<<endl;
            v.push_back("PUSH mem[" + to_string(d) + "]");
            return v;
        }
        else
        {
            // cout<<"hisd"<<endl;
            // cout<<node->num<<endl;
            v.push_back("PUSH " + to_string(node->num));
            string s=v.back();
            // cout<<s<<endl;
            // cout<<"jidf"<<endl;
            return v;
        }
       
    }
    else
    {
        // cout<<"right enetr"<<endl;
        right_postord(node->right, p, v);
        // cout<<"enetr left"<<endl;
        right_postord(node->left, p, v);
        // cout<<"exit left"<<endl;
        if (node->type == "ADD")
        {
            v.push_back("ADD");
            
        }
        else if (node->type == "SUB")
        {
            v.push_back("SUB");
        }
        else if (node->type == "MUL")
        {
            v.push_back("MUL");
        }
        else if (node->type == "DIV")
        {
            v.push_back("DIV");
        }
        return v;
    }
}
EPPCompiler::EPPCompiler()
{
    memory_size = 0;
    output_file = "";
}

EPPCompiler::EPPCompiler(string out_file, int mem_limit)
{
    // cout<<"entr sonstr"<<endl;
    output_file = out_file;
    memory_size = mem_limit;
    for (int i = 0; i < mem_limit; i++)
    {
        mem_loc.push_back(i) ;
    }
}

void EPPCompiler::compile(vector<vector<string>> code)
{
    // cout<<"comppile enter"<<endl;
    // cout<<code.size()<<endl;
    for (int i = 0; i < code.size(); i++)
    {
        // cout<<"for loop"<<endl;
        targ.parse(code[i]);
        // cout<<"here"<<endl;
        if (code[i][0] == "del")
        {
            // int d;
            // d = targ.symtable->search(code[i][2]);
            // cout<<"d push back afterr dleteion "<<d<<endl;
            // mem_loc.push_back(d);
            // targ.symtable->remove(code[i][2]);
        }
        else if (code[i][0] == "ret")
        {
        }
        else
        {
            // cout<<"enter else"<<endl;
            if (targ.symtable->search(code[i][0]) == -2) // reassign?
            {
                // cout<<"search comp"<<endl;
                int idx = mem_loc.back();
                // cout<<idx<<endl;
                mem_loc.pop_back();
                // cout<<"pop comp"<<endl;
                targ.symtable->insert(code[i][0]);
                // cout<<"insert comp"<<endl;
                // cout<<targ.symtable->get_size()<<endl;
                // cout<<targ.symtable->get_root()->key<<endl;
                targ.symtable->assign_address(code[i][0], idx);
            }
            // cout<<"exited"<<endl;
        }
        //   cout<<"writing error"<<endl;
          vector<string> vec=generate_targ_commands();
        //   for(auto b:vec){
        //     cout<<b<<endl;
        //   }
        write_to_file(vec);

    }
}

vector<string> EPPCompiler::generate_targ_commands() // what should we write for equal symbol
{
    vector<string> v;
    // cout<<"generate commads enetr"<<endl;
    ExprTreeNode *temp = targ.expr_trees.back();
    // cout<<temp->left->id<<endl;
    // cout<<"line 1"<<endl;
    if (temp->left->type == "DEL")
    {
        int l = targ.symtable->search(temp->right->id);
        v.push_back("DEL = mem[" + to_string(l) + "]");
        mem_loc.push_back(l);
        targ.symtable->remove(temp->right->id);
        return v; // can we use to_string
    }
    else if (temp->left->type == "RET")
    {
        right_postord(temp->right, targ, v);
        v.push_back("RET = POP");
        return v;
    }
    else
    {
        // cout<<"else enter"<<endl;
        right_postord(temp->right, targ, v); 
        // cout<<"right psot comp"<<endl;// can we pass targ
        int d = targ.symtable->search(temp->left->id);
        v.push_back("mem[" + to_string(d) + "] = POP");
        return v;
    }
}

void EPPCompiler::write_to_file(vector<string> commands)
{
    // string file="output_file.txt";
    // cout<<"enter wtf"<<endl;
    ofstream outputfile;
    outputfile.open(output_file,ios::out|ios::app);
//     if (!outputfile.is_open()) {
//     // Handle the case where the file couldn't be opened.
//     std::cerr << "Error: Couldn't open the file." << std::endl;
//     // Return an error code, if needed.
// }
    for (const auto &c : commands)
    {
        outputfile << c << "\n";
    }
    outputfile.close();
    // cout<<"completed"<<endl;
}

EPPCompiler::~EPPCompiler()
{
}

// int main(){
//     // cout<<"hi"<<endl;
//     string out="text6.txt";
//     int t=5;
//     // cout<<"yo"<<endl;
//     EPPCompiler* com=new EPPCompiler(out,t);
//     // cout<<"enter"<<endl;
//     vector<vector<string>> vec(7);
    
//     vec[0]={"x",":=","3"};
//      vec[1]=   {"y",":=","5"};
//      vec[2]=   {"z",":=","7"};
//      vec[3]=   {"del",":=","x"};
//      vec[4]=   {"del",":=","y"};
//      vec[5]=   {"w",":=","(","5","+","(","z","/","2",")",")"};
//      vec[6]=   {"ret",":=","w"};
//     com->compile(vec);
// }