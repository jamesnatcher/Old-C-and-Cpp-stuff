#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    string a;
    vector<string> lines;

    while (1){
        cout << "Please enter a line, enter \"quit\" to quit entering lines: " << endl;
        getline(cin, a);
        if (a == string("quit")){
            break;
        }
        lines.push_back(a);
    }
    for (int i = 0; i < lines.size(); ++i){
        cout << "Line #" << i + 1 << ": " << lines[i] << endl;
    }
    return 0;
}