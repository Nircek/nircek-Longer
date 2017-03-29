#include <iostream>
#include "Longer.h"

using namespace std;

int main()
{
    try{
        string a;
        cin>>a;
        Longer b;
        b.writebytes(a);
        cout<<b.readbytes();
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
