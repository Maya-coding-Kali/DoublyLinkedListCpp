// DoublyLinkedListCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct Node
{
    int Data;
    Node* next;
    Node* prev;
};
Node* Start;
Node* End;
void Append(int value)
{
    Node* NewNode = new Node;
    NewNode->Data = value;
    if (Start == NULL)
    {
        Start = NewNode;
        End = NewNode;   
        End->prev = Start;
        Start->next = End;
        End->next->next = NULL;
        Start->prev->next = NULL;
    }
    else
    {
        NewNode->next = Start;
        Start->prev = NewNode;
        NewNode->prev = NULL;
        Start = NewNode;

    }

}
void Prepend(int value)
{
    Node* NewNode = new Node;
    NewNode->Data = value;
    if (End == NULL)
    {
        Start = NewNode;
        End = NewNode;
        End->prev = Start;
        Start->next = End;
        End->next->next = NULL;
        Start->prev->prev = NULL;
    }
    else
    {
        NewNode->prev = End;
        NewNode->next = NULL;
        End->next = NewNode;
        End = NewNode;
    }
}
void DeleteFront()
{
    Node* ToDelete = new Node;
    if (Start != NULL)
    {
        ToDelete = Start;
        Start = Start->next;
        delete ToDelete;

    }
    else
    {
        return;
    }
}
void DeleteBack()
{
    Node* toDelete = new Node;
    if (End != NULL)
    {
        toDelete = End;
        End = End->prev;
        End->next = NULL;
        delete toDelete;
    }
}
void AddAfter(int value, int ToFind)
{
    Node* NewNode = new Node;
    Node* Current = new Node;
    Current = Start;
    NewNode->Data = value;
    if (Start == NULL)
    {
        Start = NewNode;
        End = NewNode;
        End->prev = Start;
        Start->next = End;
        End->next->next = NULL;
        Start->prev->prev = NULL;
    }
    else
    {
        while (Current->Data != ToFind)
        {
            if (Current->next == NULL)
            {
                Prepend(value);
                return;
            }
            Current = Current->next;

        }
        
       
        
    }

}
void AddBefore(int value, int ToFind)
{
    Node* NewNode = new Node;
    Node* Current = new Node;
    NewNode->Data = value;

    if (Start == NULL)
    {
        Start = NewNode;
        End = NewNode;
        End->prev = Start;
        Start->next = End;
        End->next->next = NULL;
        Start->prev->prev = NULL;
    }
    else
    {
        Current = Start;
        if (Start->Data == ToFind)
        {
            Append(value);
        }
        else
        {
            while (Current->Data != ToFind)
            {
                if (Current->next == NULL)
                {
                    return;
                }
                Current = Current->next;

            }
            NewNode->prev = Current->prev;
            NewNode->next = Current;
            Current->prev->next = NewNode;
            Current->prev = NewNode;
        }
        


    }

}
void PrintForward()
{
    Node* Current = new Node;
    Current = Start;
    std::cout << "Null <-> ";
    while (Current != NULL)
    {
        std::cout << Current->Data << " <-> ";
        Current = Current->next;

    }
    std::cout << " Null";

}
void PrintBackwards()
{
    Node* Current = new Node;
    Current = End;
    std::cout << "Null <-> ";
    while (Current != NULL)
    {
        std::cout << Current->Data << " <-> ";
        Current = Current->prev;

    }
    std::cout << "Null";

}
int main()
{
 
    //Prepend(789);
   // Append(98);
   // Prepend(963);
    //Append(5);
   // Append(8);
    AddAfter(99, 963);
    AddBefore(78, 99);

    PrintForward();

    PrintBackwards();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
