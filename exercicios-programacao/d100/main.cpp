#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> d100(1, 100);
    cout << "D100: " << d100(gen) << std::endl;

    return 0;
}