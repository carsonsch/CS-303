#ifndef PROFESSIONAL_EMPLOYEE_HPP
#define PROFESSIONAL_EMPLOYEE_HPP

#include <string>
#include "Employee.hpp"

class ProfessionalEmployee : public Employee
{
    public:
        ProfessionalEmployee(std::string first_name, std::string last_name, std::string address, float monthly_salary);
        virtual float calc_weekly_pay() const;
        virtual float calc_weekly_healthcare_contributions() const;
        virtual float calc_weekly_vacation_hours_earned() const;

        float get_monthly_salary() const;

    private:
        float monthly_salary;
};

#endif