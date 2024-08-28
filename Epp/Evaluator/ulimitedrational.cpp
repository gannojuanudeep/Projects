/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedrational.h"
// #include <iostream>
// using namespace std;

UnlimitedInt *gcd(UnlimitedInt *i1, UnlimitedInt *i2)
{
    UnlimitedInt *r = new UnlimitedInt(i1->get_array(), i1->get_capacity(), 1, i1->get_capacity());
    UnlimitedInt *s = new UnlimitedInt(i2->get_array(), i2->get_capacity(), 1, i2->get_capacity());

    while (s->get_sign() != 0)
    {
        UnlimitedInt *d;
        UnlimitedInt *temp1;
        UnlimitedInt *temp2;
        //    UnlimitedInt* temp3;
        //    temp1=d;
        d = new UnlimitedInt(s->get_array(), s->get_capacity(), 1, s->get_size());
        //    if(temp1){
        //    delete temp1;
        //    }
        temp1 = r;
        temp2 = s;
        s = UnlimitedInt::mod(r, s);
        r = new UnlimitedInt(d->get_array(), d->get_capacity(), 1, d->get_size());
        delete temp1;
        delete temp2;
        delete d;
        //    if(temp2){
        //     delete temp2;
        //    }
        //    if(temp3){
        //     delete temp3;
        //    }
    }
    delete s;
    return r;
}
UnlimitedRational::UnlimitedRational(UnlimitedInt *num, UnlimitedInt *den)
{
    if (den->get_sign() == 0)
    {
        p = new UnlimitedInt("0");
        q = new UnlimitedInt("0");
        return;
    }
    if (num->get_sign() == 0)
    {
        q = new UnlimitedInt(den->to_string());
        p = new UnlimitedInt(num->to_string());
        return;
    }
    UnlimitedInt *k = gcd(num, den);
    p = UnlimitedInt::div(num, k);
    q = UnlimitedInt::div(den, k);
    delete k;
}
UnlimitedRational::~UnlimitedRational()
{
    if (p)
    {
        delete p;
    }
    if (q)
    {
        delete q;
    }
}
UnlimitedRational::UnlimitedRational()
{
    p = NULL;
    q = NULL;
}
string UnlimitedRational::get_p_str()
{
    return p->to_string();
}
string UnlimitedRational::get_q_str()
{
    return q->to_string();
}
string UnlimitedRational::get_frac_str()
{
    string s = "";
    s += p->to_string();
    s += "/";
    s += q->to_string();
    return s;
}
UnlimitedRational *UnlimitedRational ::add(UnlimitedRational *i1, UnlimitedRational *i2)
{
    if (i2->get_frac_str() == "0/0" || i1->get_frac_str() == "0/0")
    {
        UnlimitedInt *nu = new UnlimitedInt("0");
        UnlimitedInt *de = new UnlimitedInt("0");
        UnlimitedRational *res = new UnlimitedRational(nu, de);
        delete nu;
        delete de;
        return res;
    }
    UnlimitedInt *n1 = UnlimitedInt::mul(i1->get_p(), i2->get_q());
    UnlimitedInt *n2 = UnlimitedInt::mul(i1->get_q(), i2->get_p());
    UnlimitedInt *numr = UnlimitedInt::add(n1, n2);
    UnlimitedInt *denr = UnlimitedInt::mul(i1->get_q(), i2->get_q());
    UnlimitedRational *res = new UnlimitedRational(numr, denr);
    delete n1;
    delete n2;
    delete numr;
    delete denr;
    return res;
}
UnlimitedRational *UnlimitedRational ::sub(UnlimitedRational *i1, UnlimitedRational *i2)
{
    if (i2->get_frac_str() == "0/0" || i1->get_frac_str() == "0/0")
    {
        UnlimitedInt *nu = new UnlimitedInt("0");
        UnlimitedInt *de = new UnlimitedInt("0");
        UnlimitedRational *res = new UnlimitedRational(nu, de);
        delete nu;
        delete de;
        return res;
    }
    UnlimitedInt *n1 = UnlimitedInt::mul(i1->get_p(), i2->get_q());
    UnlimitedInt *n2 = UnlimitedInt::mul(i1->get_q(), i2->get_p());
    UnlimitedInt *numr = UnlimitedInt::sub(n1, n2);
    UnlimitedInt *denr = UnlimitedInt::mul(i1->get_q(), i2->get_q());
    UnlimitedRational *res = new UnlimitedRational(numr, denr);
    delete n1;
    delete n2;
    delete numr;
    delete denr;
    return res;
}
UnlimitedRational *UnlimitedRational ::mul(UnlimitedRational *i1, UnlimitedRational *i2)
{
    if (i2->get_frac_str() == "0/0" || i1->get_frac_str() == "0/0")
    {
        UnlimitedInt *nu = new UnlimitedInt("0");
        UnlimitedInt *de = new UnlimitedInt("0");
        UnlimitedRational *res = new UnlimitedRational(nu, de);
        delete nu;
        delete de;
        return res;
    }
    UnlimitedInt *numr = UnlimitedInt::mul(i1->get_p(), i2->get_p());
    UnlimitedInt *denr = UnlimitedInt::mul(i1->get_q(), i2->get_q());
    UnlimitedRational *res = new UnlimitedRational(numr, denr);
    delete numr;
    delete denr;
    return res;
}
UnlimitedRational *UnlimitedRational ::div(UnlimitedRational *i1, UnlimitedRational *i2)
{
    if (i2->get_frac_str() == "0/0" || i1->get_frac_str() == "0/0")
    {
        UnlimitedInt *nu = new UnlimitedInt("0");
        UnlimitedInt *de = new UnlimitedInt("0");
        UnlimitedRational *res = new UnlimitedRational(nu, de);
        delete nu;
        delete de;
        return res;
    }
    UnlimitedInt *numr = UnlimitedInt::mul(i1->get_p(), i2->get_q());
    UnlimitedInt *denr = UnlimitedInt::mul(i1->get_q(), i2->get_p());
    UnlimitedRational *res = new UnlimitedRational(numr, denr);
    delete numr;
    delete denr;
    return res;
}
UnlimitedInt *UnlimitedRational ::get_p()
{
    return p;
}
UnlimitedInt *UnlimitedRational ::get_q()
{
    return q;
}

// 0/0 operations
// int main(){
//     UnlimitedInt*p=new UnlimitedInt("0");
//    UnlimitedInt* q= new UnlimitedInt("0");

//     UnlimitedRational* c=new UnlimitedRational(p,q);
//      UnlimitedInt*r=new UnlimitedInt("6");
//    UnlimitedInt* s= new UnlimitedInt("-8");
//     UnlimitedRational* d=new UnlimitedRational(r,s);
//     UnlimitedRational* f=f->div(c,d);
//     cout<<f->get_frac_str()<<endl;

// }
