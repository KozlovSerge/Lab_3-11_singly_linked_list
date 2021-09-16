#include <iostream>
#include "structures.h"
#include "functions.h"

using namespace std;



int main()
{
    
    Node *head = NULL;
    
    pushBack(head, "Дискретна математика", 8.0, 5, 144, 72, 100, "Екзамен");
    pushBack(head, "Дослідження операцій (1)", 8.0, 5, 144, 72, 100, "Екзамен");
    pushBack(head, "Теорія пріийняття рішень (1)", 8.0, 5, 144, 72, 100, "Екзамен");
    pushBack(head, "Теорія пріийняття рішень (2)", 8.0, 5, 144, 72, 100, "Екзамен");
    pushBack(head, "Дослідження операцій (2)", 8.0, 5, 144, 72, 100, "Екзамен");
    pushBack(head, "ООП", 8.0, 5, 144, 72, 100, "Екзамен");
    pushBack(head, "Управління ІТ-проектами", 8.0, 5, 144, 72, 100, "Екзамен");
    //pushBack(head, "Алгоритми та структури даних", 8.0, 5, 144, 72, 100, "Екзамен");

    
    printLinkedList(head);
    deleteList(&head);
    

    cout << endl << "Done!" << endl;

    return 0;
}


