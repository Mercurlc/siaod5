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
    std::cout << "Список:" << std::endl;
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


void deleteFromL2(Node*& L2)
{
    for (auto pCurrent = L2; pCurrent;)
    {
        if (!isdigit(pCurrent->cData))
        {
            pCurrent = pCurrent->next;
            continue;
        }

        auto pPrevNode = GetPreviousNode(L2, pCurrent);
       
        if (!pPrevNode)
        {
            auto pTmp = pCurrent;
            pCurrent = pCurrent->next;
            L2 = pCurrent;
            delete pTmp;
            continue;
        }
		pPrevNode->next = pCurrent->next;
        delete pCurrent;

        pCurrent = pPrevNode;
        pCurrent = pCurrent->next;
    }

   
}
int main()
{
    setlocale(LC_ALL, "ru");
    Node* L1 = NULL;
    Node* L2 = NULL;
    int elements;
    char ch;
    int n;


    std::cout << "Сколько элемент вы хотите добавить в список 1?" << std::endl;
    std:: cin >> elements;
    for (int i = 0; i < elements; i++)
    {
        std::cin >> ch;
        push(L1, ch);
    }

    std::cout << "Сколько элемент вы хотите добавить в список 2?" << std::endl;
    std::cin >> elements;
    for (int i = 0; i < elements; i++)
    {
        std::cin >> ch;
        push(L2, ch);
    }
    //Разработать функцию, которая проверяет на равенство списки L1 и L2.
//Разработать функцию, которая вставляет в список L1 последний элемент списка L2.
//Разработать функцию, которая удаляет из списка L2, узлы, содержащие цифровые значения.
    while (true)
    {
        std::cout << "Выберите действие над списками: 1, 2, 3" << std::endl;
        std::cin >> n;
        if (n == 1)
        {
            std::cout << isEqual(L1, L2) << std::endl;
        }
        if (n == 2)
        {
            inputL1(L1, L2);
            coutList(L1);
        }
        if (n == 3)
        {
            deleteFromL2(L2);
            coutList(L2);
        }
        if (n == 0)
            break;
    }
}