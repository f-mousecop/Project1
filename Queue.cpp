#include "Queue.h"
#include <stdexcept>

// Constructor to initialize a node
Stocks::Stocks(const string& name, int sh, double pr)
    : stockName(name), shares(sh), price(pr), next(nullptr) {}

Queue::Queue() : front(nullptr), rear(nullptr) {}
Queue::~Queue() {
    while(front != nullptr) {
        Stocks *temp = front;
        front = front->next;
        delete temp;
    }
}

void Queue::enqueue(const string& stockName, int shares, double price) {
    Stocks *newStock = new Stocks(stockName, shares, price);

    // If the queue is empty set both front and rear to new stock entry
    if(rear == nullptr) {
        front = newStock;
        rear = newStock;
    } else {
        // Add to the end and update rear
        rear->next = newStock;
        rear = newStock;
    }
}

double Queue::calculatePrice(const string& stockName, int numShares) {
    int count = 0;
    double totalCost = 0.0;

    Stocks *current = front;

    while(current != nullptr) {
        if(current->stockName == stockName) {
            if(count + current->shares >= numShares) {
                int remaining = numShares - count;
                totalCost += remaining * current->price;
                count += remaining;
                break;
            } else {
                totalCost += current->shares * current->price;
                count += current->shares;
            }
        }
        current = current->next;
    }

    if(count < numShares) {
        throw runtime_error("FIFO: Stock not found or not enough shares to perform calculation");
    }

    return totalCost / numShares;
}