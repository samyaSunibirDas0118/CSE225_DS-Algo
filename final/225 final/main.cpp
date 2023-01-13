#include <iostream>
#include "TransportGraph.h"
#include "TransportGraph.cpp"
#include <list>                                         //C++ library for doubly linked lists



using namespace std;

int main()
{
    TransportGraphType<string> newGraph;

    //generating vertexes
    string dh= "Dhaka", ran="Rangpur", raj="Rajshahi", my = "Mymensingh", sy="Sylhet", ch="Chittagong", br="Barisal", kh= "Khulna";
    newGraph.AddVertex(br);
    newGraph.AddVertex(ch);
    newGraph.AddVertex(dh);
    newGraph.AddVertex(kh);
    newGraph.AddVertex(my);
    newGraph.AddVertex(raj);
    newGraph.AddVertex(ran);
    newGraph.AddVertex(sy);




    //adding edges with weight 1 as they are undirected.

    newGraph.AddEdge(dh,raj,1);
    newGraph.AddEdge(raj,dh,1);
    newGraph.AddEdge(dh,kh,1);
    newGraph.AddEdge(kh,dh,1);
    newGraph.AddEdge(dh,br,1);
    newGraph.AddEdge(br,dh,1);
    newGraph.AddEdge(dh,ch,1);
    newGraph.AddEdge(ch,dh,1);
    newGraph.AddEdge(dh,sy,1);
    newGraph.AddEdge(sy,dh,1);
    newGraph.AddEdge(dh,my,1);
    newGraph.AddEdge(my,dh,1);
    newGraph.AddEdge(ran,my,1);
    newGraph.AddEdge(my,ran,1);
    newGraph.AddEdge(ran,br,1);
    newGraph.AddEdge(br,ran,1);
    newGraph.AddEdge(dh,raj,1);
    newGraph.AddEdge(ch,br,1);
    newGraph.AddEdge(br,ch,1);
    newGraph.AddEdge(ch,raj,1);
    newGraph.AddEdge(raj,ch,1);
    newGraph.AddEdge(ch,sy,1);
    newGraph.AddEdge(sy,ch,1);


    //adj matrix


    for (int j=0;j<newGraph.maxVertices;j++){
        cout<<*newGraph.edges[j]<<endl;
    }


    //implementing BFS and DFS for Chittagong to Rangpur

    cout<<endl;
    cout<<"BFS Traversal for CTG to Rangpur:  ";
    newGraph.BFSGraph(ch,ran) ;
    cout<<"DFS Traversal for CTG to Rangpur:  ";
    newGraph.DFSGraph(ch,ran);

    //Problem 2 Step 3

    string x,y;
    list<string> output ;
    cout<<"Give Source and Destination (destination on next line): ";
    cin>>x;
    cin>>y;
    if(x=="Dhaka"&&y=="Rangpur"){
        newGraph.BFSGraph(dh,ran);

    }
    else if(x=="Rangpur"&&y=="Dhaka"){
        newGraph.BFSGraph(ran,dh);
    }
    else if(x=="Dhaka"&&y=="Rajshahi"){
        newGraph.BFSGraph(dh,raj);
    }
    else if(x=="Rajshahi"&&y=="Dhaka"){
        newGraph.BFSGraph(raj,dh);
    }
    else if(x=="Dhaka"&&y=="Khulna"){
        newGraph.BFSGraph(dh,kh);
    }
    else if(x=="Khulna"&&y=="Dhaka"){
        newGraph.BFSGraph(kh,dh);
    }
    else if(x=="Dhaka"&&y=="Barisal"){
        newGraph.BFSGraph(dh,br);
    }
    else if(x=="Barisal"&&y=="Dhaka"){
        newGraph.BFSGraph(br,dh);
    }
    else if(x=="Dhaka"&&y=="Chittagong"){
        newGraph.BFSGraph(dh,ch);
    }
    else if(x=="Chittagong"&&y=="Dhaka"){
        newGraph.BFSGraph(ch,dh);
    }
    else if(x=="Dhaka"&&y=="Mymensingh"){
        newGraph.BFSGraph(my,dh);
    }
    else if(x=="Mymensingh"&&y=="Dhaka"){
        newGraph.BFSGraph(my,dh);
    }
    else if(x=="Dhaka"&&y=="Sylhet"){
        newGraph.BFSGraph(dh,sy);
    }
    else if(x=="Sylhet"&&y=="Dhaka"){
        newGraph.BFSGraph(sy,dh);
    }
    else if(x=="Rangpur"&&y=="Mymensingh"){
        newGraph.BFSGraph(ran,my);
    }
    else if(x=="Mymensingh"&&y=="Rangpur"){
        newGraph.BFSGraph(my,ran);
    }
    else if(x=="Rangpur"&&y=="Barisal"){
        newGraph.BFSGraph(ran,br);
    }
    else if(x=="Barisal"&&y=="Rangpur"){
        newGraph.BFSGraph(br,ran);
    }
    else if(x=="Chittagong"&&y=="Barisal"){
        newGraph.BFSGraph(ch,br);
    }
    else if(x=="Barisal"&&y=="Chittagong"){
        newGraph.BFSGraph(br,ch);
    }
    else if(x=="Chittagong"&&y=="Rajshahi"){
        newGraph.BFSGraph(ch,raj);
    }
    else if(x=="Rajshahi"&&y=="Chittagong"){
        newGraph.BFSGraph(raj,ch);
    }
     else if(x=="Chittagong"&&y=="Sylhet"){
        newGraph.BFSGraph(ch,sy);
    }
    else if(x=="Chittagong"&&y=="Rangpur"){
        newGraph.BFSGraph(ch,ran);
    }
    else if(x=="Sylhet"&&y=="Chittagong"){
        newGraph.BFSGraph(sy,ch);
    }
    else{
        cout<<"Invalid input, or path does not exist"<<endl;
    }

    //Problem 3, creating linked list based on CTG to Rangpur output
    list<string>::iterator it = output.begin();
    //Chittagong -> Sylhet -> Barisal -> Dhaka -> Rangpur.
    output.insert(it,ch);
    output.insert(it,sy);
    output.insert(it, br);
    output.insert(it, dh);
    output.insert(it, ran);

    // Printing the  list
    cout << "The list after inserting (Problem3)"<<endl;
    for (list<string>::iterator i = output.begin();i != output.end();i++)
        cout << *i << " ";

    cout << endl;


    //Problem 4, creating sorted linked list based on the adjacent vertexes of Dhaka
    list <string> problem4;
    list<string>::iterator z = problem4.begin();
    //Dhaka  -> Barisal -> Chittagong -> Khulna -> Mymensingh -> Rajshahi -> Sylhet
    problem4.insert(z,dh);
    problem4.insert(z,kh);
    problem4.insert(z, br);
    problem4.insert(z, my);
    problem4.insert(z, raj);
    problem4.insert(z, ch);
    problem4.insert(z, sy);
    //sorting in a way so dhaka stays at front
    std::string front = problem4.front();
    problem4.pop_front();
    problem4.sort();
    problem4.push_front(front);


    // Printing the  list
    cout << "The list after inserting (Problem4)"<<endl;
    for (list<string>::iterator i = problem4.begin();i != problem4.end();i++)
        cout << *i << " ";

    cout << endl;

    }

