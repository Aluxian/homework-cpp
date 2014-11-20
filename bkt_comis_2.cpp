//
//  main.cpp
//  Homework
//
//  Created by Alexandru Rosianu on 09/11/14.
//  Copyright (c) 2014 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int traseu[100], traseuMinim[100], nrOrase, nrDrumuri, orasInitial, orasFinal;
bool conectat[100][100];

void citire() {
    ifstream fin("bkt_comis_2.in");
    fin >> nrOrase >> nrDrumuri;
    
    for (int x, y, i = 1; i <= nrDrumuri; i++) {
        fin >> x >> y;
        conectat[x][y] = conectat[y][x] = true;
    }
    
    fin >> orasInitial >> orasFinal;
}

bool valid(int p) {
    for (int i = 1; i < p; i++)
        if (traseu[i] == traseu[p])
            return false;
    
    if (!conectat[traseu[p-1]][traseu[p]])
        return false;
    
    return p < traseuMinim[0];
}

bool solutie(int p) {
    return traseu[p] == orasFinal;
}

void afis(int p) {
    if (p < traseuMinim[0]) {
        traseuMinim[0] = p;
        for (int i = 1; i <= p; i++)
            traseuMinim[i] = traseu[i];
    }
}

void bkt(int p) {
    for (int i = 1; i <= nrOrase; i++) {
        traseu[p] = i;
        
        if (valid(p)) {
            if (solutie(p)) {
                afis(p);
            } else
                bkt(p + 1);
        }
    }
}

int main() {
    citire();
    
    traseu[1] = orasInitial;
    traseuMinim[0] = INT_MAX;
    
    bkt(2);
    
    for (int i = 1; i <= traseuMinim[0]; i++)
        cout << traseuMinim[i] << " ";
    cout << endl;
    
    return 0;
}
