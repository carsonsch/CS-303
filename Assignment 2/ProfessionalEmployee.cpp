#include <string>

#include "ProfessionalEmployee.hpp"

ProfessionalEmployee::ProfessionalEmployee(std::string first_name, std::string last_name, std::string address, float monthly_salary)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->address = address;
    this->monthly_salary = monthly_salary;
}

float ProfessionalEmployee::calc_weekly_pay() const
{
    return get_monthly_salary() / 4;
}

float ProfessionalEmployee::calc_weekly_healthcare_contributions() const
{
    // 5% of pay is allocated to healthcare contributions.
    return calc_weekly_pay() * 0.05;
}

float ProfessionalEmployee::calc_weekly_vacation_hours_earned() const
{
    // Professional employees earn 0.8 hours of vacation per week.
    return 0.8;
}

float ProfessionalEmployee::get_monthly_salary() const
{
    return monthly_salary;
}