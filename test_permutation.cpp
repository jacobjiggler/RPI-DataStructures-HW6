#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector < vector<int> > g;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    b.push_back(4);
    b.push_back(5);
    b.push_back(6);
    c.push_back(7);
    c.push_back(8);
    c.push_back(9);


    g.push_back(a);
    g.push_back(b);
    g.push_back(c);

    // int o[] = { 4, 5, 6 };
    // do {
    // for (int h = 0; h < 3; h++){
    // cout << o[h];
    // }
    // cout << endl;
    // } while ( next_permutation (o,o+3) );








    int counter = 0;
    int i = 0;

    // do {
        // do {
            // i = 0;
            // while (i < g.size()) {

                // for (int h = 0; h < g[i].size(); h++) {

                    // cout << g[i][h];
                // }
                // cout << " ";
                // i++;

            // }
            // i = 0;
            // counter++;
            // cout << endl;
        // } while ( next_permutation (g[i].begin(),g[i].end())) ;

        // i++;
        // cout << endl;

    // } while ( next_permutation (g[i].begin(),g[i].end())) ;


    // cout << counter << endl;



    //permutation of one calling another permutation to return vector of itself permutated.

	for (h = 0; h < g[0].size(); h++){
		for (
    do {



	

			cout << g[i][h];
		


		
    } while ( next_permutation (g[i].begin(),g[i].end())) ;

cout << endl;
		}




    return 0;
}