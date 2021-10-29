using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Model;

namespace PSD_Project.Factory
{
    public class MemberFactory
    {
        public static MsMember CreateMember(int id)
        {
            MsMember msMember = new MsMember();
            msMember.MemberID = id;
            return msMember;
        }

        public static MsMember CreateMember(
            string Email, string Password, string Name, string Age,
            string Phone, string Gender, string Street)
        {
            MsMember member = new MsMember
            {
                MemberEmail = Email,
                MemberAddress = Street,
                MemberDOB = Age,
                MemberGender = Gender,
                MemberName = Name,
                MemberPassword = Password,
                MemberPhone = Phone
            };
            return member;
        }

        public static MsMember CreateMember(
            int Id, string Email, string Password, string Name, string Age,
            string Phone, string Gender, string Street)
        {
            MsMember member = new MsMember
            {
                MemberID = Id,
                MemberEmail = Email,
                MemberAddress = Street,
                MemberDOB = Age,
                MemberGender = Gender,
                MemberName = Name,
                MemberPassword = Password,
                MemberPhone = Phone
            };
            return member;
        }
    }
}