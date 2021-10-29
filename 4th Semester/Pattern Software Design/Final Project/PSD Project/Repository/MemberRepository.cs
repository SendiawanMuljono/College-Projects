using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Model;

namespace PSD_Project.Repository
{
    public class MemberRepository
    {
        public static List<MsMember> GetAllMembers()
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            return (from x in db.MsMembers select x).ToList();
        }

        public static string InsertMember(MsMember msMember)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            db.MsMembers.Add(msMember);
            db.SaveChanges();
            return "Success";
        }

        public static void DeleteMember(MsMember msMember)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            MsMember member = (from x in db.MsMembers where x.MemberID == msMember.MemberID select x).FirstOrDefault();
            db.MsMembers.Remove(member);
            db.SaveChanges();
        }

        public static string UpdateMember(MsMember member)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            var result = (from x in db.MsMembers
                          where x.MemberID == member.MemberID
                          select x).FirstOrDefault();
            result.MemberID = member.MemberID;
            result.MemberName = member.MemberName;
            result.MemberEmail = member.MemberEmail;
            result.MemberGender = member.MemberGender;
            result.MemberPassword = member.MemberPassword;
            result.MemberPhone = member.MemberPhone;
            result.MemberDOB = member.MemberDOB;
            result.MemberAddress = member.MemberAddress;
            db.SaveChanges();
            return "Success";
        }
        
        public static MsMember getMemberById(int id)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            var result = (from x in db.MsMembers
                          where x.MemberID == id
                          select x).FirstOrDefault();
            return result;
        }

        public static MsMember getMemberByEmail(string email)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            return (from x in db.MsMembers where x.MemberEmail == email select x).FirstOrDefault();
        }
    }
}