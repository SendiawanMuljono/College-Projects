using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Model;

namespace PSD_Project.Factory
{
    public class FlowerFactory
    {
        public static MsFlower CreateFlower(string name, string image, string desc, int fTypeId, int price)
        {
            MsFlower msFlower = new MsFlower();
            msFlower.FlowerName = name;
            msFlower.FlowerImage = image;
            msFlower.FlowerDescription = desc;
            msFlower.FlowerTypeID = fTypeId;
            msFlower.FlowerPrice = price;

            return msFlower;
        }

        public static MsFlower CreateFlower(int id, string name, string image, string desc, int fTypeId, int price)
        {
            MsFlower msFlower = new MsFlower();
            msFlower.FlowerID = id;
            msFlower.FlowerName = name;
            msFlower.FlowerImage = image;
            msFlower.FlowerDescription = desc;
            msFlower.FlowerTypeID = fTypeId;
            msFlower.FlowerPrice = price;

            return msFlower;
        }
    }
}