/*
Створити однозв’язний список дисциплін факультету, кожний елемент якого містить загальну інформацію по дисципліні (назва, кількість кредитів) та деталізовану інформацію про номер семестру, 
у якому дисципліна викладається, кількість аудиторних годин, кількість лекційних годин, кількість МКР та ознаку семестрового контролю (залік/екзамен)).
1)	Реалізувати функції перегляду записаних даних, додавання нового елемента на задану позицію (INSERT), видалення елемента з заданої позиції (DELETE). Початковий вміст списку заповнити з клавіатури.
2)	Впорядкувати записи за номером семестру, а в межах одного семестру за кількістю аудиторних годин у порядку спадання.
*/

#include <iostream>

using namespace std;

struct Fields
{
    string subject_name;
    float credits;
    int semester_number;
    int classroom_hours;
    int lecture_hours;
    int MKR;
    string semester_control;
};

typedef struct Node {
    Fields fields;
    struct Node *next;
} Node;

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

// функія злиття двох списків
void merge(Node *a, Node *b, Node **c) {
    Node tmp;
    *c = NULL;
    if (a == NULL) {
        *c = b;
        return;
    }
    if (b == NULL) {
        *c = b;
        return;
    }
    if (a->fields.semester_number < b->fields.semester_number) {
        *c = a;
        a = a->next;
    } else {
        *c = b;
        b = b->next;
    }
    tmp.next = *c;
    while (a && b) {
        if ((a->fields.semester_number < b->fields.semester_number) || ((a->fields.semester_number == b->fields.semester_number) && (a->fields.classroom_hours > b->fields.classroom_hours))) {
            (*c)->next = a;
            a = a->next; 
        } else {
            (*c)->next = b;
            b = b->next;
        }
        (*c) = (*c)->next;
    }
    if (a) {
        while (a) {
            (*c)->next = a;
            (*c) = (*c)->next;
            a = a->next;
        }
    }
    if(b) {
        while (b) {
            (*c)->next = b;
            (*c) = (*c)->next;
            b = b->next;
        }
    }
    *c = tmp.next;
}

// функція здийснює пошук середини списку
void split(Node *src, Node **low, Node **high) {
    Node *fast = NULL;
    Node *slow = NULL;

    if (src == NULL || src->next == NULL) {
        (*low) = src;
        (*high) = NULL;
        return;
    }

    slow = src;
    fast = src->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    (*low) = src;
    (*high) = slow->next;
    slow->next = NULL;
}

// функція сортування злиттям
void mergeSort(Node **head) {
    Node *low = NULL;
    Node *high = NULL;
    if ((*head == NULL) || ((*head)->next == NULL)) {
        return;
    }
    split(*head, &low, &high);
    mergeSort(&low);
    mergeSort(&high);
    merge(low, high, head);
}

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
    pushBack(head, "Алгоритми та структури даних", 8.0, 5, 144, 72, 100, "Екзамен");

    
    printLinkedList(head);
    deleteList(&head);
    

    cout << endl << "Done!" << endl;

    return 0;
}

