#include <iostream>
#include <string>

#include "SinglyLinkedList.hpp"
#include "ProfessionalEmployee.hpp"
#include "NonProfessionalEmployee.hpp"

void test_list()
{
    auto list = SinglyLinkedList<int>();
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.insert(1, 5);
    list.insert(9999, 999);
    list.push_back(1010);
    list.push_front(1337);
    list.pop_front();
    list.pop_back();
    list.print();

    std::cout << "Empty: " << list.empty() << std::endl;
    std::cout << "Size: " << list.item_count() << std::endl;
    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " <<  list.back() << std::endl;
    std::cout << "Index of '5': " << list.find(5) << std::endl;

    for (int i = 0; i < 100; i++)
        list.pop_front();

    std::cout << std::endl;
    std::cout << "After popping all" << std::endl;
    std::cout << "Empty: " << list.empty() << std::endl;
    std::cout << "Size: " << list.item_count() << std::endl;
}

void test_professional_employee()
{
    ProfessionalEmployee emp = ProfessionalEmployee("John", "Doe", "123 Main St", 4025.50);
    std::cout << std::endl << "Testing ProfessionalEmployee:" << std::endl;
    std::cout << "Name: " << emp.get_first_name() << " " << emp.get_last_name() << std::endl;
    std::cout << "Address: " << emp.get_address() << std::endl;
    std::cout << "Weekly pay: $" << emp.calc_weekly_pay() << std::endl;
    std::cout << "Vacation hours earned this week: " << emp.calc_weekly_vacation_hours_earned() << std::endl;
    std::cout << "Weekly healthcare contributions: $" << emp.calc_weekly_healthcare_contributions() << std::endl;
    std::cout << "Monthly salary: $" << emp.get_monthly_salary() << std::endl;
}

void test_nonprofessional_employee()
{
    NonProfessionalEmployee emp = NonProfessionalEmployee("Bob", "Johnson", "123 Main St", 32.5, 25.2);
    std::cout << std::endl << "Testing NonProfessionalEmployee:" << std::endl;
    std::cout << "Name: " << emp.get_first_name() << " " << emp.get_last_name() << std::endl;
    std::cout << "Address: " << emp.get_address() << std::endl;
    std::cout << "Weekly pay: $" << emp.calc_weekly_pay() << std::endl;
    std::cout << "Vacation hours earned this week: " << emp.calc_weekly_vacation_hours_earned() << std::endl;
    std::cout << "Weekly healthcare contributions: $" << emp.calc_weekly_healthcare_contributions() << std::endl;
    std::cout << "Hourly pay: $" << emp.get_hourly_pay() << std::endl;
    std::cout << "Hours worked this week: " << emp.get_weekly_hours_worked() << std::endl;
}

int main()
{
    test_list();
    test_professional_employee();
    test_nonprofessional_employee();
    return 0;
}