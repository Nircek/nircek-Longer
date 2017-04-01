#include <iostream>
#include "Longer.h"

using namespace std;

int main()
{
    try{
        string a;
        cin>>a;
        Longer b,c;
        b.writebytes(a);
        cin>>a;
        c.writebytes(a);
        cout<<b.readbytes()<<"=="<<c.readbytes()<<'='<<(b==c?"true":"false")<<'\n';
        cout<<b.readbytes()<<"!="<<c.readbytes()<<'='<<(b!=c?"true":"false")<<'\n';
        cout<<b.readbytes()<<"<"<<c.readbytes()<<'='<<(b<c?"true":"false")<<'\n';
        cout<<b.readbytes()<<">"<<c.readbytes()<<'='<<(b>c?"true":"false")<<'\n';
        cout<<b.readbytes()<<"<="<<c.readbytes()<<'='<<(b<=c?"true":"false")<<'\n';
        cout<<b.readbytes()<<">="<<c.readbytes()<<'='<<(b>=c?"true":"false")<<'\n';
        cout<<"isEmpty("<<b.readbytes()<<")="<<((!b)?"true":"false")<<'\n';
        cout<<"isEmpty("<<c.readbytes()<<")="<<((!c)?"true":"false");
        ;
    return 0;
    }catch(string err){
        cout<<"\n\n!!!ERR: "<<err;
    }catch(std::exception& e) {
        cout<<"\n\n!!!ERR: "<<e.what();
    }catch(...){
        cout<<"\n\n!!!ERR: UNEXCEPTED ERROR";
    }
    return 1;
}
