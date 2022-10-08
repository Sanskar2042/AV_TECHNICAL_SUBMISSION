#include <iostream>
#include <mutex>

std::mutex m;
class Wallet
{
    int mMoney;

public:
    Wallet() : mMoney(0) {}

    int getMoney()
    {
        return mMoney;
    }

    void addMoney(int money)
    {
        m.lock();
        for (int i = 0; i < money; ++i)
        {
            mMoney++;
        }
        m.unlock();
    }
};