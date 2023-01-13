#include "TransportGraph.h"
#include "Stack.cpp"
#include "Queue.cpp"

#include <iostream>
#include <stdio.h>
#include <iomanip> //Used for formatting Print

using namespace std;

template<class Vertex>
TransportGraph<Vertex>::TransportGraph(int size)
{
    numOfVertex = 0;
    maxNumOfVertex = size;
    vertexList = new Vertex[size];
    markList = new bool[size];

    edgeList = new int *[size];
    for(int i=0; i<size; i++)
        edgeList[i] = new int[size];

    head = new Node;
    headPtrOfSortedList = new Node;
}
template<class Vertex>
TransportGraph<Vertex>::~TransportGraph()
{
    delete[] vertexList;
    delete[] markList;

    for(int i=0; i<numOfVertex; i++)
        delete[] edgeList[i];
    delete[] edgeList;

    delete head;
    delete headPtrOfSortedList;
    numOfVertex = 0;
}
template<class Vertex>
bool TransportGraph<Vertex>::IsEmpty()
{
    return (numOfVertex == 0);
}
template<class Vertex>
bool TransportGraph<Vertex>::IsFull()
{
    return (numOfVertex == maxNumOfVertex);
}
template<class Vertex>
void TransportGraph<Vertex>::MakeEmpty()
{
    numOfVertex = 0;
}
template<class Vertex>
void TransportGraph<Vertex>::AddVertex(Vertex newVertex)
{
    if(IsFull()){
        cout <<"Vertex List is Full. No more Vertex can be added!!!!!"<<endl;
        return;
    }
    vertexList[numOfVertex] = newVertex;
    for(int i=0; i<=numOfVertex; i++)
    {
        edgeList[numOfVertex][i] = 0;
        edgeList[i][numOfVertex] = 0;
    }
    numOfVertex++;
}
template<class Vertex>
int FindIndex(Vertex* vertexList, Vertex v,int numOfVertex)
{
    for(int i=0; i<numOfVertex; i++)
    {
        if(v == (vertexList[i]))
            return i;
    }
    cout <<"Vertex Not Found !"<<endl;
    return -1;
}
template<class Vertex>
void TransportGraph<Vertex>::AddEdge(Vertex startingVertex, Vertex endingVertex, int weight)
{
    if(IsEmpty())
    {
        cout<<"There is not Vertex. So, no edges can be added."<<endl;
        return;
    }
    int row = FindIndex(vertexList, startingVertex, numOfVertex);
    int col = FindIndex(vertexList, endingVertex, numOfVertex);

    if(row<0|| col<0)
    {
        cout<<"Edge can not be added. Wrong vertex inserted."<<endl;
        return;
    }
    edgeList[row][col] = weight;
}
template<class Vertex>
void TransportGraph<Vertex>::PrintAdjacencyMatrix()
{
    cout<<"Adjacency Matrix of the Graph : "<<endl;
    cout<<"\t";
    ///Printing Vertex Names :
    for(int i=0; i<numOfVertex; i++)
        //"setw()" is a function defined in <iomanip>header file
        // it is used to format the cout
        cout<<setw(11)<<vertexList[i];
    cout<<endl;

    ///Printing Adjacency Matrix
    for(int row=0; row<numOfVertex; row++){
        cout<<setw(11)<<vertexList[row];
        for(int col=0; col<numOfVertex; col++){
            cout<<setw(10)<<edgeList[row][col];
        }
        cout<<endl;
    }
}
template<class Vertex>
void TransportGraph<Vertex>::MarkVertex(Vertex v)
{
    int index = FindIndex(vertexList, v, numOfVertex);
    markList[index] = true;
}
template<class Vertex>
bool TransportGraph<Vertex>::IsVertexMarked(Vertex v)
{
    int index = FindIndex(vertexList, v, numOfVertex);
    return markList[index];
}
template<class Vertex>
void TransportGraph<Vertex>::ClearAllMarks()
{
    for(int i=0; i<maxNumOfVertex; i++)
        markList[i] = false;
}
template<class Vertex>
void TransportGraph<Vertex>::GoToVertices(Vertex v, Queue<Vertex>& adjacentVertices)
{
    int fromIndex = FindIndex(vertexList, v, numOfVertex);
    for(int toIndex=0; toIndex<numOfVertex; toIndex++)
    {
        if(edgeList[fromIndex][toIndex] != 0)
        {
            adjacentVertices.Enqueue(vertexList[toIndex]);
        }
    }
}
template<class Vertex>
void TransportGraph<Vertex>::InsertInLinkedList(Vertex item)
{
    Node *newNode = new Node;
    newNode->info = item;

    //Creating 1st Node
    if(head == NULL){
        newNode->previous = NULL;
        newNode->next = NULL;
        head = newNode;
    }
    else{ //Creating next Nodes
        Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->previous = temp;
        newNode->next = NULL;
        temp->next = newNode;
    }
}
template<class Vertex>
void TransportGraph<Vertex>::InsertInSortedLinkedList(Vertex item)
{
    Node *newNode = new Node;
    newNode->info = item;

    //Creating 1st Node
    if(headPtrOfSortedList == NULL){
        newNode->previous = NULL;
        newNode->next = NULL;
        headPtrOfSortedList = newNode;
    }
    else{ //Creating next Nodes
        Node *temp = headPtrOfSortedList;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->previous = temp;
        newNode->next = NULL;
        temp->next = newNode;
    }
}
template<class Vertex>
void TransportGraph<Vertex>::DFSGraph(Vertex startV, Vertex endV)
{
    head = NULL;

    Stack<Vertex> vStack;
    Queue<Vertex> vQueue;
    bool found = false;
    Vertex currentVertex,item;

    ClearAllMarks();
    vStack.Push(startV);

    do{
        currentVertex = vStack.Top();
        vStack.Pop();
        if(currentVertex == endV){
            //Simply Printing the current Vertex
            cout<< currentVertex <<" ] ";
            //Inserting into the Linked List
            InsertInLinkedList(currentVertex);
            found = true;
        }
        else{
            if(!IsVertexMarked(currentVertex)){
                MarkVertex(currentVertex);
                //Inserting into the Linked List
                InsertInLinkedList(currentVertex);
                cout << currentVertex <<" ";
                GoToVertices(currentVertex,vQueue);

                while (!vQueue.isEmpty()){
                    vQueue.Dequeue(item);
                    if (!IsVertexMarked(item))
                        vStack.Push(item);
                }
            }
        }
    }while (!vStack.isEmpty() && !found);
    cout << endl;
    if (!found)
        cout << "No path is found." << endl;
}
template<class Vertex>
void TransportGraph<Vertex>::BFSGraph(Vertex startV, Vertex endV)
{
    head = NULL;

    Queue<Vertex> Q;
    Queue<Vertex> vQueue;

    bool found = false;
    Vertex currentVertex, item;
    ClearAllMarks();
    Q.Enqueue(startV);

    do{
        Q.Dequeue(currentVertex);
        if(currentVertex == endV){
            //Simply Printing the current Vertex
            cout<< currentVertex <<" ] ";
            //Inserting into the Linked List
            InsertInLinkedList(currentVertex);
            found = true;
        }
        else{
            if(!IsVertexMarked(currentVertex)){
                MarkVertex(currentVertex);
                cout<< currentVertex <<" ";
                //Inserting into the Linked List
                InsertInLinkedList(currentVertex);
                GoToVertices(currentVertex, vQueue);

                while(!vQueue.isEmpty()){
                    vQueue.Dequeue(item);
                    if(!IsVertexMarked(item))
                        Q.Enqueue(item);
                }
            }
        }
    }while(!Q.isEmpty() && !found);
    cout<<endl;
    if(!found)
        cout<<"No path is found."<<endl;
}
template<class Vertex>
void TransportGraph<Vertex>::PrintLinkedList()
{
    cout <<"Linked List : ";
    Node *temp = head;
    while(temp != NULL)
    {
        cout <<temp->info<<"-->";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
}
template<class Vertex>
void TransportGraph<Vertex>::printSortedList(Vertex givenVertex)
{
    Queue<Vertex> newQueue;
    GoToVertices(givenVertex,newQueue);
    Vertex v;
    headPtrOfSortedList = NULL;

    while(!newQueue.isEmpty())
    {
        newQueue.Dequeue(v);
        InsertInSortedLinkedList(v);
    }
    Node *temp = headPtrOfSortedList;
    cout <<givenVertex<<"-->";
    while(temp != NULL)
    {
        cout <<temp->info<<"-->";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
}

