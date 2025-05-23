#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <limits> // Added for numeric_limits
using namespace std;

class FairScheduler {
private:
    struct Task {
        int id;
        string name;
        int priority;       // 1=highest, 3=lowest
        int resourceType;   // 1=CPU, 2=Memory, 3=I/O
        int duration;
        int remaining;
        int timesProcessed = 0;
    };

    queue<Task> highPriority;
    queue<Task> mediumPriority;
    queue<Task> lowPriority;

    map<int, string> resourceNames = {
        {1, "CPU"},
        {2, "Memory"},
        {3, "I/O"}
    };

    int taskIdCounter = 1;
    const int TIME_QUANTUM = 5;

    bool allQueuesEmpty() {
        return highPriority.empty() && mediumPriority.empty() && lowPriority.empty();
    }

    void processTaskToCompletion(queue<Task>& taskQueue) {
        Task current = taskQueue.front();
        taskQueue.pop();
        
        cout << "\n[COMPLETING TASK]\n"
             << "----------------------------------------\n"
             << " Name:        " << current.name << "\n"
             << " ID:          " << current.id << "\n"
             << " Priority:    " << current.priority << "\n"
             << " Resource:    " << resourceNames[current.resourceType] << "\n"
             << " Processing:  " << current.remaining << "ms to completion\n"
             << "----------------------------------------\n";
        
        current.timesProcessed++;
        cout << "Task completed in one burst!\n";
    }

public:
    void addTask(string name, int priority, int resourceType, int duration) {
        if (priority < 1 || priority > 3) {
            cerr << "Invalid priority! Use 1-3.\n";
            return;
        }
        if (resourceType < 1 || resourceType > 3) {
            cerr << "Invalid resource type! Use 1=CPU, 2=Memory, 3=I/O\n";
            return;
        }

        Task newTask{taskIdCounter++, name, priority, resourceType, duration, duration};
        
        switch(priority) {
            case 1: highPriority.push(newTask); break;
            case 2: mediumPriority.push(newTask); break;
            case 3: lowPriority.push(newTask); break;
        }
        
        cout << "Added task: " << name << " (ID: " << newTask.id 
             << ", Priority: " << priority 
             << ", Resource: " << resourceNames[resourceType] << ")\n";
    }

    void processTasks() {
        cout << "\nStarting FAIR scheduling...\n";
        cout << "Time quantum: " << TIME_QUANTUM << "ms per task\n";
        
        while(!allQueuesEmpty()) {
            if (!highPriority.empty()) processTaskSlice(highPriority, "HIGH");
            if (!mediumPriority.empty()) processTaskSlice(mediumPriority, "MEDIUM");
            if (!lowPriority.empty()) processTaskSlice(lowPriority, "LOW");
        }
    }

    void processTaskSlice(queue<Task>& queue, const string& priorityLabel) {
        Task current = queue.front();
        queue.pop();
        
        int processTime = min(TIME_QUANTUM, current.remaining);
        current.remaining -= processTime;
        current.timesProcessed++;
        
        cout << "\n[Processing " << priorityLabel << " priority task]\n"
             << " Name: " << current.name << " (" << processTime << "ms)\n"
             << " Remaining: " << current.remaining << "ms\n";
        
        if (current.remaining > 0) {
            queue.push(current);
        } else {
            cout << "Task completed!\n";
        }
    }

    void processByPriority() {
        cout << "\nStarting STRICT PRIORITY execution...\n";
        while (!highPriority.empty()) processTaskToCompletion(highPriority);
        while (!mediumPriority.empty()) processTaskToCompletion(mediumPriority);
        while (!lowPriority.empty()) processTaskToCompletion(lowPriority);
    }

    void printQueues() {
        auto printQueue = [](const string& name, queue<Task> q) {
            cout << name << " (" << q.size() << " tasks):\n";
            while (!q.empty()) {
                Task t = q.front();
                cout << "  " << t.name << " (ID:" << t.id 
                     << ", Rem:" << t.remaining << "ms)\n";
                q.pop();
            }
        };
        
        cout << "\nCurrent Queues:\n====================\n";
        printQueue("High Priority", highPriority);
        printQueue("Medium Priority", mediumPriority);
        printQueue("Low Priority", lowPriority);
        cout << "====================\n";
    }
};

int main() {
    FairScheduler scheduler;
    
    scheduler.addTask("System Monitor", 1, 1, 15);
    scheduler.addTask("User Interface", 2, 1, 20);
    scheduler.addTask("Data Backup", 3, 3, 30);
    
    scheduler.printQueues();
    
    int choice;
    while (true) {
        cout << "\nChoose mode:\n1. Fair\n2. Priority\n> ";
        if (cin >> choice) {
            if (choice == 1 || choice == 2) break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Invalid input! Enter 1 or 2.\n";
    }

    if (choice == 1) scheduler.processTasks();
    else scheduler.processByPriority();
    
    return 0;
}
