#include <iostream>
#include <string>

/*
    This program receive an integer input from terminal,
    then compute the factorial of the input (in recursive)
    then truncate the ending 0s and display only last 9 digits (with leading 0s removed)
*/
int display_truncated_factorial_value();
unsigned long long recursive(unsigned long long num);
void string_display_truncate_result(unsigned long long input);
void numeric_display_truncate_result(unsigned long long input);

int display_truncated_factorial_value () {
    unsigned long long total = 1;
    int input = 0;

    std::cin >> input;

    //get factorial of input number
    total = recursive(input);

    if (total == 0)
        return 1;

    std::cout << total << std::endl;

    string_display_truncate_result(total);
    numeric_display_truncate_result(total);
    

    return 0;
}

unsigned long long recursive(unsigned long long num) {
    if (num <= 1) {
        return 1;
    }
    
    return num * recursive(num - 1);
}

void string_display_truncate_result(unsigned long long input) {
    std::string result = std::to_string(input);

    //trim last few 0 if present
    while (result.find_last_of('0') == result.length() - 1)
        result.pop_back();

    //show only last 9 digits if more than that
    std::string output;
    if (result.length() > 9)
        output = result.substr(result.length() - 9, 9);
    else
        output = result;

    //trim first few 0 if present
    while (output.find_first_of('0') == 0)
        for (int index = 1; index < result.length() - 1; ++index) {
            output[index - 1] = output[index];
        }
    std::cout << output << std::endl;
}

void numeric_display_truncate_result(unsigned long long input) {
    //trim last few 0 if present
    while(input % 10 == 0){
        input /= 10;
    }

    int result = input % 1000000000;    //get only last 9 digits if more than that

    std::cout << result << std::endl;
}