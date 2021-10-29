using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Factory;
using PSD_Project.Model;
using PSD_Project.Repository;

namespace PSD_Project.Handler
{
    public class EmployeeHandler
    {
        public static List<MsEmployee> GetAllEmployees()
        {
            return EmployeeRepository.GetAllEmployees();
        }

        public static string InsertEmployee(string Email, string Password, string Name, string Age, string Phone, string Gender, string Street, int Salary)
        {
            var result = "";
            MsEmployee employeeFactory = EmployeeFactory.CreateEmployee(Email, Password, Name, Age, Phone, Gender, Street, Salary);
            result = EmployeeRepository.InsertEmployee(employeeFactory);
            return result;
        }

        public static void DeleteEmployee(int id)
        {
            MsEmployee msEmployee = EmployeeFactory.CreateEmployee(id);
            EmployeeRepository.DeleteEmployee(msEmployee);
        }

        public static string UpdateEmployee(
          int Id, string Email, string Password, string Name,
          string Age, string Phone, string Gender, string Street, int Salary)
        {
            var result = "";
            MsEmployee employeeFactory = EmployeeFactory.CreateEmployee(
                                        Id, Email, Password, Name, Age,
                                        Phone, Gender, Street, Salary);
            result = EmployeeRepository.UpdateEmployee(employeeFactory);
            return result;
        }

        public static MsEmployee getEmployeeById(int Id)
        {
            return EmployeeRepository.getEmployeeById(Id);
        }

        public static MsEmployee getEmployeeByEmail(string email)
        {
            return EmployeeRepository.getEmployeeByEmail(email);
        }
    }
}