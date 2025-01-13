#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

// Struct to represent entries in the array
struct StockEntry {
    string stockName;
    int shares;
    double price;

    // Constructor to inititalize entry
    StockEntry(const string& name, int sh, double pr);
};

// Class to implement the stack using an array
class Stack {
    private:
        StockEntry *stack;
        int top;
        int max;

    public:
        // Constructor to initialize stack
        Stack(int cap);

        // Destructor
        ~Stack();

        // Function to push onto the stack
        void push(const string& stockName, int shares, double price);

        // Function to calculate the price for shares
        double calculatePrice(const string& stockName, int numShares);
};

#endif // STACK_H