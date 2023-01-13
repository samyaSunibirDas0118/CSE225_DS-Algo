#include "timeStamp.h"
#include <iostream>
using namespace std;

timeStamp::timeStamp()
{
    Hour = 0;
    Minute = 0;
    Second =0;
}
timeStamp::timeStamp(int h, int m, int s){

    Hour = h;
    Minute = m;
    Second = s;

}
int timeStamp::getHour(){

    return Hour;
}

int timeStamp::getMinute(){
    return Minute;
}
int timeStamp::getSecond(){
    return Second;
}

bool timeStamp::operator!=(timeStamp t){

    if (Second ==t.Second && Minute ==t.Minute && Hour ==t.Hour)
        return true;
    else
        return false;

}

void timeStamp::Print()
{
    std:: cout<<"Hour:"<<Hour<<"\nMinute:"<<Minute<<"\nSecond:"<<Second<<std::endl;
}
