#include <iostream>
#include "structures.h"
#include "functions.h"

using namespace std;


// функція додає вузол в список
void push(Node **head, string input_subject_name, float input_credits, int input_semester_number, int input_classroom_hours, int input_lecture_hours, int input_MKR, string input_semester_control) {
    Node *tmp = (Node*) malloc(sizeof(Node)); // створюємо новий вузол
    tmp->fields.subject_name = input_subject_name; // присвоюємо вузлу значення полів 
    tmp->fields.credits = input_credits;
    tmp->fields.semester_number = input_semester_number;
    tmp->fields.classroom_hours = input_classroom_hours;
    tmp->fields.lecture_hours = input_lecture_hours;
    tmp->fields.MKR = input_MKR;
    tmp->fields.semester_control= input_semester_control;
    tmp->next = (*head); // присвоюємо вказівнику tmp адресу попереднього вузла
    (*head) = tmp; // присвоюємо вказівнику head адресу нового вузла
    // після виходу з функції змінна tmp буде знищена 
}

// функція видаляє елемент, на який вказує head та повертає його значення
struct Fields pop(Node **head) {
    Node *prev = NULL;  // створюємо вказивник на перший вузол
    
    struct Fields value_fields;

    if (head == NULL) {
        exit(-1);
    }
    
    prev = (*head);

    value_fields.subject_name = prev->fields.subject_name;
    value_fields.credits = prev->fields.credits;
    value_fields.semester_number = prev->fields.semester_number;
    value_fields.classroom_hours = prev->fields.classroom_hours;
    value_fields.lecture_hours = prev->fields.lecture_hours;
    value_fields.MKR = prev->fields.MKR;
    value_fields.semester_control = prev->fields.semester_control;

    (*head) = (*head)->next;
    free(prev);
    return value_fields;
}

// функція повертає вказивник на n-ий елемент списку
Node* getNth(Node* head, int n) {
    int counter = 0;
    while(counter < n && head){
        head = head->next;
        counter++;
    }
    return head;
}

// функція повертає вказівник на останній елемент списка
Node* getLast(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

// функція додає новий елемент в кінець списку
void pushBack(Node *head, string input_subject_name, float input_credits, int input_semester_number, int input_classroom_hours, int input_lecture_hours, int input_MKR, string input_semester_control) {
    Node *last = getLast(head);
    Node *tmp = (Node*) malloc(sizeof(Node));

    tmp->fields.subject_name = input_subject_name;
    tmp->fields.credits = input_credits;
    tmp->fields.semester_number = input_semester_number;
    tmp->fields.classroom_hours = input_classroom_hours;
    tmp->fields.lecture_hours = input_lecture_hours;
    tmp->fields.MKR = input_MKR;
    tmp->fields.semester_control = input_semester_control;
    
    tmp->next = NULL;
    last->next = tmp;
}

// функція повертає вказівник на передостанній елемент списка
Node* getLastButOne(Node* head) {
    if (head == NULL) {
        exit(-2);
    }
    if (head->next == NULL) {
        return NULL;
    }
    while (head->next->next) {
        head = head->next;
    }
    return head;
}

// функція видаляє останній елемент
void popBack(Node **head) {
    Node *lastbn = NULL;
    // отримали NULL
    if (!head) {
        exit(-1);
    }
    // список пустий
    if (!(*head)) {
        exit(-1);
    }
    lastbn = getLastButOne(*head);
    // якщо в списку один елемент
    if (lastbn == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(lastbn->next);
        lastbn->next = NULL;
    }
}

// функція вставляє на n-е місце нове значення
void insert(Node *head, unsigned n, string input_subject_name, float input_credits, int input_semester_number, int input_classroom_hours, int input_lecture_hours, int input_MKR, string input_semester_control) {
    unsigned i = 0;
    Node *tmp = NULL;
    while (i<n && head->next)
    {
        head = head->next;
        i++;
    }
    tmp = (Node*) malloc(sizeof(Node));
    
    tmp->fields.subject_name = input_subject_name;
    tmp->fields.credits = input_credits;
    tmp->fields.semester_number = input_semester_number;
    tmp->fields.classroom_hours = input_classroom_hours;
    tmp->fields.lecture_hours = input_lecture_hours;
    tmp->fields.MKR = input_MKR;
    tmp->fields.semester_control = input_semester_control;

    if (head->next) {
        tmp->next = head->next;
    } else {
        tmp->next = NULL;
    }
    head->next = tmp;     
}

// функція видаляє елемент з n-місця зі списку 
struct Fields deleteNth(Node **head, int n) {
    if (n==0) {
        return pop(head);
    } else {
        Node *prev = getNth(*head, n-1);
        Node *elm = prev->next;

        struct Fields value_fields;
        value_fields.classroom_hours = elm->fields.classroom_hours;
        value_fields.credits = elm->fields.credits;
        value_fields.lecture_hours = elm->fields.lecture_hours;
        value_fields.MKR = elm->fields.MKR;
        value_fields.semester_control = elm->fields.semester_control;
        value_fields.semester_number = elm->fields.semester_number;
        value_fields.subject_name = elm->fields.subject_name;

        prev->next = elm->next;
        free(elm);
        return value_fields;
    }
}

// функція видаляє список
void deleteList(Node **head) {
    Node* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}
