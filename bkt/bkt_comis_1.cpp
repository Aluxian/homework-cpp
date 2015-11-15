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

int traseu[100], nrOrase, nrDrumuri, orasInitial;
bool conectat[100][100];

void citire() {
    ifstream fin("bkt_comis_1.in");
    fin >> nrOrase >> nrDrumuri;
    
    for (int x, y, i = 1; i <= nrDrumuri; i++) {
        fin >> x >> y;
        conectat[x][y] = conectat[y][x] = true;
    }
    
    fin >> orasInitial;
}

bool valid(int p) {
    for (int i = 1; i < p; i++)
        if (traseu[i] == traseu[p])
            return false;
    
    if (!conectat[traseu[p-1]][traseu[p]])
        return false;
    
    if (p == nrOrase && !conectat[traseu[p]][traseu[1]])
        return false;
    
    return true;
}

bool solutie(int p) {
    return p == nrOrase;
}

void afis(int p) {
    for (int i = 1; i <= p; i++) {
        cout << traseu[i] << " ";
    }
    
    cout << traseu[1] << endl;
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
    bkt(2);
    return 0;
}
