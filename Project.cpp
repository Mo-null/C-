#include <iostream>
#include <string>
using namespace std;

// Task structure (holds task data)
struct Task {
    int id;
    string name;
    int priority;
    int resourceType; // 1 = CPU, 2 = Memory, 3 = I/O
    int duration;
};

// Node structure (holds a Task + pointer to next Node)
struct Node {
    Task data;
    Node* next;
};

// Add a new task to the front of the list (modifies original head)
void insertAtHead(Node** head, Task newTask) {
    Node* newNode = new Node{newTask, *head}; // Create new node pointing to current head
    *head = newNode; // Update original head to point to the new node
}

// Remove the first task (allocates resources)
void allocateResources(Node** head) {
    if (!*head) {
        cout << "No tasks to allocate!\n";
        return;
    }
    Node* temp = *head;       // Store old head
    *head = (*head)->next;    // Update head to next node
    cout << "Allocating resources to: " << temp->data.name << "\n";
    delete temp;              // Free memory
}

// Print all tasks in the list
void printList(Node* head) {
    while (head) {
        cout << "Task: " << head->data.name 
             << " (Priority: " << head->data.priority 
             << ", Resource: " << head->data.resourceType 
             << ")\n";
        head = head->next;
    }
}

int main() {
    Node* head = nullptr; // Start with empty list

    // Add tasks to the scheduler
    insertAtHead(&head, {1, "Process A", 2, 1, 10}); // CPU task
    insertAtHead(&head, {2, "Process B", 1, 2, 5});  // Memory task
    insertAtHead(&head, {3, "Process C", 3, 3, 15}); // I/O task

    // Print initial list
    cout << "Current Tasks:\n";
    printList(head); // Output: Process C → Process B → Process A

    // Allocate resources (remove first task)
    cout << "\nAllocating resources...\n";
    allocateResources(&head); // Removes "Process C"

    // Print updated list
    cout << "\nRemaining Tasks:\n";
    printList(head); // Output: Process B → Process A

    return 0;
}
