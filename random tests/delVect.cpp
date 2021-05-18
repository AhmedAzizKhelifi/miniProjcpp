#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void PrintVec(vector<int> &vec)
{
    for (const auto &item : vec) {
        cout << item << "; ";
    }
    cout << endl;
}

int main() {
    std::vector<int> v;
    for (int i = 0; i<10; i++)
        v.push_back(i);

    PrintVec(v);
    v.erase(v.begin() + 1);
    PrintVec(v);
}