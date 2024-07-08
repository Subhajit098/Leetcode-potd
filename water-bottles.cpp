#include <bits/stdc++.h>
using namespace std;

// Method 1 , TC : O(log(numBottles))
int numWaterBottles(int numBottles, int numExchange)
{
    int consumed = numBottles, emptyBottles = numBottles;
    while (emptyBottles >= numExchange)
    {
        int rem_empty_bottles = emptyBottles % numExchange;
        int filled_bottles = emptyBottles / numExchange;
        consumed += filled_bottles;
        emptyBottles = rem_empty_bottles + filled_bottles;
    }
    return consumed;
}

// Method 2 , TC : O(1)
int numWaterBottles(int numBottles, int numExchange)
{
    return numBottles + (numBottles - 1) / (numExchange - 1);
}