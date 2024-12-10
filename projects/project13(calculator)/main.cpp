#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cctype>
#include <stdexcept>

int precedence(char op) {

    if (op == '+' || op == '-') return 1;

    if (op == '*' || op == '/') return 2;

    if (op == '^') return 3;

    return 0;

}

double applyOperation(double a, double b, char op) {

    switch (op) {

        case '+': return a + b;

        case '-': return a - b;

        case '*': return a * b;

        case '/':

            if (b == 0) throw std::runtime_error("деление на ноль");

            return a / b;

        case '^': return std::pow(a, b);

        default: throw std::invalid_argument("Неизвестная операция");

    }

}

void parseExpression(const std::string& expression, std::vector<double>& numbers, std::vector<char>& operators) {

    std::istringstream iss(expression);

    double number;

    char op;

    if (!(iss >> number)) {

        throw std::invalid_argument("Некорректный ввод: ожидалось число");

    }

    numbers.push_back(number);


    while (iss >> op) {

        if (std::string("+-*/^").find(op) == std::string::npos) {

            throw std::invalid_argument("Неизвестный оператор: " + std::string(1, op));

        }

        operators.push_back(op);


        if (!(iss >> number)) {

            throw std::invalid_argument("Некорректный ввод: ожидалось число после оператора");

        }

        numbers.push_back(number);

    }

}

double evaluate(const std::vector<double>& numbers, const std::vector<char>& operators) {

    std::vector<double> nums = numbers;

    std::vector<char> ops = operators;

    for (size_t i = 0; i < ops.size(); ++i) {

        if (ops[i] == '^') {

            nums[i] = applyOperation(nums[i], nums[i + 1], ops[i]);

            nums.erase(nums.begin() + i + 1);

            ops.erase(ops.begin() + i);

            --i;

        }

    }

    for (size_t i = 0; i < ops.size(); ++i) {

        if (ops[i] == '*' || ops[i] == '/') {

            nums[i] = applyOperation(nums[i], nums[i + 1], ops[i]);

            nums.erase(nums.begin() + i + 1);

            ops.erase(ops.begin() + i);

            --i;
        }
    }

    for (size_t i = 0; i < ops.size(); ++i) {

        if (ops[i] == '+' || ops[i] == '-') {

            nums[i] = applyOperation(nums[i], nums[i + 1], ops[i]);

            nums.erase(nums.begin() + i + 1);

            ops.erase(ops.begin() + i);

            --i;

        }

    }
    return nums[0];
}

int main() {

    while (true) {

        try {

            std::cout << "Введите выражение: ";

            std::string expression;

            std::getline(std::cin, expression);

            std::vector<double> numbers;

            std::vector<char> operators;

            parseExpression(expression, numbers, operators);

            double result = evaluate(numbers, operators);

            std::cout << "Результат: " << result << std::endl;


        } catch (const std::exception& e) {

            std::cout << "Ошибка: " << e.what() << std::endl;

        }
    }

    return 0;

}