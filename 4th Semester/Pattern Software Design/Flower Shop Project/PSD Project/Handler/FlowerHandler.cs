using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Factory;
using PSD_Project.Model;
using PSD_Project.Repository;

namespace PSD_Project.Handler
{
    public class FlowerHandler
    {
        public static List<MsFlower> GetAllFlowers()
        {
            return FlowerRepository.GetAllFlowers();
        }

        public static void InsertFlower(string name, string image, string desc, string fType, int price)
        {
            int fTypeId = FlowerRepository.getFlowerTypeIdByName(fType);
            MsFlower msFlower = FlowerFactory.CreateFlower(name, image, desc, fTypeId, price);
            FlowerRepository.InsertFlower(msFlower);
        }

        public static void DeleteFlower(int Id)
        {
            FlowerRepository.DeleteFlower(Id);
        }

        public static void UpdateFlower(int id, string name, string image, string desc, string fType, int price)
        {
            int fTypeId = FlowerRepository.getFlowerTypeIdByName(fType);
            MsFlower msFlower = FlowerFactory.CreateFlower(id, name, image, desc, fTypeId, price);
            FlowerRepository.UpdateFlower(msFlower);
        }

        public static MsFlower getFlowerById(int id)
        {
            return FlowerRepository.getFlowerById(id);
        }
    }
}