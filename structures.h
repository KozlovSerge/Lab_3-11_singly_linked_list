#include <iostream>

using namespace std;

#ifndef STRUCTURES_H
#define STRUCTURES_H

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

#endif