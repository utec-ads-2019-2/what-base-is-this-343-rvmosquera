#include <string>
#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long int numType;

int minimumBase(string num) {
    int mayor = 0, aux = 0;
    int len = num.length();

    switch (len) {
        case 1: {
            if (num[0] >= 65 && num[0] <= 90)
                mayor = num[0] - 55;
            else {
                if (num[0] == '0')
                    mayor = 1;
                else
                    mayor = num[0] - 48;
            }
        }
            break;
        case 2: {
            if (num[0] >= 65 && num[0] <= 90)
                aux = num[0] - 55;
            else
                aux = num[0] - 48;

            mayor = aux;

            if (num[1] >= 65 && num[1] <= 90)
                aux = num[1] - 55;
            else
                aux = num[1] - 48;

            if (aux > mayor)
                mayor = aux;
        }
            break;
        default: {
            for (auto it = num.begin(); it != num.end(); ++it) {
                if (*it >= 65 && *it <= 90) {
                    aux = *it - 55;
                } else {
                    aux = stoi(string(1, *it));
                }

                if (aux > mayor)
                    mayor = aux;
            }
        }
    }

    return ++mayor;
}

numType convertToBase(string num, int i) {
    numType result = 0;
    auto len = num.length();

    for (int k = len - 1; k >= 0; --k)
        if (num[k] >= 65 && num[k] <= 90)
            result = result + (num[k] - 55) * pow(i, len - k - 1);
        else
            result = result + (num[k] - 48) * pow(i, len - k - 1);

    return result;
}

void getbaseforEqual(string num1, int minBase1, string num2, int minBase2) {
    numType first, second;
    bool found = false;
    int i, j;
    for (i = minBase1; i <= 36; ++i) {

        first = convertToBase(num1, i);

        for (j = minBase2; j <= 36; ++j) {

            second = convertToBase(num2, j);

            if (first == second) {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    if (found)
        printf("%s (base %d) = %s (base %d)\n", num1.c_str(), i, num2.c_str(), j);
    else
        printf("%s is not equal to %s in any base 2..36\n", num1.c_str(), num2.c_str());
}

int main() {
    string x, y;

    while (cin >> x >> y) {
        auto minBaseX = minimumBase(x);
        auto minBaseY = minimumBase(y);

        getbaseforEqual(x, minBaseX, y, minBaseY);
    }

}