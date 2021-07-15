using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Web;
using PSD_Project.Handler;
using PSD_Project.Model;

namespace PSD_Project.Controller
{
    public class EmployeeController
    {
        public static List<MsEmployee> GetAllEmployees()
        {
            return EmployeeHandler.GetAllEmployees();
        }

        public static void DeleteEmployee(int id)
        {
            EmployeeHandler.DeleteEmployee(id);
        }

        public static MsEmployee getEmployeeById(int Id)
        {
            return EmployeeHandler.getEmployeeById(Id);
        }

        public static string validationUpdateEmployee(
            int Id,
            string Email,
            string Password,
            string Name,
            DateTime Age,
            string Phone,
            string Gender,
            string Street,
            int Salary
            )
        {
            string msg = "";
            DateTime datenow = DateTime.Now.AddYears(-17);
            Debug.WriteLine(datenow);
            if (!Email.Contains(".") || !Email.Contains("@") || String.IsNullOrEmpty(Email))
            {
                msg += "Wrong email format or empty! ";
            }
            else
            {
                MsEmployee employee = EmployeeHandler.getEmployeeByEmail(Email);
                if(employee != null)
                {
                    msg += "Email must be unique! ";
                }
            }
            if (Password.Length < 3 || Password.Length > 20)
            {
                msg += "Password length must between 3 and 20! ";
            }
            if (Name.Length < 3 || Name.Length > 20 || !Name.All(char.IsLetter))
            {
                msg += "Name length must between 3 and 20 and must be letter! ";
            }
            if (DateTime.Compare(Age, datenow) > 0)
            {
                msg += "Minimal age is 17 years old! ";
            }
            if (String.IsNullOrEmpty(Gender))
            {
                msg += "Gender must be chosen! ";
            }
            if (!Phone.All(char.IsDigit))
            {
                msg += "Phone number must be numeric! ";
            }
            if (!Street.Contains("Street"))
            {
                msg += "Address must contains 'Street'! ";
            }
            if(Salary < 100 || Salary > 1000)
            {
                msg += "Salary must be between 100 and 1000 inclusively! ";
            }

            if (!msg.Equals(""))
            {
                return msg;
            }
            return EmployeeHandler.UpdateEmployee(
                Id, Email, Password, Name, Age.ToString("dd/MM/yyyy"),
                Phone, Gender, Street, Salary);
        }

        public static string validationEmployee(
            string Email,
            string Password,
            string Name,
            DateTime Age,
            string Phone,
            string Gender,
            string Street,
            int Salary
            )
        {
            string msg = "";
            DateTime datenow = DateTime.Now.AddYears(-17);
            Debug.WriteLine(datenow);
            if (!Email.Contains(".") || !Email.Contains("@") || String.IsNullOrEmpty(Email))
            {
                msg += "Wrong email format or empty! ";
            }
            else
            {
                MsEmployee employee = EmployeeHandler.getEmployeeByEmail(Email);
                if (employee != null)
                {
                    msg += "Email must be unique! ";
                }
            }
            if (Password.Length < 3 || Password.Length > 20)
            {
                msg += "Password length must between 3 and 20! ";
            }
            if (Name.Length < 3 || Name.Length > 20 || !Name.All(char.IsLetter))
            {
                msg += "Name length must between 3 and 20 and must be letter! ";
            }
            if (DateTime.Compare(Age, datenow) > 0)
            {
                msg += "Minimal age is 17 years old! ";
            }
            if (String.IsNullOrEmpty(Gender))
            {
                msg += "Gender must be chosen! ";
            }
            if (!Phone.All(char.IsDigit))
            {
                msg += "Phone number must be numeric! ";
            }
            if (!Street.Contains("Street"))
            {
                msg += "Address must contains 'Street'! ";
            }
            if (Salary < 100 || Salary > 1000)
            {
                msg += "Salary must be between 100 and 1000 inclusively! ";
            }

            if (!msg.Equals(""))
            {
                return msg;
            }
            return EmployeeHandler.InsertEmployee(
                Email, Password, Name, Age.ToString("dd/MM/yyyy"),
                Phone, Gender, Street, Salary);
        }
    }
}