#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED
class FullStack
{};
class EmptyStack
{};
template <class ItemType>
class StackType
{
    struct NodeType
    {
        ItemType info;
        NodeType* next;
    };
public:
    StackType();
    ~StackType();
    void Push(ItemType);
    void Pop(ItemType &newItem);
    ItemType Top();
    bool isEmpty();
    bool isFull();
private:
    NodeType* topPtr;
};
#endif // STACKTYPE_H_INCLUDED
