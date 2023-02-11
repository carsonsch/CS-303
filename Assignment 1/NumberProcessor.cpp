#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <sstream>

#include "NumberProcessor.hpp"

int main()
{
    NumberProcessor processor = NumberProcessor();
    processor.start_tui();
    return 0;
}

NumberProcessor::NumberProcessor()
    : used_numbers_size(0), numbers_capacity(1024), numbers(new int[1024])
{
}

NumberProcessor::~NumberProcessor()
{
    // Delete the numbers array from the heap if it exists.
    if (numbers != nullptr)
    {
        delete[] numbers;
    }
}

// Displays the terminal user interface to the user
void NumberProcessor::start_tui()
{
    bool stop = false;

    // Try to import the data from the numbers file:
    try
    {
        import_file();
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
        stop = true;
    }
    catch (const std::domain_error& e)
    {
        std::cout << e.what() << std::endl;
        stop = true;
    }
    
    while (!stop)
    {
        print_nums();
        std::cout << "Pick an option: " << std::endl
                  << "1) Add a number" << std::endl
                  << "2) Remove a number" << std::endl
                  << "3) Replace a number" << std::endl
                  << "4) Find index of number" << std::endl
                  << "5) Quit" << std::endl;
        
        int choice = prompt_for_number("Choice", 1, 5);

        // Call appropriate function depending on user choice.
        switch (choice)
        {
            case 1:
                append_number();
                break;
            case 2:
                remove_number();
                break;
            case 3:
                replace_num();
                break;
            case 4:
                find_num();
                break;
            case 5:
                stop = true;
                break;
        }

        std::cout << std::endl;
    }
}

// Makes the user press the enter key before continuing.
// Useful for letting the user see the output of the previous command before continuing.
void NumberProcessor::wait_for_enter_key() const
{
    std::string dummy;
    std::cout << "Press enter to continue...";
    getline(std::cin, dummy); // Waits for enter key
}

// Extends the length of the `numbers` array if we are out of capacity.
void NumberProcessor::extend_array()
{
    if (used_numbers_size >= numbers_capacity)
    {
        // We create a new array double the size of the old one.
        int new_array_size = numbers_capacity * 2;
        int* new_array = new int[new_array_size];

        // Copy elements from old array to new one.
        for (int i = 0; i < used_numbers_size; i++)
        {
            new_array[i] = numbers[i];
        }

        // Assign new array as our `numbers` array
        delete[] numbers;
        numbers = new_array;
        numbers_capacity = new_array_size;
    }
}

// Displays the given prompt and requires that the user provides an int as response.
int NumberProcessor::prompt_for_number(std::string prompt) const
{
    std::string input_str;
    int result;
    while (true)
    {
        std::cout << prompt << ": ";

        getline(std::cin, input_str);
        try
        {
            // Try to parse input as integer.
            result = std::stoi(input_str);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Input wasn't a number. Try again." << std::endl;
            continue;
        }
        
        return result;
    }
}

// Prompt the user for a number, requiring that the response be within the given range.
int NumberProcessor::prompt_for_number(std::string prompt, int beginRange, int endRange) const
{
    prompt += " [" + std::to_string(beginRange) + "-" + std::to_string(endRange) + "]";
    
    int input;
    while (true)
    {
        input = prompt_for_number(prompt);

        // Validate the the value is within the range. If not, ask again.
        if (input < beginRange || input > endRange)
        {
            std::cout << "Number must be from " + std::to_string(beginRange)
                      << " to " + std::to_string(endRange) << std::endl;
        }
        else
        {
            return input;
        }
    }
}

// Asks the user for the number to append to the `numbers` array.
void NumberProcessor::append_number()
{
    int num = prompt_for_number("Enter the number to add to the array");
    append_number(num);
}

// Appends the given number to the `numbers` array.
void NumberProcessor::append_number(int num)
{
    // If we are out of allocated space in the array, make a new array and copy old elements to it
    if (used_numbers_size >= numbers_capacity)
    {
        extend_array();
    }

    // Add number to `numbers` array, keeping track of how
    // much of the `numbers` array we're actually using
    numbers[used_numbers_size] = num;
    used_numbers_size++;
}

// Asks the user for an index of a number to remove from the `numbers` array.
void NumberProcessor::remove_number()
{
    int idx = prompt_for_number("Pick an index to remove", 0, used_numbers_size - 1);

    // Shift all elements forwards one, starting at the index of the element to remove.
    for (int i = idx; i < used_numbers_size - 1; i++)
    {
        numbers[i] = numbers[i + 1];
    }

    used_numbers_size--;
}

// Ask the user for a number to search for. If it's found, outputs the index of the number.
void NumberProcessor::find_num() const
{
    int num = prompt_for_number("Enter a number to find");

    int idx = -1;
    // Search numbers array, trying to find number
    for (int i = 0; i < used_numbers_size; i++)
    {
        if (numbers[i] == num)
        {
            idx = i;
            break;
        }
    }

    // If idx is -1, we didn't find the number in the `numbers` array.
    if (idx == -1)
    {
        std::cout << "Your number wasn't found" << std::endl;
    }
    else
    {
        std::cout << "Your number is at index " << std::to_string(idx) << std::endl;
    }

    wait_for_enter_key();
}

// Asks the users which number they want to replace, and the number to replace it with.
// Outputs the old number that was replaced.
void NumberProcessor::replace_num()
{
    int idx = prompt_for_number("What is the index of the number you want to replace?", 0, used_numbers_size - 1);
    int num = prompt_for_number("What number do you want to replace it with?");

    int old_num = numbers[idx];
    numbers[idx] = num;

    std::cout << "Replaced " << std::to_string(old_num) << " with " << std::to_string(num) << "." << std::endl;
    wait_for_enter_key();
}

// Displays all numbers in the `numbers` array.
void NumberProcessor::print_nums() const
{
    std::cout << "Your numbers:" << std::endl;
    for (int i = 0; i < used_numbers_size; i++)
    {
        // Display 10 numbers per line
        if (i % 10 == 0)
        {
            if (i != 0)
            {
                std::cout << std::endl;
            }

            // Begin each line with an index so the user can find any particular numbers' index quickly.
            // Pad index counter to 3 chars.
            std::string idx_str = std::to_string(i);
            idx_str.insert(idx_str.begin(), 3 - idx_str.size(), '0');
            std::cout << "[" << idx_str << "] ";
        }
        
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl << "Total: " << std::to_string(used_numbers_size);
    std::cout << std::endl << std::endl;
}

// Reads all numbers from the `numbers.csv` file and adds them to the `numbers` array.
void NumberProcessor::import_file()
{
    std::string line;
    std::string int_str;
    std::ifstream numbers_file("numbers.csv");
    if (numbers_file.is_open())
    {
        // Read numbers one at a time, delimited by commas.
        while (getline(numbers_file, line))
        {
            std::stringstream int_stream(line);

            while (getline(int_stream, int_str, ','))
            {
                try
                {
                    int num = std::stoi(int_str);
                    append_number(num);
                }
                catch (const std::invalid_argument& e)
                {
                    throw std::domain_error("Unable to parse integers in numbers.csv. File is malformed.");
                }
            }
        }
        numbers_file.close();
    }
    else
    {
        // Throw if we can't find the 'numbers.csv' file.
        throw std::runtime_error("Unable to open the 'numbers.csv' file. Make sure your current working directory is correct.");
    }
}