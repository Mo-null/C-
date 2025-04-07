#include <iostream>
#include <string>
using namespace std;


struct Task {
    int id;
    string name;
    int priority;
    int resourceType; // 1 = CPU, 2 = Memory, 3 = I/O
    int duration;
};

struct Node {
    Task data;  // Preserve original field name 'data'
    Node* next;
};


void addTaskToFront(Node** head, Task newTask) {
    Node* newNode = new Node{newTask, *head}; 
    *head = newNode;
}

void processNextTask(Node** head) {
    if (!*head) {
        cout << "No tasks to allocate!\n";
        return;
    }

    Node* taskToRemove = *head;
    *head = (*head)->next;

    cout << "Allocating resources to: " << taskToRemove->data.name << "\n";
    delete taskToRemove;
}

void printTaskList(Node* head) {
    while (head) {
        cout << "Task: " << head->data.name 
             << " (Priority: " << head->data.priority 
             << ", Resource: " << head->data.resourceType 
             << ")\n";
        head = head->next;
    }
}

int main() {
    Node* taskList = nullptr;

    
    addTaskToFront(&taskList, {1, "Process A", 2, 1, 10});
    addTaskToFront(&taskList, {2, "Process B", 1, 2, 5});
    addTaskToFront(&taskList, {3, "Process C", 3, 3, 15});

    cout << "Current Tasks:\n";
    printTaskList(taskList);

    cout << "\nAllocating resources...\n";
    processNextTask(&taskList);

    cout << "\nRemaining Tasks:\n";
    printTaskList(taskList);

    return 0;
}
