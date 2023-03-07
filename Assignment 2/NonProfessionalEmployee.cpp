#include <string>

#include "NonProfessionalEmployee.hpp"

NonProfessionalEmployee::NonProfessionalEmployee(std::string first_name, std::string last_name, std::string address, float hourly_pay, float weekly_hours_worked)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->address = address;
    this->hourly_pay = hourly_pay;
    this->weekly_hours_worked = weekly_hours_worked;
}

float NonProfessionalEmployee::calc_weekly_pay() const
{
    // Weekly pay is hourly rate * hours worked in the week.
    return hourly_pay * weekly_hours_worked;
}

float NonProfessionalEmployee::calc_weekly_healthcare_contributions() const
{
    // 2% of pay is allocated to healthcare contributions.
    return calc_weekly_pay() * 0.02;
}

float NonProfessionalEmployee::calc_weekly_vacation_hours_earned() const
{
    // Professional employees earn 0.015 hours of vacation per hour worked.
    return weekly_hours_worked * 0.015;
}

float NonProfessionalEmployee::get_hourly_pay() const
{
    return hourly_pay;
}

float NonProfessionalEmployee::get_weekly_hours_worked() const
{
    return weekly_hours_worked;
}