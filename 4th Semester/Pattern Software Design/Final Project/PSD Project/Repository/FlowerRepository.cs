using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Model;

namespace PSD_Project.Repository
{
    public class FlowerRepository
    {
        public static List<MsFlower> GetAllFlowers()
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            return (from x in db.MsFlowers select x).ToList();
        }

        public static void InsertFlower(MsFlower msFlower)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            db.MsFlowers.Add(msFlower);
            db.SaveChanges();
        }

        public static void DeleteFlower(int Id)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            MsFlower msFlower = (from x in db.MsFlowers where x.FlowerID == Id select x).FirstOrDefault();
            db.MsFlowers.Remove(msFlower);
            db.SaveChanges();
        }

        public static void UpdateFlower(MsFlower msFlower)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            MsFlower ms = (from x in db.MsFlowers where x.FlowerID == msFlower.FlowerID select x).FirstOrDefault();
            ms.FlowerName = msFlower.FlowerName;
            ms.FlowerImage = msFlower.FlowerImage;
            ms.FlowerDescription = msFlower.FlowerDescription;
            ms.FlowerTypeID = msFlower.FlowerTypeID;
            ms.FlowerPrice = msFlower.FlowerPrice;
            db.SaveChanges();
        }

        public static MsFlower getFlowerById(int id)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            MsFlower msFlower = (from x in db.MsFlowers where x.FlowerID == id select x).FirstOrDefault();
            return msFlower;
        }

        public static int getFlowerTypeIdByName(string fType)
        {
            NeinteenFlowerDBEntities db = new NeinteenFlowerDBEntities();
            return (from x in db.MsFlowerTypes where x.FlowerTypeName == fType select x.FlowerTypeID).FirstOrDefault();
        }
    }
}