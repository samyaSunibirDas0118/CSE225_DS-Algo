#include "TransportGraph.h"

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

    edgeList = new int *[size];
    for(int i=0; i<size; i++)
        edgeList[i] = new int[size];

    head = new Node;
}
template<class Vertex>
TransportGraph<Vertex>::~TransportGraph()
{
    delete[] vertexList;
    for(int i=0; i<numOfVertex; i++)
        delete[] edgeList[i];
    delete[] edgeList;

    delete head;
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
    cout<<"\t ";
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
void TransportGraph<Vertex>::FindVertices(Vertex v)
{
    head = NULL;

    int fromIndex = FindIndex(vertexList, v, numOfVertex);
    for(int toIndex=0; toIndex<numOfVertex; toIndex++)
    {
        if(edgeList[fromIndex][toIndex] != 0)
            InsertLinkedListInSorted(vertexList[toIndex]);
    }
}
template<class Vertex>
void TransportGraph<Vertex>::InsertLinkedListInSorted(Vertex item)
{
    //Using Doubly Linked List
    Node* newNode = new Node;
    newNode->info = item;

    //Inserting First Node
    if(head == NULL){
        newNode->next = NULL;
        newNode->previous = NULL;
        head = newNode;
    }
    //Inserting Second Node
    else if(item <= head->info){
        newNode->next = head;
        newNode->next->previous = newNode;
        head = newNode;
    }
    else{ //Inserting All other Nodes
        Node* temp = head;
        while(temp->next != NULL)
        {
            if ((temp->next)->info > item)
                break;
            else
                temp = temp->next;
        }
        newNode->next = temp->next;
        if(temp->next != NULL)
            newNode->next->previous = newNode;

        temp->next = newNode;
        newNode->previous = temp;
    }
}
template<class Vertex>
void TransportGraph<Vertex>::printSortedList(Vertex givenVertex)
{
    FindVertices(givenVertex);
    Node *temp = head;
    cout <<givenVertex<<"<-->";
    while(temp != NULL)
    {
        cout <<temp->info<<"<-->";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
}
