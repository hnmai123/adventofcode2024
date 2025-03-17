#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

bool is_safe(vector<int> row) {
    bool is_decreasing = true;
    bool is_increasing = true;

    for (int j = 0; j < row.size() - 1; j++) {
        
        int different = abs(row[j] - row[j+1]);

        if (different > 3 || different < 1) {
            return false;
        }
        if (row[j] < row[j+1]) {
            is_decreasing = false;
        }
        if (row[j] > row[j+1]) {
            is_increasing = false;
        }
    }
    return is_decreasing ^ is_increasing;
}

int main() {
    string line;
    string filename = "day2_real.txt";
    vector<vector<int>> rows;
    ifstream myfile(filename);
    
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            stringstream ss(line);
            vector<int> report;
            int element;

            while (ss >> element) {
                report.push_back(element);
            }

            rows.push_back(report);
        }
    }

    int safe_count = 0;
    for (int i = 0; i < rows.size(); i++) {
        if (is_safe(rows[i])) {
            safe_count += 1;
        }
    }

    cout << safe_count;
    myfile.close();
    return safe_count;
}