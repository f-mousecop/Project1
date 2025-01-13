#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;
// Class to represent nodes where stock information will be stored
class Stocks {
    public:
        string stockName;
        int shares;
        double price;
        Stocks *next;

        // Constructor for nodes
        Stocks(const string& name, int sh, double pr);
};

// Class for implementation of a queue using a linked list
class Queue {
    private:
        Stocks *front;
        Stocks *rear;

    public:
        // Constructor for queue
        Queue();
        // Destructor for queue
        ~Queue();

        // Adding a new entry to the queue
        void enqueue(const string& stockName, int shares, double price);

        // Function to calculate the average price of a number of shares using FIFO
        double calculatePrice(const string& stockName, int numShares);
};

#endif // Queue.h