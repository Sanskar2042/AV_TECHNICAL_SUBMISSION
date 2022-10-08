#include "Wallet.h"
#include <vector>
#include <thread>

int testerFunction()
{
    Wallet walletObject;
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
    {
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
    }
    for (int i = 0; i < threads.size(); i++)
    {
        threads.at(i).join();
    }
    return walletObject.getMoney();
}
