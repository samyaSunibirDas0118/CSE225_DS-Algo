#ifndef DYNARR_H_INCLUDED
#define DYNARR_H_INCLUDED

class dynArr{


private:
    int *data;
    int size;
public:
    dynArr();
    dynArr(int); //method overloading
    ~dynArr();
    void setValue(int, int); //getter method
    int getValue(int); //setter method
};

#endif // DYNARR_H_INCLUDED
