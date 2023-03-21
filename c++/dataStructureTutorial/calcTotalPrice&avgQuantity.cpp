#include <iostream>

struct Item {
    double unitPrice;
    int quantity;
    Item() { unitPrice = 0.0, quantity = 0; }
    Item(double up, int q) :unitPrice(up), quantity(q) {}
    double getPrice() { return unitPrice * quantity; }
    void operator = (Item temp) { this->unitPrice = temp.unitPrice; this->quantity = temp.quantity; }
};


int main() {
    using namespace std;
    Item list[100];
    int num = 0,quantity=0;
    double unitPrice = 0.0;

    while (unitPrice != 0 || num < 100) {
        bool loop = false;

        do{
            cout << "Enter unit price (Enter 0 to terminate) :";
            cin >> unitPrice;
            
            if (unitPrice > 1000 || unitPrice < 0) {
                cout << "The unit price should between 0 and 1000" << endl;
                loop = true;
            }
            else {
                loop = false;
            }
        } while (loop);

        if (unitPrice == 0)
            break;

        do {
            cout << "Enter quantity :";
            cin >> quantity;

            if (quantity > 1000 || quantity < 0) {
                cout << "The quantity should between 0 and 1000" << endl;
                loop = true;
            }
            else {
                loop = false;
            }
        } while (loop);

        Item temp(unitPrice, quantity);
        list[num++] = temp;
    }

    double total = 0,average=0;
    int totalQty = 0;

    for (int i = 0; i < num; ++i) {
        total += list[i].getPrice();
        totalQty += list[i].quantity;
    }
    if (num == 0)
        average = 0;
    else
        average = static_cast<double>(totalQty) / num;

    printf("Total: %.2f\tAverage quantity: %.1f", total, average);

    return 0;
}