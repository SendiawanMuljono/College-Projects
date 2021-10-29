using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Model;

namespace PSD_Project.Factory
{
    public class EmployeeFactory
    {
        public static MsEmployee CreateEmployee(int id)
        {
            MsEmployee msEmployee = new MsEmployee();
            msEmployee.EmployeeID = id;
            return msEmployee;
        }

        public static MsEmployee CreateEmployee(
            int Id, string Email, string Password, string Name, string Age,
            string Phone, string Gender, string Street, int Salary)
        {
            MsEmployee employee = new MsEmployee
            {
                EmployeeID = Id,
                EmployeeEmail = Email,
                EmployeeAddress = Street,
                EmployeeDOB = Age,
                EmployeeGender = Gender,
                EmployeeName = Name,
                EmployeePassword = Password,
                EmployeePhone = Phone,
                EmployeeSalary = Salary
            };
            return employee;
        }

        public static MsEmployee CreateEmployee(
            string Email, string Password, string Name, string Age,
            string Phone, string Gender, string Street, int Salary)
        {
            MsEmployee employee = new MsEmployee
            {
                EmployeeEmail = Email,
                EmployeeAddress = Street,
                EmployeeDOB = Age,
                EmployeeGender = Gender,
                EmployeeName = Name,
                EmployeePassword = Password,
                EmployeePhone = Phone,
                EmployeeSalary = Salary
            };
            return employee;
        }
    }
}