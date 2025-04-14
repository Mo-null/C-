#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

class FairScheduler {
private:
    // Task structure
    struct Task {
        int id;
        string name;
        int priority;       // 1=highest, 3=lowest
        int resourceType;   // 1=CPU, 2=Memory, 3=I/O
        int duration;       // Total required processing time
        int remaining;      // Remaining processing time
        int timesProcessed = 0;
    };

    // Priority queues
    queue<Task> highPriority;    // Priority 1
    queue<Task> mediumPriority;  // Priority 2
    queue<Task> lowPriority;     // Priority 3

    // Resource type names
    map<int, string> resourceNames = {
        {1, "CPU"},
        {2, "Memory"},
        {3, "I/O"}
    };

    int taskIdCounter = 1;
    const int TIME_QUANTUM = 5; // ms per task turn

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
        Task newTask{taskIdCounter++, name, priority, resourceType, duration, duration};
        
        switch(priority) {
            case 1: highPriority.push(newTask); break;
            case 2: mediumPriority.push(newTask); break;
            case 3: lowPriority.push(newTask); break;
            default: cerr << "Invalid priority!\n"; return;
        }
        
        cout << "Added task: " << name << " (ID: " << newTask.id 
             << ", Priority: " << priority 
             << ", Resource: " << resourceNames[resourceType] << ")\n";
    }

    void processTasks() {
        cout << "\nStarting FAIR scheduling...\n";
        cout << "Time quantum: " << TIME_QUANTUM << "ms per task\n";
        
        while(!allQueuesEmpty()) {
            if (!highPriority.empty()) {
                Task current = highPriority.front();
                highPriority.pop();
                
                int processTime = min(TIME_QUANTUM, current.remaining);
                current.remaining -= processTime;
                current.timesProcessed++;
                
                cout << "\n[Processing HIGH priority task]\n"
                     << " Name: " << current.name << " (" << processTime << "ms)\n"
                     << " Remaining: " << current.remaining << "ms\n";
                
                if (current.remaining > 0) {
                    highPriority.push(current);
                } else {
                    cout << "Task completed!\n";
                }
            }
            
            if (!mediumPriority.empty()) {
                // Same pattern for medium priority...
                Task current = mediumPriority.front();
                mediumPriority.pop();
                int processTime = min(TIME_QUANTUM, current.remaining);
                current.remaining -= processTime;
                if (current.remaining > 0) {
                    mediumPriority.push(current);
                }
            }
            
            if (!lowPriority.empty()) {
                // Same pattern for low priority...
                Task current = lowPriority.front();
                lowPriority.pop();
                int processTime = min(TIME_QUANTUM, current.remaining);
                current.remaining -= processTime;
                if (current.remaining > 0) {
                    lowPriority.push(current);
                }
            }
        }
    }

    void processByPriority() {
        cout << "\nStarting STRICT PRIORITY execution...\n";
        
        while (!highPriority.empty()) {
            processTaskToCompletion(highPriority);
        }
        
        while (!mediumPriority.empty()) {
            processTaskToCompletion(mediumPriority);
        }
        
        while (!lowPriority.empty()) {
            processTaskToCompletion(lowPriority);
        }
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
        
        cout << "\nCurrent Queues:\n";
        cout << "====================\n";
        printQueue("High Priority", highPriority);
        printQueue("Medium Priority", mediumPriority);
        printQueue("Low Priority", lowPriority);
        cout << "====================\n";
    }
};

int main() {
    FairScheduler scheduler;
    
    // Add test tasks
    scheduler.addTask("System Monitor", 1, 1, 15);
    scheduler.addTask("User Interface", 2, 1, 20);
    scheduler.addTask("Data Backup", 3, 3, 30);
    
    scheduler.printQueues();
    
    cout << "\nChoose mode:\n1. Fair\n2. Priority\n> ";
    int choice;
    cin >> choice;
    
    if (choice == 2) {
        scheduler.processByPriority();
    } else {
        scheduler.processTasks();
    }
    
    return 0;
}
