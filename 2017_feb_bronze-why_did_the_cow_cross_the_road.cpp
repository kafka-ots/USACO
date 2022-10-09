#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {

    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");
    string cowmap;
    fin >> cowmap;
    //string cowmap = "ABCCABDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZ";
    int count = 0;

    int start[26], end[26];
    fill(start, start + 26, -1);
	fill(end, end + 26, -1);

    for (int i = 0; i < cowmap.size(); i++) {
        	if (start[cowmap[i]-'A'] == -1) { //so for example because A is the '0th' letter in the alphabet
                start[cowmap[i]-'A'] = i;
            } else {
                end[cowmap[i]-'A'] = i;
            }
    }

    for (int i = 0; i <= 26; i++) {
        for (int j = 0; j <= 26; j++) {
            if (start[i] < start[j] && start[j] < end[i] && end[i] < end[j]) {
                count++;
            }
        }
    }


    fout << count << "\n";
}
