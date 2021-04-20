#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int num, temp;
    set<int> st;
    bool ans;
    cout << "Enter the number to check whether it is a happy number\n>>";
    cin >> num;
    while (true)
    {
        temp = 0;
        while (num)
        {
            temp += ((num % 10) * (num % 10));
            num /= 10;
        }
        num = temp;
        if (num == 1)
        {
            ans = true;
            break;
        }
        if (st.find(num) != st.end())
        {
            ans = false;
            break;
        }
        st.insert(temp);
    }
    cout << (ans ? "True" : "False");
    return 0;
}