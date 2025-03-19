/* look like it rotate 90 degree 180 degree 270 degree
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
    string filename = "day4_test.txt";
    ifstream myfile(filename);
    vector<vector<char>> rows;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            vector<char> row;
            for (int i = 0; i < line.length(); i++) {
                row.push_back(line[i]);
            }
            rows.push_back(row);
        }
    }
    
    myfile.close();
}