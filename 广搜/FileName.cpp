#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

struct State {
    int x, y; // x是5L桶的水量，y是3L桶的水量
    State(int a, int b) : x(a), y(b) {}
};

// 用于输出状态
void printState(const State& state) {
    cout << "(" << state.x << ", " << state.y << ")" << endl;
}

// 输出当前操作
void printOperation(const string& operation) {
    cout << operation << endl;
}

bool bfs() {
    // 队列用于BFS，存储每一个状态
    queue<pair<State, string>> q; // 队列存储状态和当前操作的描述
    // 集合用于记录访问过的状态，避免重复访问
    set<pair<int, int>> visited;

    // 初始状态，5L桶和3L桶都为空
    State start(0, 0);
    q.push({ start, "初始状态: (0, 0)" });
    visited.insert({ 0, 0 });

    while (!q.empty()) {
        // 从队列中取出当前状态
        auto current = q.front();
        q.pop();

        // 获取当前状态和描述
        State state = current.first;
        string operation = current.second;

        // 输出当前状态和操作
        printOperation(operation);
        printState(state);

        // 如果已经达到了目标状态，返回true
        if (state.x == 4) {
            cout << "找到目标状态！" << endl;
            return true;
        }

        // 进行所有可能的操作，生成新的状态
        // 将5L桶装满
        State next(5, state.y);
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "将5L桶装满" });
            visited.insert({ next.x, next.y });
        }

        // 将3L桶装满
        next = State(state.x, 3);
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "将3L桶装满" });
            visited.insert({ next.x, next.y });
        }

        // 将5L桶的水倒入3L桶
        next = State(state.x - min(state.x, 3 - state.y), state.y + min(state.x, 3 - state.y));
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "将5L桶的水倒入3L桶" });
            visited.insert({ next.x, next.y });
        }

        // 将3L桶的水倒入5L桶
        next = State(state.x + min(state.y, 5 - state.x), state.y - min(state.y, 5 - state.x));
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "将3L桶的水倒入5L桶" });
            visited.insert({ next.x, next.y });
        }

        // 将5L桶的水倒掉
        next = State(0, state.y);
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "将5L桶的水倒掉" });
            visited.insert({ next.x, next.y });
        }

        // 将3L桶的水倒掉
        next = State(state.x, 0);
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "将3L桶的水倒掉" });
            visited.insert({ next.x, next.y });
        }
    }

    // 如果队列为空，则表示无法达到目标状态
    return false;
}

int main() {
    if (!bfs()) {
        cout << "无法达到目标状态。" << endl;
    }
    return 0;
}
