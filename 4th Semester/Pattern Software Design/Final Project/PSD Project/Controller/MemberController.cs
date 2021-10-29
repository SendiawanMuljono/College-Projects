using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Web;
using PSD_Project.Handler;
using PSD_Project.Model;

namespace PSD_Project.Controller
{
    public class MemberController
    {
        public static List<MsMember> GetAllMembers()
        {
            return MemberHandler.GetAllMembers();
        }

        public static void DeleteMember(int id)
        {
            MemberHandler.DeleteMember(id);
        }

        public static MsMember getMemberById(int Id)
        {
            return MemberHandler.getMemberById(Id);
        }

        public static string validationUpdateMember(
            int Id,
            string Email,
            string Password,
            string Name,
            DateTime Age,
            string Phone,
            string Gender,
            string Street
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
                MsMember member = MemberHandler.getMemberByEmail(Email);
                if(member != null)
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

            if (!msg.Equals(""))
            {
                return msg;
            }
            return MemberHandler.UpdateMember(
                Id, Email, Password, Name, Age.ToString("dd/MM/yyyy"),
                Phone, Gender, Street);
        }

        public static string validationMember(
            string Email,
            string Password,
            string Name,
            DateTime Age,
            string Phone,
            string Gender,
            string Street
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
                MsMember member = MemberHandler.getMemberByEmail(Email);
                if (member != null)
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

            if (!msg.Equals(""))
            {
                return msg;
            }
            return MemberHandler.InsertMember(
                Email, Password, Name, Age.ToString("dd/MM/yyyy"),
                Phone, Gender, Street);
        }
    }
}