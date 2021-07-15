using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Model;

namespace PSD_Project.Repository
{
    public class TransactionRepository
    {
        public static void InsertTrHeader(TrHeader trHeader)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            db.TrHeaders.Add(trHeader);
            db.SaveChanges();
        }

        public static void InsertTrDetail(TrDetail trDetail)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            db.TrDetails.Add(trDetail);
            db.SaveChanges();
        }

        public static TrHeader getLastTrHeader()
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            TrHeader trHeader = (from x in db.TrHeaders orderby x.TransactionID descending select x).FirstOrDefault();
            return trHeader;
        }
    }
}