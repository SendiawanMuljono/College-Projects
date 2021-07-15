using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Model;

namespace PSD_Project.Factory
{
    public class GuestFactory
    {
        public static MsEmployee CreateEmployee(string email, string password)
        {
            MsEmployee employee = new MsEmployee();
            employee.EmployeeEmail = email;
            employee.EmployeePassword = password;
            return employee;
        }

        public static MsMember CreateMember(string email, string password)
        {
            MsMember member = new MsMember();
            member.MemberEmail = email;
            member.MemberPassword = password;
            return member;
        }
    }
}