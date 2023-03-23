//char
//Даны два линейных однонаправленных списка L1 и L2 с головным элементом. 
//Разработать функцию, которая проверяет на равенство списки L1 и L2.
//Разработать функцию, которая вставляет в список L1 последний элемент списка L2.
//Разработать функцию, которая удаляет из списка L2, узлы, содержащие цифровые значения.

#include <iostream>

struct Node
{
	char cData;
	Node* next = nullptr;
};

Node* GetLastElement(Node* pNode)
{
    while (pNode->next)
        pNode = pNode->next;

    return pNode;
}

void push(Node*& list, char data) 
{

    Node* newNode = new Node;
    newNode->cData = data;
    
    if (list)
        GetLastElement(list)->next = newNode;
	else 
        list = newNode;
}

bool isEqual(Node* L1, Node* L2) 
{
    while (L1 != nullptr && L2 != nullptr) 
    {
        if (L1->cData != L2->cData) 
            return false;
        L1 = L1->next;
        L2 = L2->next;
    }
    return (L1 == nullptr && L2 == nullptr);
}
 
void inputL1(Node* L1, Node* L2)
{
    push(L1, GetLastElement(L2)->cData);
}

void coutList(Node* L1)
{
    while (L1 != nullptr)
    {
        std::cout << L1->cData << std::endl;
        L1 = L1->next;
    }
}

Node* GetPreviousNode(Node* pArrStart, Node* pTargetNode)
{
    for (auto pCurrent = pArrStart; pCurrent; pCurrent = pCurrent->next)
        if (pCurrent->next == pTargetNode)
            return pCurrent;
    return nullptr;
}


void deleteFromL2(Node* L2)
{
    for (auto pCurrent = L2; pCurrent; pCurrent = pCurrent->next)
    {
        if (!isdigit(pCurrent->cData))
            continue;
        
        auto pPrevNode = GetPreviousNode(L2, pCurrent);

		pPrevNode->next = pCurrent->next;
        delete pCurrent;

        pCurrent = pPrevNode;
    }

   
}
int main()
{
    Node* L1 = NULL;
    push(L1, 'a');
    push(L1, 'b');
    coutList(L1);

    Node* L2 = NULL;
    push(L2, 'a');
    push(L2, 'b');
    push(L2, '2');
    push(L2, '3');
    coutList(L1);

    std::cout << isEqual(L1, L2) << std::endl;
    inputL1(L1, L2);
    coutList(L1);
    deleteFromL2(L2);
    coutList(L2);
}