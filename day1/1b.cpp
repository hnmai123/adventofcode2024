#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string line;
    string file_name = "extra.txt";
    ifstream myfile (file_name);
    vector<int> left_list, right_list;
    int left_element, right_element;

    if (myfile.is_open()) {
        while (myfile >> left_element >> right_element) {
            left_list.push_back(left_element);
            right_list.push_back(right_element);
        }
    }

    int list_length = left_list.size();
    int similarity_score = 0;

    for (int i = 0; i < list_length; i++) {
        int frequency = 0;
        for (int j = 0; j < list_length; j++) {
            if (left_list[i] == right_list[j]) {
                frequency += 1;
            }
        }
        similarity_score += left_list[i] * frequency;
    }

    cout << similarity_score;
    myfile.close();

    return similarity_score;
}
