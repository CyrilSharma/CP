#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

#define maxVal 1000000000

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nodes(n);
    int best = -1;
    int energy = k;
    for (int i = 0; i < n; i++) {
        k--;
        cin >> nodes[i];
    }

    vector<int> triples(n-2);
    for (int i = 2; i < n; i++) {
        triples[i-2] = min(nodes[i], nodes[i-1], nodes[i-2]);
    }

    // THINK. We need the string of combinations of upto k length strings that compositely get us to the destination
    // the only issue is that we need the strings to use the minimum value possible!
    // list all possible triples. (0, 1, 2), (1, 2, 3), (2, 3, 4)...
    // how do i think of this as a graph.
    // we want the path that takes us to node n, that uses the highest weight nodes possible.
    // there are so many possible paths though!
    // paths 
    // connect triples if they are within three apart. 
}