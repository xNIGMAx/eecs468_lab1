#include <iostream>
#include <regex>
#include <iomanip>
#include <string>

using namespace std;


double extractNumeric(const std::string& str) {
    // regex pattern that match a possible double value
    regex pattern("^[+-]?(\\d+(\\.\\d*)?|\\.\\d+)$");
    if (regex_match(str, pattern)){
        bool isNegative = false;
        double answer = 0.0;
        int i = 0;

        // handle the sign
        if (str[i] == '-'){
            isNegative = true;
            i++; // skip
        }
        else if (str[i] == '+'){
            i++;
        }

        //handle the integer before the decimal if exist
        while (i < str.length() && isdigit(str[i])){
            answer = answer * 10 + (str[i] - '0');
            i++;
        }

        // handle after decimal
        if (i < str.length() && str[i] == '.'){
            i++;
            double decimal = 0.1; // first decimal place

            while (i < str.length() && isdigit(str[i])){
                answer += (str[i] - '0') * decimal;
                decimal /= 10; // move next
                i++;
            }

        }

        // get the sign back
        if (isNegative){
            answer = -answer;
        }

        return answer;
    }
    else{
        return -999999.99;
    }
}

int main() {
    string str;
    
    while (true){
        cout << "Enter a string to check (or type 'END' to quit): ";
        cin >> str;

        if (str == "END") {
            break; 
        }

        double value = extractNumeric(str);

        if (value == -999999.99){
            cout << "Input is Invalid" << endl;
        }
        else {
            cout << "Input is Valid: " << fixed << setprecision(4) << value << endl;
        }
    }

    return 0;
}
