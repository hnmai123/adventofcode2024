#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string line;
    string filename = "day4_real.txt";
    ifstream myfile(filename);
    vector<vector<char>> rows;
    // Right, Up, Left, Down, Right Up (diagonal), Right Down (diagonal), Left Up (diagonal), Left Down (diagonal)
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; 
    string word = "XMAS";
    bool check_word = false;
    int count = 0;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            vector<char> row;
            for (int i = 0; i < line.length(); i++) {
                row.push_back(line[i]);
            }
            rows.push_back(row);
        }
    }

    for (int i = 0; i < rows.size(); i ++) {
        for (int j = 0; j < rows[i].size(); j++) {
            if (rows[i][j] == 'X') {
                // Check XMAS in each direction
                for (int k = 0; k < directions.size(); k++) {
                    // Check each character of that direction
                    for (int l = 1; l <= 3; l++) {
                        int row_idx = i + directions[k][1]*l;
                        int col_idx = j + directions[k][0]*l;
                        if (row_idx < 0 || // if move up outbound
                            row_idx >= rows.size() || // if move down outbound
                            col_idx < 0 || // if move left outbound
                            col_idx >= rows[i].size() || // if move right outbound
                            rows[row_idx][col_idx] != word[l]) // if next character not match
                        {
                            check_word = false;
                            break;
                        } else if (rows[row_idx][col_idx] == word[l]) {
                            check_word = true;
                        } 
                    }
                    if (check_word) {
                        count += 1;
                    }
                }
            }
        }
    }

    cout << count;
    myfile.close();
    return count;
}