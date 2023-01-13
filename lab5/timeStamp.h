#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

class timeStamp{

public:
    timeStamp();
    timeStamp(int,int,int);
    int getHour();
    int getMinute();
    int getSecond();
    bool operator!=(timeStamp);
    void Print();

private:
    int Hour,Minute,Second;



};


#endif // TIMESTAMP_H_INCLUDED
