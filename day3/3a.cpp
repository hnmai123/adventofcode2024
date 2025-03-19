#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string filename = "day3_test.txt";
    ifstream myfile(filename);
    char character;
    string line;
    regex key("mul\\((\\d+),(\\d+)\\)");
    int sum = 0;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {

            sregex_iterator begin(line.begin(), line.end(), key);
            sregex_iterator end;

            for (sregex_iterator i = begin; i != end; i ++) {
                smatch match = *i;
                string num1 = match[1];
                string num2 = match[2]; 

                int x = stoi(num1);
                int y = stoi(num2);
                sum += x*y;
            }
        }
    }
    cout << sum;
    myfile.close();
    return sum;
}