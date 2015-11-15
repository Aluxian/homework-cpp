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

int traseu[100], traseuMinim[100], drum[100][100], distMin, nrOrase, nrDrumuri;

void citire() {
    ifstream fin("bkt_comis_3.in");
    fin >> nrOrase >> nrDrumuri;
    
    for (int x, y, distanta, i = 1; i <= nrDrumuri; i++) {
        fin >> x >> y >> distanta;
        drum[x][y] = drum[y][x] = distanta;
    }
    
    distMin = INT_MAX;
}

bool solutie(int p) {
    return p == nrOrase;
}

bool valid(int p) {
    for (int i = 1; i < p; i++)
        if (traseu[i] == traseu[p])
            return false;
    
    if (p > 1 && !drum[traseu[p-1]][traseu[p]])
        return false;
    
    if (solutie(p) && !drum[traseu[p]][traseu[1]])
        return false;
    
    return true;
}

void afis(int p) {
    int dist = 0;
    
    for (int i = 1; i < p; i++)
        dist += drum[traseu[i]][traseu[i+1]];
    
    if (dist < distMin)
        for (int i = 1; i <= p; i++)
            traseuMinim[i] = traseu[i];
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
    bkt(1);
    
    for (int i = 1; i <= nrOrase; i++)
        cout << traseuMinim[i] << " ";
    cout << endl;
    
    return 0;
}
