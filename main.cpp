#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

void menu() {
    const int max = 50;
    Stack stack(max);
    Queue queue;
    int choice;

    while(true) {
        cout << "Press 1 to enter a new stock.\n";
        cout << "Press 2 to find the LIFO and FIFO price for a stock.\n";
        cout << "Press 0 to exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 0) {
            exit(EXIT_SUCCESS);
        } else if(choice == 1) {
            string stockName;
            int shares;
            double price;

            cout << "Enter stock name: ";
            cin >> stockName;
            cout << "Enter the number of shares: ";
            cin >> shares;
            cout << "Enter price per share: ";
            cin >> price;

            // Pushing stock entry onto the stack
            try {
                stack.push(stockName, shares, price);
            } catch(const overflow_error& e) {
                cout << e.what() << endl;
            }

            // Adding stock entry into the rear of the queue
            queue.enqueue(stockName, shares, price);

            cout << endl << "Stock successfully entered.";
            cout << endl << endl;

        } else if(choice == 2) {
            string stockName;
            int numShares;

            cout << "Enter stock name: ";
            cin >> stockName;
            cout << "Enter the number of shares to sell: ";
            cin >> numShares;

            // Calculate the average price of shares using LIFO
            try {
                double stackTotalPrice = stack.calculatePrice(stockName, numShares);
                cout << "LIFO: Total price for " << numShares << " shares of " << stockName << " is: " << stackTotalPrice << endl;
            } catch(const runtime_error& e) {
                cout << e.what() << endl;
            }

            // Calculate the average price of shares using FIFO
            try {
                double queueTotalPrice = queue.calculatePrice(stockName, numShares);
                cout << "FIFO: Total price for " << numShares << " shares of " << stockName << " is: " << queueTotalPrice << endl;
            } catch(const runtime_error& e) {
                cout << e.what() << endl;
            }
            cout << endl << endl;

        } else {
            cout << "Error: Invalid Choice." << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}