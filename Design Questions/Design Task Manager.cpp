class TaskManager {
public:
    // Mapping of taskID to priority
    unordered_map<int,int>task_priority;
    // priority_task -> userID
    map<pair<int,int>,int>priority_task_user;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto task : tasks){
            task_priority[task[1]] = task[2];
            priority_task_user[{task[2],task[1]}] = task[0];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        task_priority[taskId] = priority;
        priority_task_user[{priority,taskId}] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        int priority = task_priority[taskId];
        task_priority[taskId] = newPriority;
        int user = priority_task_user[{priority,taskId}];
        priority_task_user.erase({priority,taskId});
        priority_task_user[{newPriority,taskId}] = user;

    }
    
    void rmv(int taskId) {
        int priority = task_priority[taskId];
        priority_task_user.erase({priority,taskId});
        task_priority.erase(taskId);
    }
    
    int execTop() {
        if(priority_task_user.size()==0)return -1;
        auto res = priority_task_user.rbegin();
        int priority = res->first.first;
        int taskId = res->first.second;
        int result = res->second;
        priority_task_user.erase({priority,taskId});
        task_priority.erase(taskId);
        return result;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */





class TaskManager {
private:
    unordered_map<int, pair<int, int>> taskInfo;
    priority_queue<pair<int, int>> heap;

public:
    TaskManager(vector<vector<int>> tasks) {
        for (auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskInfo[taskId] = {priority, userId};
            heap.emplace(priority, taskId);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {priority, userId};
        heap.emplace(priority, taskId);
    }

    void edit(int taskId, int newPriority) {
        if (taskInfo.find(taskId) != taskInfo.end()) {
            taskInfo[taskId].first = newPriority;
            heap.emplace(newPriority, taskId);
        }
    }

    void rmv(int taskId) { taskInfo.erase(taskId); }

    int execTop() {
        while (!heap.empty()) {
            auto [priority, taskId] = heap.top();
            heap.pop();

            if (taskInfo.find(taskId) != taskInfo.end() &&
                taskInfo[taskId].first == priority) {
                int userId = taskInfo[taskId].second;
                taskInfo.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};
