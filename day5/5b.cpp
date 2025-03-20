#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool check_update(vector<int> update, vector<vector<int>> rules) {
    for (int i = 0; i < rules.size(); i++) {
        int left_num = rules[i][0];
        int right_num = rules[i][1];

        auto before_pos = find(update.begin(), update.end(), left_num);
        auto after_pos = find(update.begin(), update.end(), right_num);
        
        // if pages exists
        if (before_pos != update.end() && after_pos != update.end()) {
            if (before_pos > after_pos) {
                return false;
            }
        }
    }
    return true;
}

vector<int> reorder_update(vector<int> update, vector<vector<int>> rules) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;

        for (int i = 0; i < rules.size(); i++) {
            int left_num = rules[i][0];
            int right_num = rules[i][1];
    
            auto before_pos = find(update.begin(), update.end(), left_num);
            auto after_pos = find(update.begin(), update.end(), right_num);
            
            // check one more time after swapped and if the number in the rules appear in the update
            if (before_pos != update.end() && after_pos != update.end() && before_pos > after_pos) {
                swap(*before_pos, *after_pos);
                sorted = false;
            }
        }
    }
    return update;
}

int main() {
    string line;
    string filename = "day5_real.txt";
    ifstream myfile(filename);
    vector<vector<int>> rules;
    vector<vector<int>> updates;
    int sum = 0;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (line.find('|') != string::npos) {
                int left_num, right_num;
                vector<int> rule;
                sscanf(line.c_str(), "%d|%d", &left_num, &right_num);
                rule.push_back(left_num);
                rule.push_back(right_num);
                rules.push_back(rule);

            } else if (line.find(',') != string::npos) {
                vector<int> update;
                stringstream ss(line);
                string num;
                while (getline(ss, num, ',')) {
                    update.push_back(stoi(num));
                } 
                updates.push_back(update);
            }
        }   
    }

    for (int j = 0; j < updates.size(); j++) {
        if (!check_update(updates[j], rules)) {
            vector<int> fix_update = reorder_update(updates[j], rules);
            int mid_idx = fix_update.size() / 2;
            sum += fix_update[mid_idx];
        }
    }
    cout << sum;
    myfile.close();
    return sum;
}