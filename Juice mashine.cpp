// Juice mashine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class cashRegister
{
public:
    int getCurrentBalance() const;
    //Function to show the current amount in the cash
    //register.
    //Postcondition: The value of cashOnHand is returned.
    void acceptAmount(int amountIn);
    //Function to receive the amount deposited by
    //the customer and update the amount in the register.
    //Postcondition: cashOnHand = cashOnHand + amountIn;
    cashRegister(int cashIn = 500);
    //Constructor
    //Sets the cash in the register to a specific amount.
    //Postcondition: cashOnHand = cashIn;
    // If no value is specified when the
    // object is declared, the default value
    // assigned to cashOnHand is 500.
private:
    int cashOnHand; //variable to store the cash
    //in the register
};

int cashRegister::getCurrentBalance() const {
    return cashOnHand;
}
void cashRegister::acceptAmount(int amountIn) {
    cashOnHand = cashOnHand + amountIn;
}

cashRegister::cashRegister(int cashIn) {
    if (cashIn >= 0)
        cashOnHand = cashIn;
    else
        cashOnHand = 500;
}

class DispenserType {
public:
    int getNoOfItems() const {
        return numberOfItems;
    };
    int getCost() const {
        return cost;
    };
    void makeSale() {
        numberOfItems--;
    };
    DispenserType(int setOnOfitem=50, int setCost=50);
    //constructor
    //sets of the cost and numbers of item in the dispenser 
    // to the values specified by the user.
    //postcondition:: numbersOfItems=setofitems;
    //cost=setcost
    
private:
    int numberOfItems;
    int cost;
};

DispenserType::DispenserType(int setNoOfItems, int setCost)
{
    if (setNoOfItems >= 0)
        numberOfItems = setNoOfItems;
    else
        numberOfItems = 50;
    if (setCost >= 0)
        cost = setCost;
    else
        cost = 50;
}

void showSelection()
{
    std::cout << "*** Welcome to Shelly's Juice Shop ***" << endl;
    std::cout << "To select an item, enter " << endl;
    std::cout << "1 for orange juice (50 cents)" << endl;
    std::cout << "2 for apple juice (65 cents)" << endl;
    std::cout << "3 for mango juice (80 cents)" << endl;
    std::cout << "4 for strawberry banana juice (85 cents)" << endl;
    std::cout << "9 to exit" << endl;
}//end showSelection

void sellProduct(DispenserType& product,
    cashRegister& pCounter){

    int amount; //variable to hold the amount entered
    int amount2; //variable to hold the extra amount needed
    if (product.getNoOfItems() > 0) //if the dispenser is not
    //empty
    {
        std::cout << "Please deposit " << product.getCost() << " cents" << endl;
        std::cin >> amount;
        if (amount < product.getCost())
        {
            std::cout << "Please deposit another "
                << product.getCost() - amount
                << " cents" << endl;
            std::cin >> amount2;
            amount = amount + amount2;
        }
        if (amount >= product.getCost())
        {
            pCounter.acceptAmount(amount);
            product.makeSale();
            std::cout << "Collect your item at the bottom and "
                << "enjoy." << endl;
        }
        else
            std::cout << "The amount is not enough. "
            << "Collect what you deposited." << endl;
        std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
            << endl << endl;
    }
    else
        std::cout << "Sorry, this item is sold out." << endl;
}//end sellProduct
int main()
{

    cashRegister counter;
    DispenserType orange(100, 50);
    DispenserType apple(100, 65);
    DispenserType mango(75, 80);
    DispenserType strawberryBanana(100, 85);
    int choice; //variable to hold the selection
    showSelection();
    std::cin >> choice;
    while (choice != 9) {
        switch (choice)
        {
        case 1:
            sellProduct(orange, counter);
            break;
        case 2:
            sellProduct(apple, counter);
            break;
        case 3:
            sellProduct(mango, counter);
            break;
        case 4:
            sellProduct(strawberryBanana, counter);
            break;
        default:
            std::cout << "Invalid selection." << endl;

        }
        showSelection();
        cin >> choice;
    }
    return 0;


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
