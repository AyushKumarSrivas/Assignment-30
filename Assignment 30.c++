Exception Handling

1. Write a C++ program to demonstrate the use of try, catch block with the argument as an
integer and string using multiple catch blocks.
2. Write a C++ program to demonstrate try, throw and catch statements.
3. Write a C++ program to perform arithmetic operations on two numbers and throw an
exception if the dividend is zero or does not contain an operator.
4. Write a C++ program to accept an email address and throw an exception if it does not
contain @ symbol.
5. Write a C++ program to accept a mobile number and throw an exception if it does not
contain 10 digits.
6. Write a C++ program to accept area pin code and throw an exception if it does not
contain 6 digits.
7. Write a C++ program to accept a username if the username has less than 6 characters
or does contain any digit or special symbol.
8. Write a C++ program to accept a password and throw an exception if the password has
less than 6 characters or does not contain a digit or does not contain any special
character or does not contain any capital letter.
9. Write a C++ program to accept Gmail id only and throw an exception if the id does not
contain @ and gmail.com.
10. Write a C++ program to accept Nickname and throw an exception if it has greater than 8
characters or does contain a digit or special symbol or space.

Solution:-

1. #include <iostream>
#include <string>
using namespace std;

int main() {
    try {
        throw 10; // Throwing an integer exception
    } catch (int e) {
        cout << "Caught an integer exception: " << e << endl;
    }

    try {
        throw string("String exception"); // Throwing a string exception
    } catch (string &e) {
        cout << "Caught a string exception: " << e << endl;
    }

    return 0;
}

2. #include <iostream>
using namespace std;

void testFunction(int x) {
    if (x == 0) {
        throw runtime_error("Division by zero error");
    }
    cout << "Value is " << x << endl;
}

int main() {
    try {
        testFunction(0); // This will throw an exception
    } catch (const runtime_error &e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    return 0;
}

3. #include <iostream>
#include <stdexcept>
using namespace std;

void performOperation(int dividend, int divisor, char op) {
    if (divisor == 0) {
        throw runtime_error("Division by zero error");
    }
    if (op != '+' && op != '-' && op != '*' && op != '/') {
        throw runtime_error("Invalid operator");
    }
    
    switch (op) {
        case '+':
            cout << "Result: " << (dividend + divisor) << endl;
            break;
        case '-':
            cout << "Result: " << (dividend - divisor) << endl;
            break;
        case '*':
            cout << "Result: " << (dividend * divisor) << endl;
            break;
        case '/':
            cout << "Result: " << (dividend / divisor) << endl;
            break;
    }
}

int main() {
    int dividend = 10;
    int divisor = 0;
    char op = '/';

    try {
        performOperation(dividend, divisor, op);
    } catch (const runtime_error &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

4. #include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void validateEmail(const string &email) {
    if (email.find('@') == string::npos) {
        throw runtime_error("Invalid email address. Missing '@' symbol.");
    }
}

int main() {
    string email;
    cout << "Enter email address: ";
    cin >> email;

    try {
        validateEmail(email);
        cout << "Email address is valid." << endl;
    } catch (const runtime_error &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

5. #include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void validateMobileNumber(const string &number) {
    if (number.length() != 10 || !all_of(number.begin(), number.end(), ::isdigit)) {
        throw runtime_error("Invalid mobile number. It should contain exactly 10 digits.");
    }
}

int main() {
    string mobileNumber;
    cout << "Enter mobile number: ";
    cin >> mobileNumber;

    try {
        validateMobileNumber(mobileNumber);
        cout << "Mobile number is valid." << endl;
    } catch (const runtime_error &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

6. #include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void validatePinCode(const string &pin) {
    if (pin.length() != 6 || !all_of(pin.begin(), pin.end(), ::isdigit)) {
        throw runtime_error("Invalid pin code. It should contain exactly 6 digits.");
    }
}

int main() {
    string pinCode;
    cout << "Enter pin code: ";
    cin >> pinCode;

    try {
        validatePinCode(pinCode);
        cout << "Pin code is valid." << endl;
    } catch (const runtime_error &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

7. #include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void validateUsername(const string &username) {
    if (username.length() < 6) {
        throw runtime_error("Username must be at least 6 characters long.");
    }
    if (any_of(username.begin(), username.end(), ::isdigit) || 
        any_of(username.begin(), username.end(), ::ispunct)) {
        throw runtime_error("Username should not contain digits or special symbols.");
    }
}

int main() {
    string username;
    cout << "Enter username: ";
    cin >> username;

    try {
        validateUsername(username);
        cout << "Username is valid." << endl;
    } catch (const runtime_error &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

8. #include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void validatePassword(const string &password) {
    if (password.length() < 6) {
        throw runtime_error("Password must be at least 6 characters long.");
    }
    if (!any_of(password.begin(), password.end(), ::isdigit)) {
        throw runtime_error("Password must contain at least one digit.");
    }
    if (!any_of(password.begin(), password.end(), ::ispunct)) {
        throw runtime_error("Password must contain at least one special character.");
    }
    if (!any_of(password.begin(), password.end(), ::isupper)) {
        throw runtime_error("Password must contain at least one uppercase letter.");
    }
}

int main() {
    string password;
    cout << "Enter password: ";
    cin >> password;

    try {
        validatePassword(password);
        cout << "Password is valid." << endl;
    } catch (const runtime_error &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

9. #include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void validateGmailID(const string &email) {
    if (email.find('@') == string::npos || email.find("gmail.com") == string::npos) {
        throw runtime_error("Invalid Gmail ID. It should contain '@' and 'gmail.com'.");
    }
}

int main() {
    string email;
    cout << "Enter Gmail ID: ";
    cin >> email;

    try {
        validateGmailID(email);
        cout << "Gmail ID is valid." << endl;
    } catch (const runtime_error &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

10. #include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void validateNickname(const string &nickname) {
    if (nickname.length() > 8) {
        throw runtime_error("Nickname should not be longer than 8 characters.");
    }
    if (any_of(nickname.begin(), nickname.end(), ::isdigit) || 
        any_of(nickname.begin(), nickname.end(), ::ispunct) || 
        any_of(nickname.begin(), nickname.end(), ::isspace)) {
        throw runtime_error("Nickname should not contain digits, special symbols, or spaces.");
    }
}

int main() {
    string nickname;
    cout << "Enter nickname: ";
    cin >> nickname;

    try {
        validateNickname(nickname);
        cout << "Nickname is valid." << endl;
    } catch (const runtime_error &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
