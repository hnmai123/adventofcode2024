/* 
M.M  
.A.     
S.S

S.M
.A.
S.M

S.S
.A.
M.M

M.S
.A.
M.S 
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string line;
    string filename = "day4_real.txt";
    ifstream myfile(filename);
    vector<vector<char>> rows;
    string word = "MAS";
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
    
    for (int i = 1; i < rows.size() - 1; i++) {
        for (int j = 1; j < rows[i].size() - 1; j ++) {
            if (rows[i][j] == 'A') {
                int row_idx = i;
                int col_idx = j;
                if (
                    (rows[row_idx - 1][col_idx - 1]  == 'M' && 
                    rows[row_idx - 1][col_idx + 1]  == 'M' &&
                    rows[row_idx + 1][col_idx - 1] == 'S' &&
                    rows[row_idx + 1][col_idx + 1] == 'S') ||
                    (rows[row_idx - 1][col_idx - 1]  == 'S' && 
                    rows[row_idx - 1][col_idx + 1]  == 'M' &&
                    rows[row_idx + 1][col_idx - 1] == 'S' &&
                    rows[row_idx + 1][col_idx + 1] == 'M') ||
                    (rows[row_idx - 1][col_idx - 1]  == 'S' && 
                    rows[row_idx - 1][col_idx + 1]  == 'S' &&
                    rows[row_idx + 1][col_idx - 1] == 'M' &&
                    rows[row_idx + 1][col_idx + 1] == 'M') ||
                    (rows[row_idx - 1][col_idx - 1]  == 'M' && 
                    rows[row_idx - 1][col_idx + 1]  == 'S' &&
                    rows[row_idx + 1][col_idx - 1] == 'M' &&
                    rows[row_idx + 1][col_idx + 1] == 'S')
                ) {
                    count += 1;
                }
            } 
        }
    }

    myfile.close();
    cout << count;
    return count;
}