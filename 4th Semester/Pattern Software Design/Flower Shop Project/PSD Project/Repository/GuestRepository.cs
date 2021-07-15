using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Model;

namespace PSD_Project.Repository
{
    public class GuestRepository
    {
        public static MsEmployee empLogin(MsEmployee emp)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            MsEmployee msEmployee = (from x in db.MsEmployees where x.EmployeeEmail == emp.EmployeeEmail && x.EmployeePassword == emp.EmployeePassword select x).FirstOrDefault();
            return msEmployee;
        }

        public static MsMember memLogin(MsMember member)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            MsMember msMember = (from x in db.MsMembers where x.MemberEmail == member.MemberEmail && x.MemberPassword == member.MemberPassword select x).FirstOrDefault();
            return msMember;
        }

        public static dynamic get_obj_by_email(string Email, string NewPassword)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            var employee = (from x in db.MsEmployees
                            where x.EmployeeEmail == Email
                            select x).FirstOrDefault();
            if (employee != null)
            {
                employee.EmployeePassword = NewPassword;
                db.SaveChanges();
                return true;
            }

            var member = (from x in db.MsMembers
                          where x.MemberEmail == Email
                          select x).FirstOrDefault();
            if (member != null)
            {
                member.MemberPassword = NewPassword;
                db.SaveChanges();
                return true;
            }

            return false;
        }
    }
}