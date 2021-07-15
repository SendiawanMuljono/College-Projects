using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Factory;
using PSD_Project.Model;
using PSD_Project.Repository;

namespace PSD_Project.Handler
{
    public class GuestHandler
    {
        public static MsEmployee empLogin(string email, string password)
        {
            MsEmployee emp = GuestFactory.CreateEmployee(email, password);
            return GuestRepository.empLogin(emp);
        }

        public static MsMember memLogin(string email, string password)
        {
            MsMember mem = GuestFactory.CreateMember(email, password);
            return GuestRepository.memLogin(mem);
        }

        public static dynamic get_obj_by_email(string Email, string NewPassword)
        {
            return GuestRepository.get_obj_by_email(Email, NewPassword);
        }
    }
}