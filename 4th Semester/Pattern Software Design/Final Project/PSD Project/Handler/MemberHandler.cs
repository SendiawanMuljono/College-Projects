using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Factory;
using PSD_Project.Model;
using PSD_Project.Repository;

namespace PSD_Project.Handler
{
    public class MemberHandler
    {
        public static List<MsMember> GetAllMembers()
        {
            return MemberRepository.GetAllMembers();
        }

        public static string InsertMember(string Email, string Password, string Name, string Age, string Phone, string Gender, string Street)
        {
            var result = "";
            MsMember memberFactory = MemberFactory.CreateMember(Email, Password, Name, Age, Phone, Gender, Street);
            result = MemberRepository.InsertMember(memberFactory);
            return result;
        }

        public static void DeleteMember(int id)
        {
            MsMember msMember = MemberFactory.CreateMember(id);
            MemberRepository.DeleteMember(msMember);
        }
        public static string UpdateMember(
          int Id, string Email, string Password, string Name,
          string Age, string Phone, string Gender, string Street)
        {
            var result = "";
            MsMember memberFactory = MemberFactory.CreateMember(
                                        Id, Email, Password, Name, Age,
                                        Phone, Gender, Street);
            result = MemberRepository.UpdateMember(memberFactory);
            return result;
        }

        public static MsMember getMemberById(int Id)
        {
            return MemberRepository.getMemberById(Id);
        }

        public static MsMember getMemberByEmail(string email)
        {
            return MemberRepository.getMemberByEmail(email);
        }
    }
}