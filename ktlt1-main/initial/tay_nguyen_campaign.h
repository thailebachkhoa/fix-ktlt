/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 1
 * Programming Fundamentals Spring 2025
 * Date: 07.02.2025
 */

#ifndef _TAY_NGUYEN_CAMPAIGN_H_
#define _TAY_NGUYEN_CAMPAIGN_H_

#include "main.h"

bool readFile(
    const string &filename,
    int LF1[], int LF2[],
    int &EXP1, int &EXP2,
    int &T1, int &T2, int &E);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

/////////////////////// self-defined datastructured ////////////////////
class DlinkedList
{
public:
    DlinkedList() : head(nullptr), tail(nullptr), count(0) {}
    bool empty() const { return count == 0; }
    int size() const { return count; }
    void push_back(int data)
    {
        Node *newNode = new Node(data);
        if (empty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++count;
    }
    int pop_back()
    {
        if (empty()) return -1;
        Node *delNode = tail;
        int data = delNode->data;
        tail = tail->prev;
        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete delNode;
        --count;
        return data;
    }
    ~DlinkedList()
    {

        while (!empty())
        {
            pop_back();
        }
    }

private:
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
        Node(int data) : data(data), next(nullptr), prev(nullptr) {}
    };
    int count;
    Node *head;
    Node *tail;
};

///////////////////////// self-defined datastructured ///////////////////////

///////////////////////// self-defined functions /////////////////////////////
// int minVal(int a, int b)
// {
//     return a < b ? a : b;
// }
// void quicksort(int arr[], int l, int r)
// {
//     if (l >= r)
//         return;
//     int pivot = arr[(l + r) / 2];
//     int i = l, j = r;
//     while (i <= j)
//     {
//         while (arr[i] < pivot)
//             i++;
//         while (arr[j] > pivot)
//             j--;
//         if (i <= j)
//         {
//             swap(arr[i], arr[j]);
//             i++;
//             j--;
//         }
//     }
//     quicksort(arr, l, j);
//     quicksort(arr, i, r);
// }

///////////////////////// self-defined functions /////////////////////////////





// Task 1: Gather Forces
int gatherForces(int LF1[], int LF2[]);

// Task 2: Deception Strategy
string determineRightTarget(const string &target);
string decodeTarget(const string &message, int EXP1, int EXP2);

// Task 3: Logistics Management
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E);

// Task 4: Attack Planning
int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10]);

// Task 5: Resupply
int resupply(int shortfall, int supply[5][5]);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

#endif /* _TAY_NGUYEN_CAMPAIGN_H_ */
