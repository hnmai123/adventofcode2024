#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string filename = "day3_real.txt";
    ifstream myfile(filename);
    char character;
    string line;

    regex key("mul\\((\\d+),(\\d+)\\)|do\\(\\)|don't\\(\\)");

    bool status = true;
    int sum = 0;
    int pointer = 0;
    
    if (myfile.is_open()) {
        while (getline(myfile, line)) {

            sregex_iterator begin(line.begin(), line.end(), key);
            sregex_iterator end;

            for (sregex_iterator i = begin; i != end; i ++) {
                smatch match = *i;
                string match_str =  i->str();
                if (match_str == "do()") {
                    status = true;
                } else if (match_str == "don't()") {
                    status = false;
                } else if (status) {
                    string num1 = match[1];
                    string num2 = match[2]; 

                    int x = stoi(num1);
                    int y = stoi(num2);
                    sum += x*y;
                }
            
            }
        }
    }
    cout << sum;
    myfile.close();
    return sum;
}
