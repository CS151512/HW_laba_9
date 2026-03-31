#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../include/stack_module.h"
#include "../include/deque_module.h"
#include "../include/queue_module.h"
#include <thread>
#include <chrono>

struct Theme {
    std::string name;
    std::string primary;
    std::string secondary;
    std::string text;
    std::string error;
    std::string success;
};

const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";

const std::vector<Theme> THEMES = {
    {"Claude Code (Coral)", "\033[38;5;210m", "\033[38;5;245m", "\033[38;5;255m", "\033[38;5;196m", "\033[38;5;114m"},
    {"Rustacean", "\033[38;5;208m", "\033[38;5;240m", "\033[38;5;253m", "\033[38;5;196m", "\033[38;5;76m"},
    {"Dracula", "\033[38;5;141m", "\033[38;5;61m", "\033[38;5;253m", "\033[38;5;203m", "\033[38;5;84m"},
    {"Nord", "\033[38;5;109m", "\033[38;5;146m", "\033[38;5;253m", "\033[38;5;131m", "\033[38;5;108m"},
    {"Matrix", "\033[38;5;46m", "\033[38;5;22m", "\033[38;5;40m", "\033[38;5;196m", "\033[38;5;46m"}
};

Theme currentTheme = THEMES[0];

void clearScreen() {
    std::cout << "\033[2J\033[1;1H" << std::flush;
}

void selectThemeOnStartup() {
    clearScreen();
    std::cout << "\n  [ Initializing System... ]\n\n";
    std::cout << "  Please select a color theme:\n";
    for (size_t i = 0; i < THEMES.size(); ++i) {
        std::cout << "  " << THEMES[i].primary << "[" << i << "] " << THEMES[i].name << RESET << "\n";
    }
    std::cout << "\n  > ";
    std::string input;
    std::getline(std::cin, input);
    try {
        int choice = std::stoi(input);
        if (choice >= 0 && choice < THEMES.size()) {
            currentTheme = THEMES[choice];
        }
    } catch (...) {}
}

void printClaudeStyleHeader() {
    std::string accent = currentTheme.primary;
    std::string text = currentTheme.text + BOLD;
    std::string dim = currentTheme.secondary;

    std::cout << accent << "╭─ Data Structures CLI v1.0 ──────────────────────────────────────────\n";
    std::cout << accent << "│                                          " << accent << "│ " << text << "Mini-description\n";
    std::cout << accent << "│" << text << "                                          " << accent << "│ " << dim << "Interactive REPL for\n";
    std::cout << accent << "│" << text << "                                          " << accent << "│ " << dim << "Lab 9: Stacks, Deques,\n";
    std::cout << accent << "│" << text << "                                          " << accent << "│ " << dim << "and Queues.\n";
    std::cout << accent << "│" << text << "                ▐▛███▜▌                   " << accent << "│\n";
    std::cout << accent << "│" << text << "               ▝▜█████▛▘                  " << accent << "│ " << text << "Instructions\n";
    std::cout << accent << "│" << text << "                 ▘▘ ▝▝                    " << accent << "│ " << dim << "Type 'help' to see all\n";
    std::cout << accent << "│" << text << "                                          " << accent << "│ " << dim << "commands. Type 'exit'\n";
    std::cout << accent << "│" << text << "                                          " << accent << "│ " << dim << "to quit the app.\n";
    std::cout << accent << "│" << text << "  C++17 | Laba9 NARFU | Memory Safe       " << accent << "│\n";
    std::cout << accent << "│" << dim  << "  /github/golkity/lab9                    " << accent << "│\n";
    std::cout << accent << "╰─────────────────────────────────────────────────────────────────────\n" << RESET;
}

std::string getHelpText() {
    std::ostringstream out;
    out << currentTheme.text << BOLD << "COMMANDS:\n" << RESET
        << currentTheme.secondary << "  Стек (Stack):\n" << RESET
        << currentTheme.text << "    push <num>   " << currentTheme.secondary << "- Добавить элемент в стек\n" << RESET
        << currentTheme.text << "    pop          " << currentTheme.secondary << "- Извлечь элемент из стека\n" << RESET
        << currentTheme.text << "    reverse      " << currentTheme.secondary << "- Перевернуть стек\n" << RESET
        << currentTheme.text << "    print        " << currentTheme.secondary << "- Вывести стек\n" << RESET
        << currentTheme.secondary << "\n  Дек (Deque):\n" << RESET
        << currentTheme.text << "    push_f <num> " << currentTheme.secondary << "- Добавить в начало\n" << RESET
        << currentTheme.text << "    push_b <num> " << currentTheme.secondary << "- Добавить в конец\n" << RESET
        << currentTheme.text << "    pop_f        " << currentTheme.secondary << "- Извлечь из начала\n" << RESET
        << currentTheme.text << "    pop_b        " << currentTheme.secondary << "- Извлечь из конца\n" << RESET
        << currentTheme.secondary << "\n  Очередь (Queue):\n" << RESET
        << currentTheme.text << "    q_push <num> " << currentTheme.secondary << "- Добавить элемент в конец очереди\n" << RESET
        << currentTheme.text << "    q_pop        " << currentTheme.secondary << "- Извлечь элемент из начала очереди\n" << RESET
        << currentTheme.secondary << "\n  Система:\n" << RESET
        << currentTheme.text << "    theme <0-4>  " << currentTheme.secondary << "- Сменить тему\n" << RESET
        << currentTheme.text << "    clear        " << currentTheme.secondary << "- Очистить экран вывода\n" << RESET
        << currentTheme.text << "    exit         " << currentTheme.secondary << "- Выйти\n";
    return out.str();
}

void showLoadingScreen() {
    clearScreen();
    std::cout << "\n  " << currentTheme.primary << BOLD << "FINNIK-OS Boot Sequence Initiated...\n\n" << RESET;

    std::vector<std::string> steps = {
        "Allocating memory pools...",
        "Linking StackRepository...",
        "Linking DequeRepository...",
        "Verifying memory safety...",
        "Waking up Ferris (Rustacean mode)..."
    };

    for (const auto& step : steps) {
        std::cout << currentTheme.secondary << "  [ * ] " << currentTheme.text << step << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        std::cout << currentTheme.success << " OK\n" << RESET;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "\n";

    const int barWidth = 40;
    for (int i = 0; i <= barWidth; ++i) {
        std::cout << "\r  " << currentTheme.secondary << "Mounting core systems: "
                  << currentTheme.primary << "[";

        for (int j = 0; j < barWidth; ++j) {
            if (j < i) std::cout << "█";
            else std::cout << "░";
        }

        int percent = (i * 100) / barWidth;
        std::cout << "] " << currentTheme.text << percent << "%" << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(35));
    }

    std::cout << "\n\n  " << currentTheme.success << "System Ready. Press Enter to launch CLI..." << RESET;
    std::string dummy;
    std::getline(std::cin, dummy);
}

int main() {
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    StackRepo stack;
    DequeRepo deque;
    QueueRepository queue;

    selectThemeOnStartup();
    showLoadingScreen();

    std::string input;
    std::string lastOutput = "";

    while (true) {
        clearScreen();
        printClaudeStyleHeader();

        if (!lastOutput.empty()) {
            std::cout << "\n" << lastOutput << "\n";
        } else {
            std::cout << "\n" << currentTheme.secondary << " ↑ Use 'clear' to clean this area · 'theme <id>' to switch colors\n" << RESET;
        }

        std::cout << "\n" << currentTheme.secondary << "───────────────────────────────────────────────────────────────────────\n" << RESET;
        std::cout << currentTheme.secondary << "  ? type 'help' for commands                       " << currentTheme.success << "● Memory: Safe\n" << RESET;

        std::cout << currentTheme.text << BOLD << "❯ " << RESET;

        std::getline(std::cin, input);
        if (input.empty()) continue;

        std::istringstream iss(input);
        std::string command;
        iss >> command;
        int val;

        std::ostringstream out;

        if (command == "exit" || command == "quit") {
            clearScreen();
            std::cout << currentTheme.secondary << "Session ended. Bye!\n" << RESET;
            break;
        }
        else if (command == "help") {
            out << getHelpText();
        }
        else if (command == "clear") {
            lastOutput = "";
            continue;
        }
        else if (command == "theme") {
            int themeId;
            if (iss >> themeId && themeId >= 0 && themeId < THEMES.size()) {
                currentTheme = THEMES[themeId];
                out << currentTheme.success << "Тема обновлена на " << currentTheme.name << RESET;
            } else {
                out << currentTheme.error << "Укажите номер от 0 до " << THEMES.size() - 1 << RESET;
            }
        }
        else if (command == "push") {
            if (iss >> val) {
                stack.push(val);
                out << currentTheme.success << "Стек: добавлен элемент " << val << RESET;
            } else out << currentTheme.error << "Error: требуется аргумент (например, push 42)" << RESET;
        }
        else if (command == "pop") {
            if (stack.pop(val)) out << currentTheme.success << "Стек: извлечено " << val << RESET;
            else out << currentTheme.error << "Error: Стек пуст" << RESET;
        }
        else if (command == "reverse") {
            StackService::reverse(stack);
            out << currentTheme.success << "Стек перевернут" << RESET;
        }
        else if (command == "print") {
            std::vector<int> elements = StackService::getElementsViaDubleReverse(stack);
            if (elements.empty()) {
                out << currentTheme.secondary << "[ Стек пуст ]" << RESET;
            } else {
                out << currentTheme.secondary << "Стек (сверху вниз): [" << RESET;
                for (size_t i = 0; i < elements.size(); ++i) {
                    out << currentTheme.text << elements[i];
                    if (i < elements.size() - 1) out << currentTheme.secondary << ", " << RESET;
                }
                out << currentTheme.secondary << "]" << RESET;
            }
        }
        else if (command == "push_f") {
            if (iss >> val) {
                deque.push_front(val);
                out << currentTheme.success << "Дек: добавлено в начало " << val << RESET;
            } else out << currentTheme.error << "Error: требуется аргумент" << RESET;
        }
        else if (command == "push_b") {
            if (iss >> val) {
                deque.push_back(val);
                out << currentTheme.success << "Дек: добавлено в конец " << val << RESET;
            } else out << currentTheme.error << "Error: требуется аргумент" << RESET;
        }
        else if (command == "pop_f") {
            if (deque.pop_front(val)) out << currentTheme.success << "Дек: извлечено из начала " << val << RESET;
            else out << currentTheme.error << "Error: Дек пуст" << RESET;
        }
        else if (command == "pop_b") {
            if (deque.pop_back(val)) out << currentTheme.success << "Дек: извлечено из конца " << val << RESET;
            else out << currentTheme.error << "Error: Дек пуст" << RESET;
        }
        else if (command == "q_push") {
            if (iss >> val) {
                queue.push(val);
                out << currentTheme.success << "Очередь: добавлено " << val << RESET;
            } else out << currentTheme.error << "Error: требуется аргумент" << RESET;
        }
        else if (command == "q_pop") {
            if (queue.pop(val)) out << currentTheme.success << "Очередь: извлечено " << val << RESET;
            else out << currentTheme.error << "Error: Очередь пуста" << RESET;
        }
        else {
            out << currentTheme.error << "Error: Команда '" << command << "' не найдена. Введи 'help'." << RESET;
        }

        lastOutput = out.str();
    }
    return 0;
}