#include <iostream>
#include <string>
using namespace std;

bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int getDigit(int number)
{
    if (number < 10)
        return number;
    else
        return number / 10 + number % 10;
}

int sumOfDoubleEvenPlace(long long number)
{
    string digits = to_string(number);
    int sum = 0;

    for (int i = static_cast<int>(digits.size()) - 2; i >= 0; i -= 2)
    {
        int digit = digits[i] - '0';
        sum += getDigit(digit * 2);
    }

    return sum;
}

int sumOfOddPlace(long long number)
{
    string digits = to_string(number);
    int sum = 0;

    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; i -= 2)
    {
        sum += digits[i] - '0';
    }

    return sum;
}

int getSize(long long d)
{
    int size = 0;

    do
    {
        d /= 10;
        size++;
    } while (d != 0);

    return size;
}

long long getPrefix(long long number, int k)
{
    string digits = to_string(number);

    if (k <= 0 || k > static_cast<int>(digits.size()))
        return number;

    return stoll(digits.substr(0, k));
}

bool prefixMatched(long long number, int d)
{
    if (d == 37)
        return getPrefix(number, 2) == 37;
    else
        return getPrefix(number, 1) == d;
}

bool isValid(long long number)
{
    int total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    int size = getSize(number);

    if (size < 13 || size > 16)
        return false;

    if (!(prefixMatched(number, 4) || prefixMatched(number, 5) || prefixMatched(number, 37) || prefixMatched(number, 6)))
        return false;

    return total % 10 == 0;
}

int main()
{
    long long cardNumber;

    cout << "Enter a credit card number: ";
    cin >> cardNumber;

    if (isValid(cardNumber))
        cout << cardNumber << " is valid." << endl;
    else
        cout << cardNumber << " is invalid." << endl;

    return 0;
}

