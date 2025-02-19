#include <iostream>
#include <string>

using namespace std;

class ToDoList {
private:
    int MAX_TASKS;
    string tasks[50];
    bool taskStatus[50];
    int nextIndex;

public:
    ToDoList(int maxTasks) : MAX_TASKS(maxTasks), nextIndex(0) {}

    void AddTask(const string& taskName) {
        if(nextIndex < MAX_TASKS){
            tasks[nextIndex] = taskName;
            taskStatus[nextIndex] = false;
            cout << "Task added." << endl;
            nextIndex++;
        }else{
            cout << "Task list is full." << endl;
        }
    }

    void ViewTasks() {
        if(nextIndex == 0) {
            cout<<"No tasks to display." << endl;
            return;
        }

        cout<<"\nTasks:" << endl;
        for(int i = 0; i < nextIndex; ++i) {
            cout<<i + 1 << ". " << tasks[i] << " - " << (taskStatus[i] ? "Completed" : "Pending") << endl;
        }
    }

    void MarkTaskAsCompleted(int index) {
        if(index>= 1 && index <= nextIndex) {
            taskStatus[index - 1] = true;
            cout<<"Task marked as completed."<<endl;
        } else{
            cout<<"Invalid task index."<<endl;
        }
    }

    void RemoveTask(int index){
        if (index >= 1 && index<=nextIndex) {
            for (int i = index - 1; i < nextIndex - 1; ++i) {
                tasks[i] = tasks[i + 1];
                taskStatus[i] = taskStatus[i + 1];
            }
            nextIndex--;
            cout<<"Task removed."<<endl;
        } else{
            cout<< "Invalid task index."<<endl;
        }
    }
};

int main() {
    int maxTasks;
    cout<<"Enter the maximum number of tasks: ";
    cin>>maxTasks;
    ToDoList todoList(maxTasks);

    while (true) {
        cout<<"\nMenu:" << endl;
        cout<<"1. Add Task" << endl;
        cout<<"2. View Tasks" << endl;
        cout<<"3. Mark Task as Completed" << endl;
        cout<<"4. Remove Task" << endl;
        cout<<"5. Exit" << endl;

        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1: {
                string taskName;
                cout<<"Enter task: ";
                cin.ignore();
                getline(cin, taskName);
                todoList.AddTask(taskName);
                break;
            }
            case 2:
                todoList.ViewTasks();
                break;
            case 3: {
                int index;
                cout<<"Enter task index to mark as completed: ";
                cin>>index;
                todoList.MarkTaskAsCompleted(index);
                break;
            }
            case 4: {
                int index;
                cout<<"Enter task index to remove: ";
                cin>>index;
                todoList.RemoveTask(index);
                break;
            }
            case 5:
                cout<<"Exiting program." << endl;
                return 0;
            default:
                cout<<"Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}