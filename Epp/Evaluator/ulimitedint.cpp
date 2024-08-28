/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include <iostream>
using namespace std;
#include "ulimitedint.h"
int comp(int *a,int n1, int *b,int n2)
{ /// doesnt check sign
    if (n1 > n2)
    {
        return 1;
    }
    else if (n1 < n2)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < n1; i++)
        {
            if (a[n1 - i - 1] > b[n1 - i - 1])
            {
                return 1;
            }
            else if (a[n1 - i - 1] < b[n1 - i - 1])
            {
                return 0;
            }
        }
        return 2;
    }
}
int *checkzeros(int *a, int n)
{
    int i = n - 1;
    while (i > 0)
    {
        if (a[i] == 0)
        {
            i--;
        }
        else
        {
            break;
        }
    }
    if (i == n - 1)
    {
        return a;
    }
    else
    {
        int *b = new int[i + 1];
        for (int j = 0; j < i + 1; j++)
        {
            b[j] = a[j];
        }
        delete [] a;
        return b;
    }
}
int *adder(int *a, int n1, int *b, int n2)
{
    int c = max(n1, n2);
    int d = min(n1, n2);
    int *temparr = new int[c + 1];
    int carry = 0;
    for (int i = 0; i < c; i++)
    {
        if (i < d)
        {
            temparr[i] = (a[i] + b[i] + carry) % 10;
            carry = (a[i] + b[i] + carry) / 10;
        }
        else
        {
            if (n1 > n2)
            {
                temparr[i] = (a[i] + carry) % 10;
                carry = (a[i] + carry) / 10;
            }
            else
            {
                temparr[i] = (b[i] + carry) % 10;
                carry = (b[i] + carry) / 10;
            }
        }
    }
    temparr[c] = carry;
        return temparr;
    
}
int *subtract(int *a, int n1, int *b, int n2)
{  
    if(comp(a,n1,b,n2)==1){
    int tempcap = n1;
    int *temparr = new int[tempcap];
    int borrow = 0;
    for (int i = 0; i < tempcap; i++)
    {
        if (i < n2)
        {
            temparr[i] = a[i] - b[i] - borrow;
            if (temparr[i] < 0)
            {
                temparr[i] += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
        }
        else
        {
            temparr[i] = a[i] - borrow;
            if (temparr[i] < 0)
            {
                temparr[i] += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
        }
    }
    return temparr;
    }
    else if(comp(a,n1,b,n2)==0){
    int tempcap = n2;
    int *temparr = new int[tempcap];
    int borrow = 0;
    for (int i = 0; i < tempcap; i++)
    {
        if (i < n1)
        {
            temparr[i] = b[i] - a[i] - borrow;
            if (temparr[i] < 0)
            {
                temparr[i] += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
        }
        else
        {
            temparr[i] = b[i] - borrow;
            if (temparr[i] < 0)
            {
                temparr[i] += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
        }
    }
    return temparr;
    }
    else if(comp(a,n1,b,n2)==2){
         int *zero1 = new int[1]{0};
       
        return zero1;
    }
}
int compare(UnlimitedInt *i1, UnlimitedInt *i2)
{ /// doesnt check sign
    if (i1->get_size() > i2->get_size())
    {
        return 1;
    }
    else if (i1->get_size() < i2->get_size())
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < i1->get_size(); i++)
        {
            if (i1->get_array()[i1->get_size() - i - 1] > i2->get_array()[i1->get_size() - i - 1])
            {
                return 1;
            }
            else if (i1->get_array()[i1->get_size() - i - 1] < i2->get_array()[i1->get_size() - i - 1])
            {
                return 0;
            }
        }
        return 2;
    }
}
int checkzeros_size(int *a, int n)
{
    int i = n - 1;
    while (i > 0)
    {
        if (a[i] == 0)
        {
            i--;
        }
        else
        {
            break;
        }
    }
    return i+1;
}
UnlimitedInt::UnlimitedInt()
{
    capacity = 0;
    size = 0;
    unlimited_int = NULL;
    sign = 0; // should we check for error while creating
}
UnlimitedInt::UnlimitedInt(int *ulimited_int, int cap, int sgn, int sz)
{
    capacity = cap;
    sign = sgn;
    size = sz;
    unlimited_int=new int[cap];
    for (int i = 0; i < cap; i++)
    {
        unlimited_int[i] = ulimited_int[i];
    }   
}
UnlimitedInt::UnlimitedInt(string s)
{
    if (s[0] == '-')
    {
        sign = -1;
        size = s.size() - 1;
        capacity = size;
        unlimited_int = new int[size];
        for (int i = 0; i < size; i++)
        {
            unlimited_int[i] = s[size - i] - '0';
        }
    }
    else if (s[0] == '0')
    {
        sign = 0;
        size = 1;
        capacity = 1;
        unlimited_int = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            unlimited_int[i] = 0;
        }
    }
    else
    {
        sign = 1;
        size = s.size();
        capacity = size;
        unlimited_int = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            unlimited_int[i] = s[size - i - 1] - '0';
        }
    }
}
UnlimitedInt ::UnlimitedInt(int i)
{
    if (i > 0)
    {
        int a = i;
        sign = 1;
        size = 0;
        while (a > 0)
        {
            size++;
            a /= 10;
        }
        capacity = size;
        int k = 0;
        unlimited_int = new int[capacity];
        while (i > 0)
        {
            unlimited_int[k] = i % 10;
            i = i / 10;
            k++;
        }
    }
    else if (i < 0)
    {
        int a = -i;
        sign = -1;
        size = 0;
        while (a > 0)
        {
            size++;
            a /= 10;
        }
        capacity = size;
        int k = 0;
        unlimited_int = new int[capacity];
        i = -i;
        while (i > 0)
        {
            unlimited_int[k] = i % 10;
            i = i / 10;
            k++;
        }
    }
    else
    {
        sign = 0;
        size = 1;
        capacity = 1;
        unlimited_int = new int[capacity];
        unlimited_int[0] = 0;
    }
}
string UnlimitedInt ::to_string()
{
    string s = "";
    if (sign == -1)
    {
        s = s + '-';
    }
    for (int i = 0; i < capacity; i++)
    {
        s = s + char('0' + unlimited_int[capacity - i - 1]);
    }
    return s;
}
int UnlimitedInt::get_size()
{
    return size;
}
int *UnlimitedInt::get_array()
{
    return unlimited_int;
}
int UnlimitedInt::get_sign()
{
    return sign;
}
int UnlimitedInt ::get_capacity()
{
    return capacity;
}
UnlimitedInt *UnlimitedInt::add(UnlimitedInt *i1, UnlimitedInt *i2)
{
    if (i1->get_sign()* i2->get_sign() >=0)
    {
        // string s1,s2;
        // if(i1->get_sign()<0){
        //  s1=i1->to_string().substr(1,i1->get_capacity());
        // }
        //  if(i2->get_sign()<0){
        //  s2=i2->to_string().substr(1,i2->get_capacity());
        // }
        // UnlimitedInt* r=new UnlimitedInt(s1);
        // UnlimitedInt* s=new UnlimitedInt(s2);
         UnlimitedInt* r=new UnlimitedInt(i1->get_array(),i1->get_capacity(),1,i1->get_capacity());
        UnlimitedInt* s=new UnlimitedInt(i2->get_array(),i2->get_capacity(),1,i2->get_capacity());
        int sgn;
       int siz=max(i1->get_capacity(),i2->get_capacity());
        int* temparray=adder(r->get_array(),r->get_capacity(),s->get_array(),s->get_capacity());
        int t=checkzeros_size(temparray,siz+1);
        int* temparr1=checkzeros(temparray,siz+1);
       
        if(i1->get_sign()>0 || i1->get_sign()<0){
            sgn=i1->get_sign();
            UnlimitedInt* res =new UnlimitedInt(temparr1,t,sgn,t);
            delete [] temparr1;
            delete r;
            delete s;
            return res;
        }
        else{
            if(i2->get_sign()!=0){
                sgn=i2->get_sign();
            UnlimitedInt* res =new UnlimitedInt(temparr1,t,sgn,t);
            delete [] temparr1;
            delete r;
            delete s;
            return res;
            }
            else{
                int *zero1 = new int[1]{0};
        UnlimitedInt *res = new UnlimitedInt(zero1, 1, 0, 1); 
        delete [] zero1; 
        delete r;
        delete s; 
        return res;
            }
        }
    }
    else if (i1->get_sign() * i2->get_sign() < 0)
    {
        UnlimitedInt* r=new UnlimitedInt(i1->get_array(),i1->get_capacity(),1,i1->get_capacity());
        UnlimitedInt* s=new UnlimitedInt(i2->get_array(),i2->get_capacity(),1,i2->get_capacity());
        int sgn;
     if(compare(i1,i2)==1){
        int siz=i1->get_capacity();
         sgn=i1->get_sign();
         int * temparray=subtract(r->get_array(),r->get_capacity(),s->get_array(),s->get_capacity());
         int t=checkzeros_size(temparray,siz);
         int* temparr1=checkzeros(temparray,siz);
         
         UnlimitedInt* res =new UnlimitedInt(temparr1,t,sgn,t);
         delete []temparr1;
         delete r;
         delete s;
            return res;
     }
     else if(compare(i1,i2)==0){
         int siz=i2->get_capacity();
         sgn=i2->get_sign();
         int * temparray=subtract(r->get_array(),r->get_capacity(),s->get_array(),s->get_capacity());
          int t=checkzeros_size(temparray,siz);
         int* temparr1=checkzeros(temparray,siz); 
         UnlimitedInt* res =new UnlimitedInt(temparr1,t,sgn,t);
         delete []temparr1;
         delete r;
         delete s;
            return res;
     }
    else if(compare(i1,i2)==2){
         int *zero1 = new int[1]{0};
        UnlimitedInt *res = new UnlimitedInt(zero1, 1, 0, 1);
        delete [] zero1;
         delete r;
         delete s;
        return res;
    } 
    }
}
UnlimitedInt *UnlimitedInt ::sub(UnlimitedInt *i1, UnlimitedInt *i2)
{
    if (i1->get_sign() * i2->get_sign() <=0)
    {
       UnlimitedInt* r=new UnlimitedInt(i1->get_array(),i1->get_capacity(),1,i1->get_capacity());
        UnlimitedInt* s=new UnlimitedInt(i2->get_array(),i2->get_capacity(),1,i2->get_capacity());
        int sgn;
       int siz=max(i1->get_capacity(),i2->get_capacity());
        int* temparray=adder(r->get_array(),r->get_capacity(),s->get_array(),s->get_capacity());
          int t=checkzeros_size(temparray,siz+1);
        int* temparr1=checkzeros(temparray,siz+1);
      
       
        if(i1->get_sign()>0 || i1->get_sign()<0){
            sgn=i1->get_sign();
            UnlimitedInt* res =new UnlimitedInt(temparr1,t,sgn,t);
            delete []temparr1;
         delete r;
         delete s;
            return res;
        }
        else{
            if(i2->get_sign()!=0){
                sgn=-(i2->get_sign());
            UnlimitedInt* res =new UnlimitedInt(temparr1,t,sgn,t);
            delete []temparr1;
         delete r;
         delete s;
            return res;
            }
            else{
                int *zero1 = new int[1]{0};
        UnlimitedInt *res = new UnlimitedInt(zero1, 1, 0, 1);
              delete [] zero1;
         delete r;
         delete s;
        return res;
            }
        }
    }
    else if (i1->get_sign() * i2->get_sign() > 0)
    {
        UnlimitedInt* r=new UnlimitedInt(i1->get_array(),i1->get_capacity(),1,i1->get_capacity());
        UnlimitedInt* s=new UnlimitedInt(i2->get_array(),i2->get_capacity(),1,i2->get_capacity());
        int sgn;
     if(compare(i1,i2)==1){
        int siz=i1->get_capacity();
         sgn=i1->get_sign();
         int * temparray=subtract(r->get_array(),r->get_capacity(),s->get_array(),s->get_capacity());
          int t=checkzeros_size(temparray,siz);
         int* temparr1=checkzeros(temparray,siz);
        
         UnlimitedInt* res =new UnlimitedInt(temparr1,t,sgn,t);
          delete []temparr1;
         delete r;
         delete s;
            return res;
     }
     else if(compare(i1,i2)==0){
         int siz=i2->get_capacity();
         sgn=-(i2->get_sign());
         int * temparray=subtract(r->get_array(),r->get_capacity(),s->get_array(),s->get_capacity());
         int t=checkzeros_size(temparray,siz);
         int* temparr1=checkzeros(temparray,siz);
         
         UnlimitedInt* res =new UnlimitedInt(temparr1,t,sgn,t);
          delete []temparr1;
         delete r;
         delete s;
            return res;
     }
    else if(compare(i1,i2)==2){
         int *zero1 = new int[1]{0};
        UnlimitedInt *res = new UnlimitedInt(zero1, 1, 0, 1);
         delete [] zero1;
         delete r;
         delete s;
        return res;
    } 
    }
}
UnlimitedInt::~UnlimitedInt()
{
    if(unlimited_int!=nullptr){
    delete[] unlimited_int;
    }
    size = 0;
    sign = 0;
    capacity = 0;
}
UnlimitedInt *UnlimitedInt::mul(UnlimitedInt *i1, UnlimitedInt *i2)
{
    if (i1->get_sign() * i2->get_sign() == 0)
    {
        int sgn = 0;
        int i = 0;
        int *temp1array = new int[1];
        temp1array[0] = 0;
        UnlimitedInt *res = new UnlimitedInt(temp1array, i + 1, sgn, i + 1);
        delete [] temp1array;
        return res;
    }
    else
    {
        int *temparray = new int[i1->get_size() + i2->get_size()]{0};

        if (i1->get_size() >= i2->get_size())
        {
            for (int i = 0; i < i2->get_size(); i++)
            {
                int carry = 0;
                for (int j = 0; j < i1->get_size(); j++)
                {
                    int f = temparray[i + j];
                    temparray[i + j] = (temparray[i + j] + (i2->get_array()[i] * i1->get_array()[j]) + carry) % 10;
                    carry = (f + i2->get_array()[i] * i1->get_array()[j] + carry) / 10;
                }
                temparray[i + i1->get_size()] = carry;
            }
            int i = i1->get_size() + i2->get_size() - 1;
            int sgn;
            while (temparray[i] == 0 && i >= 0)
            {
                i--;
            }
            int *temp1array = new int[i + 1];
            for (int j = 0; j < i + 1; j++)
            {
                temp1array[j] = temparray[j];
            }
            delete[] temparray;
            if (i1->get_sign() * i2->get_sign() > 0)
            {
                sgn = 1;
            }
            else if (i1->get_sign() * i2->get_sign() < 0)
            {
                sgn = -1;
            }

            UnlimitedInt *res = new UnlimitedInt(temp1array, i + 1, sgn, i + 1);
            delete [] temp1array;
            return res;
        }
        else
        {
            for (int i = 0; i < i1->get_size(); i++)
            {
                int carry = 0;
                for (int j = 0; j < i2->get_size(); j++)
                {
                    int f = temparray[i + j];
                    temparray[i + j] = (temparray[i + j] + (i1->get_array()[i] * i2->get_array()[j]) + carry) % 10;
                    carry = (f + i1->get_array()[i] * i2->get_array()[j] + carry) / 10;
                }
                temparray[i + i2->get_size()] = carry;
            }
            int i = i1->get_size() + i2->get_size() - 1;
            int sgn;
            while (temparray[i] == 0 && i >= 0)
            {
                i--;
            }
            int *temp1array = new int[i + 1];
            for (int j = 0; j < i + 1; j++)
            {
                temp1array[j] = temparray[j];
            }
            delete[] temparray;
            if (i1->get_sign() * i2->get_sign() > 0)
            {
                sgn = 1;
            }
            else if (i1->get_sign() * i2->get_sign() < 0)
            {
                sgn = -1;
            }

            UnlimitedInt *res = new UnlimitedInt(temp1array, i + 1, sgn, i + 1);
            delete [] temp1array;
            return res;
        }
    }
}
UnlimitedInt *UnlimitedInt::div(UnlimitedInt *i1, UnlimitedInt *i2)
{                                                                                  //i2=0??????
    if (i1->get_sign() == 0)
    {
        int *zero1 = new int[1]{0};
        UnlimitedInt *res = new UnlimitedInt(zero1, 1, 0, 1);
        delete [] zero1;
        return res;
    }
    if (compare(i1, i2))
    {
        int sgn;
        if (i1->get_sign() * i2->get_sign() > 0)
        {
            sgn = 1;
        }
        else
        {
            sgn = -1;
        }
        // int *ten1 = new int[2]{0, 1};
        // int *one1 = new int[1]{1};
        // int *zero1 = new int[1]{0};
        UnlimitedInt *ten = new UnlimitedInt("10");
        UnlimitedInt *zero = new UnlimitedInt("0");
        UnlimitedInt *one = new UnlimitedInt("1");
        // delete [] ten1;
        // delete [] one1;
        // delete [] zero1;
        int t = i1->get_size() - i2->get_size();
        UnlimitedInt *quo = new UnlimitedInt("0");
             
            UnlimitedInt* s=new UnlimitedInt(i1->get_array(),i1->get_capacity(),1,i1->get_size());
        while (t >= 0)
        {
            UnlimitedInt *r = new UnlimitedInt(i2->get_array(),i2->get_capacity(),1,i2->get_size());
            UnlimitedInt *temp = new UnlimitedInt("1");
            int w = t;
            while (w--)
            {
                UnlimitedInt* temp1=r;
                UnlimitedInt* temp2=temp;
                // cout << "hi" << endl;
                r = mul(r, ten);            // delete old arrys
                temp = mul(temp, ten);
                delete temp1;
                delete temp2;
            }
            while (compare(s, r))
            {
                // cout << "bye" << endl;
                // cout << s->get_sign() << " " << s->to_string() << endl;
                // cout << temp->get_sign() << " " << temp->to_string() << endl;
                // cout << r->get_sign() << " " << r->to_string() << endl;
                 UnlimitedInt* temp3=s;
                UnlimitedInt* temp4=quo;
                s = sub(s, r);
                delete temp3;
                // cout<<s->get_sign()<<" "<<s->to_string()<<endl;
                quo = add(quo, temp);
                delete temp4;
                // cout << quo->get_sign() << " " << quo->to_string() << endl;
                // cout << t << " here" << endl;
                // cout << "here sign is" << sgn << endl;
                // if(t == 0) cout << i1->to_string() << endl;
                // delete temp1;
                // delete temp2;
            }
            t--;
            delete r;
            delete temp;
        }
        //    cout << i1->to_string() << " " << quo->to_string() << endl;

        //    delete [] ten;
        //    delete [] one;
        // cout << "here1" << endl;
       
        // cout << a << " a" << endl;
        // cout << "here2" << endl;
        // cout<<s->to_string()<<endl;
        // cout << sgn << " " << endl;
        if(sgn==-1){
           if(s->get_sign()!=0){
            UnlimitedInt* temp5=quo;
            quo=add(one,quo);
            delete temp5;
           }
        }
         int a = quo->get_capacity();
        // cout<<quo->to_string()<<endl;
        int *temparray = quo->get_array();
        // cout << temparray[0] << " " << temparray[1] << endl;
        // cout << quo->get_sign() << " " << quo->to_string() << endl;
        // cout << "here3" << endl;
        // delete quo;
        UnlimitedInt *res = new UnlimitedInt(temparray, a, sgn, a);
       
        delete s;
        delete quo;
        delete  ten;
        delete  one;
        delete  zero;
        return res;
    }
    else
    {
        if(i1->get_sign()*i2->get_sign()<0 ){
            UnlimitedInt* mone=new UnlimitedInt("-1");
            return mone;
        }
        int *zero1 = new int[1]{0};
        UnlimitedInt *zero = new UnlimitedInt(zero1, 1, 0, 1);
        delete [] zero1;
        return zero;
    }
}
UnlimitedInt* UnlimitedInt::mod(UnlimitedInt *i1, UnlimitedInt *i2){
    UnlimitedInt* k=div(i1,i2);
    // cout<<k->to_string()<<endl;
    UnlimitedInt* j=mul(k,i2);
    // cout<<j->to_string()<<endl;
    UnlimitedInt* res=sub(i1,j);
    delete k;
    delete j;
    // cout<<res->to_string()<<endl;
    return res;
}
// UnlimitedInt* gcd(UnlimitedInt* i1, UnlimitedInt* i2){
//      UnlimitedInt* r=new UnlimitedInt(i1->get_array(),i1->get_capacity(),1,i1->get_capacity());
//         UnlimitedInt* s=new UnlimitedInt(i2->get_array(),i2->get_capacity(),1,i2->get_capacity());
        
//         while(s->get_sign()!=0){
//            UnlimitedInt* d;
//            d=new UnlimitedInt(s->get_array(),s->get_capacity(),1,s->get_size());
//            s=UnlimitedInt::mod(r,s);
//            r=new UnlimitedInt(d->get_array(),d->get_capacity(),1,d->get_size());
//         } 
//         return r;
// }
// int main()
// {
//     UnlimitedInt a("123");
//     UnlimitedInt *x = &a;
//     UnlimitedInt b("-56");
//     UnlimitedInt *t = &b;
//     //   cout<<a.get_capacity()<<endl;
//     //   cout<<a.get_size()<<endl;
//     //   cout<<a.get_sign()<<endl;
//     //   cout<<a.to_string()<<endl;
//     //    cout<<b.get_capacity()<<endl;
//     //   cout<<b.get_size()<<endl;
//     //   cout<<b.get_sign()<<endl;
//     //   cout<<b.to_string()<<endl;
//     // int *y = new int[3]{0,0,5};
//     // int *x = new int[3]{0,0,4};
//     // int *c = subtract(y,3,x,3);
//     // int k=checkzeros_size(c,3);
//     // cout<<k<<endl;
//     // for (int i = 0; i <k; i++)
//     // {
//     //     cout << c[i] << " ";
//     // }
//     // cout << endl;
//     // delete[] x;
//     // delete [] y;
//     UnlimitedInt *c;
//     c = c->mod(x, t);
//     cout << c->get_capacity() << endl;
//     cout << c->get_size() << endl;
//     cout << c->get_sign() << endl;
//     cout << c->to_string() << endl;
//     // x = x->mul(x, t);
//     // cout << x->to_string() << endl;
//     // cout << x->get_capacity() << endl;
//     // cout << x->get_size() << endl;
//     // cout << x->get_sign() << endl;
//     // //   cout<<a.get_capacity()<<endl;
//     //   cout<<a.get_size()<<endl;
//     //   cout<<a.get_sign()<<endl;
//     //   cout<<a.to_string()<<endl;
//     // }
//     // cout<<comp(x,t)<<endl;
//     // cout<<x->to_string()<<endl;
// }


// delete [] t;  what should be deleted???
// i2=0;