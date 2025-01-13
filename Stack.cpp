#include "Stack.h"
#include <stdexcept>

StockEntry::StockEntry(const string& name = "", int sh = 0, double pr = 0.0)
    : stockName(name), shares(sh), price(pr) {}

Stack::Stack(int cap)
    : top(-1), max(cap) {
        stack = new StockEntry[max];
    }

Stack::~Stack() {
    delete[] stack;
}

// Push an entry onto the stack
void Stack::push(const string& stockName, int shares, double price) {
    if(top >= max - 1) {
        throw std::overflow_error("Stack is full.");
    }
    stack[++top] = StockEntry(stockName, shares, price);
}

// Function to calculate the price of shares
double Stack::calculatePrice(const string& stockName, int numShares) {
    int count = 0;
    double totalCost = 0.0;

    // Traverse the array
    for(int i = top; i >= 0; --i) {
        if(stack[i].stockName == stockName) {
            if(count + stack[i].shares >= numShares) {
                int remaining = numShares - count;
                totalCost += remaining * stack[i].price;
                count += remaining;
                break;
            } else {
                totalCost += stack[i].shares * stack[i].price;
                count += stack[i].shares;
            }
        }
    }

    if(count < numShares) {
        throw std::runtime_error("\nLIFO: Stock not found or not enough shares to perform calculation");
    }

    // Return the average price for the shares
    return totalCost / numShares;
}