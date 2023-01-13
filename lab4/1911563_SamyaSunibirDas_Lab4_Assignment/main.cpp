#include <iostream>
#include "unsortedtype.cpp"

using namespace std;

/*

This is solution from today's Lab 4. You have to complete codes for deletion and retrieving

*/

int main() {

    UnsortedType <int> student_id;
    UnsortedType <string> student_name;
    UnsortedType <double> student_cgpa;

    cout<< "######Insert details for five students######"<<endl;

    int id;
    string name;
    double cgpa;

    for (int i=0;i<5;i++){

            cout<<"Enter ID of student "<<(i+1)<<":";
            cin>>id;
            student_id.InsertItem(id);

            cout<<"Enter name of student "<<(i+1)<<":";
            cin>>name;
            student_name.InsertItem(name);

            cout<<"Enter CGPA of student "<<(i+1)<<":";
            cin>>cgpa;
            student_cgpa.InsertItem(cgpa);
    }






    cout<< "\n######The inserted list is printed below######"<<endl;
    for (int i=0;i<student_id.LengthIs();i++){

            student_id.GetNextItem(id);
            student_name.GetNextItem(name);
            student_cgpa.GetNextItem(cgpa);

            cout<<id<<" "<<name<<" "<<cgpa<<endl;
    }

    int inputSearch;
    cout<<"Choose 1 for Search by Id, Choose 2 for Search by Name, Choose 3 for Search by CGPA"<<endl;
    cin>>inputSearch;
    if  (inputSearch==1){
    student_id.ResetList();

    bool check;
    int p;
    cout<<endl;
    cout<<"enter the ID to retrieve: "<<endl;
    cin>>p;
    student_id.RetrieveItem(p,check);
    if(check){
        cout<<"found"<<endl<<endl;
    }
    else {
        cout<<"not found"<<endl<<endl;
    }
    }
    else if (inputSearch==2){
            student_name.ResetList();

    bool check;
    string p;
    cout<<endl;
    cout<<"enter the Name to retrieve: "<<endl;
    cin>>p;
    student_name.RetrieveItem(p,check);
    if(check){
        cout<<"found"<<endl<<endl;
    }
    else {
        cout<<"not found"<<endl<<endl;
    }
    }

        else if (inputSearch==3){
            student_cgpa.ResetList();

    bool check;
    double p;
    cout<<endl;
    cout<<"enter the CGPA to retrieve: "<<endl;
    cin>>p;
    student_cgpa.RetrieveItem(p,check);
    if(check){
        cout<<"found"<<endl<<endl;
    }
    else {
        cout<<"not found"<<endl<<endl;
    }
    }


    student_id.ResetList();
    int o,k;
    cout<<"Give The ID of the Student to Delete: "<<endl;
    cin>>o;
    student_id.DeleteItem(o);

    cout<<"After deletion:: "<<endl;
    for(int i=0;i<student_id.LengthIs();i++){
        student_id.GetNextItem(k);
        cout<<k<<endl;
    }

    cout<<"After deleting list is: "<<student_id.LengthIs()<<endl<<endl;


    return 0;
}
