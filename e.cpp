#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> bb;
    deque<int> nn; 

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        bb.push_back(x);
    }
    for (int j = 0; j < 5; j++) {
        int y;
        cin >> y;
        nn.push_back(y);
    }

    int count = 0;
    bool n = true;

    while (!bb.empty() && !nn.empty()) {
        int b = bb.front();
        int nurs = nn.front();
        bb.pop_front();
        nn.pop_front();

        if ((b == 0 && nurs == 9)) {
            bb.push_back(b);
            bb.push_back(nurs);
        } else if ((b == 9 && nurs == 0)) {
            nn.push_back(b);
            nn.push_back(nurs);
        } else if (b > nurs) {
            bb.push_back(b);
            bb.push_back(nurs);
        } else {
            nn.push_back(b);
            nn.push_back(nurs);
        }

        count++;
        if (count > 1000000) {
            n = false;
            break;
        }
    }

    if (n) {
        if (bb.size() > nn.size())
            cout << "Boris " << count;
        else
            cout << "Nursik " << count;
    } else {
        cout << "blin nichya";
    }

    return 0;
}
