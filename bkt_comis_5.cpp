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

int traseu[100], drum[100][100], nrOrase, nrDrumuri, orasInitial;
double carburant, consum, maxAlimentare;

void citire() {
    ifstream fin("bkt_comis_5.in");
    fin >> nrOrase >> nrDrumuri;
    
    for (int x, y, dist, i = 1; i <= nrDrumuri; i++) {
        fin >> x >> y >> dist;
        drum[x][y] = drum[y][x] = dist;
    }
    
    fin >> orasInitial;
    
    cout << "Carburant initial, consum l/km, cant. max alim. oras" << endl;
    cin >> carburant >> consum >> maxAlimentare;
}

bool valid(int p) {
    for (int i = 1; i < p; i++)
        if (traseu[i] == traseu[p])
            return false;
    
    if (!drum[traseu[p-1]][traseu[p]])
        return false;
    
    if (p == nrOrase && !drum[traseu[p]][traseu[1]])
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
        
        double consumat = drum[traseu[p-1]][traseu[p]] * consum;
        carburant -= consumat;
        
        if (carburant >= 0) {
            carburant += maxAlimentare;
            
            if (valid(p)) {
                if (solutie(p)) {
                    afis(p);
                } else
                    bkt(p + 1);
            }
            
            carburant -= maxAlimentare;
        }
        
        carburant += consumat;
    }
}

int main() {
    citire();
    traseu[1] = orasInitial;
    bkt(2);
    return 0;
}
