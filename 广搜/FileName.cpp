#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

struct State {
    int x, y; // x��5LͰ��ˮ����y��3LͰ��ˮ��
    State(int a, int b) : x(a), y(b) {}
};

// �������״̬
void printState(const State& state) {
    cout << "(" << state.x << ", " << state.y << ")" << endl;
}

// �����ǰ����
void printOperation(const string& operation) {
    cout << operation << endl;
}

bool bfs() {
    // ��������BFS���洢ÿһ��״̬
    queue<pair<State, string>> q; // ���д洢״̬�͵�ǰ����������
    // �������ڼ�¼���ʹ���״̬�������ظ�����
    set<pair<int, int>> visited;

    // ��ʼ״̬��5LͰ��3LͰ��Ϊ��
    State start(0, 0);
    q.push({ start, "��ʼ״̬: (0, 0)" });
    visited.insert({ 0, 0 });

    while (!q.empty()) {
        // �Ӷ�����ȡ����ǰ״̬
        auto current = q.front();
        q.pop();

        // ��ȡ��ǰ״̬������
        State state = current.first;
        string operation = current.second;

        // �����ǰ״̬�Ͳ���
        printOperation(operation);
        printState(state);

        // ����Ѿ��ﵽ��Ŀ��״̬������true
        if (state.x == 4) {
            cout << "�ҵ�Ŀ��״̬��" << endl;
            return true;
        }

        // �������п��ܵĲ����������µ�״̬
        // ��5LͰװ��
        State next(5, state.y);
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "��5LͰװ��" });
            visited.insert({ next.x, next.y });
        }

        // ��3LͰװ��
        next = State(state.x, 3);
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "��3LͰװ��" });
            visited.insert({ next.x, next.y });
        }

        // ��5LͰ��ˮ����3LͰ
        next = State(state.x - min(state.x, 3 - state.y), state.y + min(state.x, 3 - state.y));
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "��5LͰ��ˮ����3LͰ" });
            visited.insert({ next.x, next.y });
        }

        // ��3LͰ��ˮ����5LͰ
        next = State(state.x + min(state.y, 5 - state.x), state.y - min(state.y, 5 - state.x));
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "��3LͰ��ˮ����5LͰ" });
            visited.insert({ next.x, next.y });
        }

        // ��5LͰ��ˮ����
        next = State(0, state.y);
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "��5LͰ��ˮ����" });
            visited.insert({ next.x, next.y });
        }

        // ��3LͰ��ˮ����
        next = State(state.x, 0);
        if (visited.find({ next.x, next.y }) == visited.end()) {
            q.push({ next, "��3LͰ��ˮ����" });
            visited.insert({ next.x, next.y });
        }
    }

    // �������Ϊ�գ����ʾ�޷��ﵽĿ��״̬
    return false;
}

int main() {
    if (!bfs()) {
        cout << "�޷��ﵽĿ��״̬��" << endl;
    }
    return 0;
}
