#include "structures.h"

// функція виводить в термінал вміст списку
void printLinkedList(const Node *head) {
    cout << "Назва предмета   Кількість кредитів   Номер семестра   Кількість аудиторних годин   Кількість лекційних годин   МКР   Тип контроля" << endl;
    while(head) {
        cout << head->fields.subject_name << "    ";
        cout << head->fields.credits << "    ";
        cout << head->fields.semester_number << "    ";
        cout << head->fields.classroom_hours << "    ";
        cout << head->fields.lecture_hours << "    ";
        cout << head->fields.MKR << "    ";
        cout << head->fields.semester_control << "    ";

        head = head->next;
        cout << endl;
    }
}