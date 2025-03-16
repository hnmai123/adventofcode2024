#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    string file_name = "day1_real.txt";
    ifstream myfile (file_name);
    vector<int> left_list, right_list;
    int left_element, right_element;

    if (myfile.is_open()) {
        while (myfile >> left_element >> right_element) {
            left_list.push_back(left_element);
            right_list.push_back(right_element);
        }
    }
    
    sort(left_list.begin(), left_list.end());
    sort(right_list.begin(), right_list.end());
    
    int list_length = left_list.size();
    int total_distance = 0;
    
    for (int i = 0; i < list_length; i++) {
        int distance = abs(left_list[i] - right_list[i]);
        total_distance += distance;
    }
    cout << total_distance;
    myfile.close();

    return total_distance;
}


