using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Model;

namespace PSD_Project.Repository
{
    public class EmployeeRepository
    {
        public static List<MsEmployee> GetAllEmployees()
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            return (from x in db.MsEmployees select x).ToList();
        }

        public static string InsertEmployee(MsEmployee msEmployee)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            db.MsEmployees.Add(msEmployee);
            db.SaveChanges();
            return "Success";
        }

        public static void DeleteEmployee(MsEmployee msEmployee)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            MsEmployee employee = (from x in db.MsEmployees where x.EmployeeID == msEmployee.EmployeeID select x).FirstOrDefault();
            db.MsEmployees.Remove(employee);
            db.SaveChanges();
        }

        public static string UpdateEmployee(MsEmployee employee)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            var result = (from x in db.MsEmployees
                          where x.EmployeeID == employee.EmployeeID
                          select x).FirstOrDefault();
            result.EmployeeID = employee.EmployeeID;
            result.EmployeeName = employee.EmployeeName;
            result.EmployeeEmail = employee.EmployeeEmail;
            result.EmployeeGender = employee.EmployeeGender;
            result.EmployeePassword = employee.EmployeePassword;
            result.EmployeePhone = employee.EmployeePhone;
            result.EmployeeDOB = employee.EmployeeDOB;
            result.EmployeeAddress = employee.EmployeeAddress;
            result.EmployeeSalary = employee.EmployeeSalary;
            db.SaveChanges();
            return "Success";
        }

        public static MsEmployee getEmployeeById(int id)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            var result = (from x in db.MsEmployees
                          where x.EmployeeID == id
                          select x).FirstOrDefault();
            return result;
        }

        public static MsEmployee getEmployeeByEmail(string email)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            return (from x in db.MsEmployees where x.EmployeeEmail == email select x).FirstOrDefault();
        }
    }
}