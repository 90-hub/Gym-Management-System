#include <iostream>
#include <string>
using namespace std;

// Structure for each gym member
struct Node {
    string name;
    int age;
    float weight;
    Node* next;
};

Node* head = NULL;

// Add a gym member to the list
void addMember(string name, int age, float weight) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->age = age;
    newNode->weight = weight;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display the member list
void displayMembers() {
    Node* temp = head;
    cout << "\nGYM MEMBER LIST:\n";
    while (temp != NULL) {
        cout << "Name: " << temp->name
             << ", Age: " << temp->age
             << ", Weight: " << temp->weight << "kg\n";
        temp = temp->next;
    }
}

// Bubble Sort by weight
void bubbleSort() {
    if (head == NULL) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->weight > ptr1->next->weight) {
                swap(ptr1->name, ptr1->next->name);
                swap(ptr1->age, ptr1->next->age);
                swap(ptr1->weight, ptr1->next->weight);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Selection Sort by weight
void selectionSort() {
    for (Node* i = head; i != NULL; i = i->next) {
        Node* min = i;
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->weight < min->weight)
                min = j;
        }
        if (min != i) {
            swap(i->name, min->name);
            swap(i->age, min->age);
            swap(i->weight, min->weight);
        }
    }
}

// Insertion Sort by weight
void insertionSort() {
    if (head == NULL || head->next == NULL)
        return;

    Node* sorted = NULL;

    while (head != NULL) {
        Node* current = head;
        head = head->next;

        if (sorted == NULL || current->weight < sorted->weight) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->weight < current->weight)
                temp = temp->next;

            current->next = temp->next;
            temp->next = current;
        }
    }
    head = sorted;
}

// Menu
void menu() {
    int choice;
    string name;
    int age;
    float weight;

    do {
        cout << "\n--- GYM MANAGEMENT SYSTEM ---\n";
        cout << "1. Add Member\n";
        cout << "2. Display Members\n";
        cout << "3. Sort by Weight (Bubble Sort)\n";
        cout << "4. Sort by Weight (Selection Sort)\n";
        cout << "5. Sort by Weight (Insertion Sort)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Member Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Weight (kg): ";
                cin >> weight;
                addMember(name, age, weight);
                break;

            case 2:
                displayMembers();
                break;

            case 3:
                bubbleSort();
                cout << "Sorted using Bubble Sort!\n";
                break;

            case 4:
                selectionSort();
                cout << "Sorted using Selection Sort!\n";
                break;

            case 5:
                insertionSort();
                cout << "Sorted using Insertion Sort!\n";
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}

// Main function
int main() {
    menu();
    return 0;
}

