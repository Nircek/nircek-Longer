#include <iostream>
#include "Longer.h"

using namespace std;

int main()
{
    try{
    Longer a;
    a=a+10;
    return 0;
    }catch(string err){
        cout<<"\n\n!!!ERR: "<<err;
    }catch(...){
        cout<<"\n\n!!!ERR: UNEXCEPTED ERROR";
    }
    return 1;
}
