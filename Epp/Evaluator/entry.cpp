/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "entry.h"

SymEntry::SymEntry(){
    key="";
    val=NULL;
     left=NULL;
     right=NULL;
}
SymEntry::SymEntry(string k, UnlimitedRational* v){
    key=k;
    val=v;
     left=NULL;
         right=NULL;
}
SymEntry::~SymEntry(){
    if(val){
    delete val;
    }
    if(left){
    delete left;
    }
    if(right){
    delete right;
    }
}