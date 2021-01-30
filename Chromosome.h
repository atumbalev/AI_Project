#pragma once

#include <map>
#include <deque>

#include "Board.h"

using namespace std;

class Solution
{
public:
        multimap<int, int> map;
        deque<int> list;

        Solution(int);
        void grow(); 
        bool growNoCycle();
        void growBestNoCycle(); 
        void mutate();
        int getStatus() const;
        bool operator<(const Solution& rhs) const;
        double getFitness() const;
        bool solved();
        void print();
        void crossover(Solution&);

        void truncate();
};