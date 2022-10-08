#include <iostream>
#include <thread>
#include <map>
#include <vector>
#include <utility>
#include <cmath>
#include "testerF.h"
#include "gtest/gtest.h"
using namespace std;

const int values[] = {1, 2, 3, 4, 5};
const int NVALS = sizeof values / sizeof(int);
void function(char **);
int total = 0;

// Do not change anything besides the ptr variable
void function(char **ptr)
{
    char *ptr1;
    ptr1 = (ptr += sizeof(int))[-2];
    printf("%s\n", ptr1);
}

void fn(int **pp)
{
    printf("%p : %p : %d", pp, *pp, **pp);
}

class Foo
{
public:
    int aa;
    Wallet *bb;
    Foo(int a, Wallet *b = NULL)
    {
        aa = a;
        bb = b;
    }
};

struct person
{
    int age;
    float weight;
};

int main()
{

    // Question 1
    int x = 10;
    int y = 15;
    cout << ""
         << "(" << x << "," << y << ")" << endl;

    // Question 2 Insert in map
    typedef map<int, double> valmp;
    valmp m;
    for (int i = 0; i < NVALS; i++)
    {
        m.insert(make_pair(values[i], pow(values[i], .5)));
    }
    m.insert(make_pair(1, 2));

    // Question 3
    int i = 1, j = 1;
    if ((i != 3) && (j == 1))
    {
        cout << "inside if statement\n";
    }

    // Question 4 Fix the compiler errors and race conditions
    // Convert the testerFunction() into a google test
    // https://stackoverflow.com/questions/34510/what-is-a-race-condition
    // Think about how you can use a mutex to solve this
    int val = 0;
    for (int k = 0; k < 1000; k++)
    {
        if ((val = testerFunction()) != 5000)
        {
            cout << "Error at count = " << k << " Money in Wallet = " << val << endl;
            return 1;
        }
    }

    // Question 5
    int n = 1;
    int *p = &n;
    fn(&p);

    // Question 6 Initialise a person
    struct person *ptr = new person();
    ptr->age = 10;
    ptr->weight = 55.5;

    // Question 7 Initialise foo with 10 and a wallet
    class Wallet newWallet;
    class Foo fooObj(10, &newWallet);

    // Question 8 fix compiler warning
    char c;
    while ((c = getchar()) == EOF)
    {
        putchar(c);
    }

    return 0;
}