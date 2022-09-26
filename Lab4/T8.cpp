#include <vector>
#include <string>
#include <algorithm>
#include "Searches.h"

int main()
{
    std::vector<std::string> stringTest {"greetings", "yall", "earthlings", "take", "me", "to", "your", "leader"};
    std::sort(stringTest.begin(), stringTest.end());
    std::string tester = "gr";
    int a = linearSearch(stringTest, tester);
    //ASSERT_EQ(a,-1);
    if (a != -1)
    {
        std::cout << "expected/correct value for a is -1, actual value when testing " << a << ".\n";
        return 1;
    }

    return 0;
}