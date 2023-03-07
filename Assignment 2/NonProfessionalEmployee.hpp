#ifndef NON_PROFESSIONAL_EMPLOYEE_HPP
#define NON_PROFESSIONAL_EMPLOYEE_HPP

#include <string>
#include "Employee.hpp"

class NonProfessionalEmployee : public Employee
{
    public:
        NonProfessionalEmployee(std::string first_name, std::string last_name, std::string address, float hourly_pay, float weekly_hours_worked);
        virtual float calc_weekly_pay() const;
        virtual float calc_weekly_healthcare_contributions() const;
        virtual float calc_weekly_vacation_hours_earned() const;

        float get_hourly_pay() const;
        float get_weekly_hours_worked() const;

    private:
        float hourly_pay;
        float weekly_hours_worked;
};

#endif