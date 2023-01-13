#ifndef TRANSPORTGRAPH_H_INCLUDED
#define TRANSPORTGRAPH_H_INCLUDED
#include "stacktype.h"
#include "quetype.h"
template<class VertexType>

class TransportGraphType{

public:
TransportGraphType();
TransportGraphType(int maxV);
~TransportGraphType();
void MakeEmpty();
bool IsEmpty();
bool IsFull();
void AddVertex(VertexType);
void AddEdge(VertexType,
VertexType, int);
int WeightIs(VertexType,
VertexType);
void GetToVertices(VertexType,
QueType<VertexType>&);
void ClearMarks();
void MarkVertex(VertexType);
bool IsMarked(VertexType);
void DFSGraph(VertexType,
VertexType);
void BFSGraph(VertexType,
VertexType);
//private:
int numVertices;
int maxVertices;
VertexType* vertices;
int **edges;
bool* marks;
};





#endif // TRANSPORTGRAPH_H_INCLUDED
