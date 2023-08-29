/*
ID: cyrilsh1
TASK: transform
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void render(char **m1, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << m1[i][j] << "";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

char** initialize2DArray(int n) {
    char **m2;
    m2 = new char*[n];
    for (int i = 0; i < n; i++) {
        m2[i] = new char[n];
    }
    return m2;
}

char** r1(char **m1, int n) {
    char **m2 = initialize2DArray(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m2[i][j] = m1[n-1-j][i];
        }
    }
    return m2;
}

char** r2(char **m1, int n) {
    char **m2 = initialize2DArray(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m2[i][j] = m1[n-1-i][n-1-j];
        }
    }
    return m2;
}

char** r3(char **m1, int n) {
    char **m2 = initialize2DArray(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m2[i][j] = m1[j][n-1-i];
        }
    }
    return m2;
}

char** rotateMatrix(char **m1, int n, int r) {
    int rotations = r % 4;
    if (rotations == 0) {
        return m1;
    }
    else if (rotations == 1) {
        return r1(m1, n);
    }
    else if (rotations == 2) {
        return r2(m1, n);
    }
    else {
        return r3(m1, n);
    }
}

char** reflectMatrix(char **m1, int n) {
    char **m2 = initialize2DArray(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // rows - columns or y - x, hence reflection about x involves j.
            m2[i][n-1-j] = m1[i][j];
        }
    }
    return m2;
}

bool matrixEquality(char **m1, char **m2, int n) {
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (m1[i][j] != m2[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    int size;
    FILE* fin = fopen("transform.in", "r");
    fscanf (fin, "%d\n", &size);

    char **ogSquare = initialize2DArray(size);
    char **newSquare = initialize2DArray(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            fscanf (fin, "%c ", &ogSquare[i][j]);
        }
        fscanf (fin, "%c\n", &ogSquare[i][size-1]);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            fscanf (fin, "%c ", &newSquare[i][j]);
        }
        fscanf (fin, "%c\n", &newSquare[i][size-1]);
    }

    int minType = 8;
    int type = 7;
    bool equal;
    char** transformedSquare;
    for (int i = 0; i < 4; i++) {
        transformedSquare = rotateMatrix(ogSquare, size, i);
        equal = matrixEquality(transformedSquare, newSquare, size);

        if (equal) {
            if (i == 0)
                type = 6;
            else
                type = i;
        }

        if (type < minType) {
            minType = type;
        }

        transformedSquare = reflectMatrix(transformedSquare, size);
        equal = matrixEquality(transformedSquare, newSquare, size);

        if (equal) {
            if (i == 0)
                type = 4;
            else
                type = 5;
        }

        if (type < minType) {
            minType = type;
        }
    }
    
    FILE* fout = fopen("transform.out", "w");
    fprintf (fout, "%d\n", minType);
}