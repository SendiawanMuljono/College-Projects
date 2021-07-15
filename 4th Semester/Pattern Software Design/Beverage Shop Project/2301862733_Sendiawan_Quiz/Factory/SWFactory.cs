using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using _2301862733_Sendiawan_Quiz.Model;

namespace _2301862733_Sendiawan_Quiz.Factory
{
    public class SWFactory
    {
        public static Beverage CreateBeverage(string name, string type, string description, int price)
        {
            Beverage beverage = new Beverage();
            beverage.Name = name;
            beverage.Type = type;
            beverage.Description = description;
            beverage.Price = price;
            return beverage;
        }

        public static Beverage CreateBeverage(int id, string name, string type, string description, int price)
        {
            Beverage beverage = new Beverage();
            beverage.Id = id;
            beverage.Name = name;
            beverage.Type = type;
            beverage.Description = description;
            beverage.Price = price;
            return beverage;
        }
    }
}