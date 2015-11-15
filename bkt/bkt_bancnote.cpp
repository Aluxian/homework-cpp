//
//  main.cpp
//  Homew
//
//  Created by Alexandru Rosianu on 09/11/14.
//  Copyright (c) 2014 Alexandru Rosianu. All rights reserved.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int s[10], bills[10], n, S;
bool doAfis = false;

void citire() {
    cout << "Input: S, n then bill values" << endl;
    cin >> S >> n;
    for (int i = 1; i <= n; i++) {
        cin >> bills[i];
    }
}

bool valid(int p, long sum) {
    if (p == n) {
        return sum == S;
    } else {
        return sum <= S;
    }
}

bool solutie(int p) {
    return p == n;
}

void bkt(int p, long sum) {
    for (int i = 0; i <= S / bills[p]; i++) {
        s[p] = i;
        long s2 = sum + i * bills[p];
        
//        if (valid(p, s2)) {
//            if (solutie(p))
//                afis(p);
//            else
//                bkt(p + 1, s2);
//        }
        
        if (p == n ? s2 == S : s2 <= S) {
            if (p == n) {
                if (doAfis) {
                    for (int i = 1; i <= n; i++)
                        cout << s[i] << " x " << bills[i] << endl;
                    cout << endl;
                }
            } else
                bkt(p + 1, s2);
        }
        
//        // Improves average time by: 0.3
//        if (s2 <= S && p != n)
//            bkt(p + 1, s2);
    }
}

int main() {
    citire();
    
    cout << "Perftest? ";
    bool perfTest = false;
    cin >> perfTest;
    
    if (perfTest) {
        cout << "Number of tries: ";
        double tries;
        cin >> tries;
        
        auto start = steady_clock::now();
        for (int i = 1; i <= tries; i++) bkt(1, 0);
        auto end = steady_clock::now() ;
        
        long long duration = duration_cast<milliseconds>(end-start).count();
        cout << "That took: " << duration << " ms\n";
        cout << "Average: " << tries / duration << " runs/ms\n";
    } else {
        doAfis = true;
        bkt(1, 0);
    }
    
    return 0;
}

//#include <iostream>
//#include <chrono>
//
//using namespace std;
//using namespace chrono;
//
//int s[10], bills[10], n, S;
//bool doAfis = false;
//
//void citire() {
//    cout << "Input: S, n then bill values" << endl;
//    cin >> S >> n;
//    for (int i = 1; i <= n; i++) {
//        cin >> bills[i];
//    }
//}
//
//bool valid(int p, long sum) {
//    if (p == n) {
//        return sum == S;
//    } else {
//        return sum <= S;
//    }
//}
//
//bool solutie(int p) {
//    return p == n;
//}
//
//void afis(int p) {
//    if (!doAfis) return;
//    for (int i = 1; i <= n; i++)
//        cout << s[i] << " x " << bills[i] << endl;
//    cout << endl;
//}
//
//void bkt(int p, long sum) {
//    for (int i = 0; i <= S / bills[p]; i++) {
//        s[p] = i;
//        long s2 = sum + i * bills[p];
//
//        if (valid(p, s2)) {
//            if (solutie(p))
//                afis(p);
//            else
//                bkt(p + 1, s2);
//        }
//    }
//}
//
//int main() {
//    citire();
//
//    cout << "Perftest? ";
//    bool perfTest = false;
//    cin >> perfTest;
//
//    if (perfTest) {
//        cout << "Number of tries: ";
//        double tries;
//        cin >> tries;
//
//        auto start = steady_clock::now();
//        for (int i = 1; i <= tries; i++) bkt(1, 0);
//        auto end = steady_clock::now() ;
//
//        long long duration = duration_cast<milliseconds>(end-start).count();
//        cout << "That took: " << duration << " ms\n";
//        cout << "Average: " << tries / duration << " runs/ms\n";
//    } else {
//        doAfis = true;
//        bkt(1, 0);
//    }
//
//    return 0;
//}
