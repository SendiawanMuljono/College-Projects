using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Handler;
using PSD_Project.Model;

namespace PSD_Project.Controller
{
    public class FlowerController
    {
        public static List<MsFlower> GetAllFlowers()
        {
            return FlowerHandler.GetAllFlowers();
        }

        public static void DeleteFlower(int Id)
        {
            FlowerHandler.DeleteFlower(Id);
        }

        public static string flowerValidation(string name, string image, string desc, string fType, string price)
        {
            string msg = "";
            if (name.Equals(""))
            {
                msg += "Name must be filled! "; 
            }
            else
            {
                if(name.Length < 5)
                {
                    msg += "Name minimal length is 5 characters! ";
                }
            }
            if (!image.EndsWith(".jpg"))
            {
                msg += "Image extension must end with '.jpg'! ";
            }
            if(desc.Length <= 50)
            {
                msg += "Description must be longer than 50 characters! ";
            }
            if(!fType.Equals("Daisies") && !fType.Equals("Lilies") && !fType.Equals("Roses"))
            {
                msg += "Flower type must be either 'Daisies', 'Lilies' or 'Roses'! ";
            }
            if(int.TryParse(price, out int resultPrice) == false)
            {
                msg += "Price must be numeric! ";
            }
            else
            {
                if(resultPrice < 20 || resultPrice > 100)
                {
                    msg += "Price must be between 20 and 100 inclusively! ";
                }
            }

            if (msg.Equals(""))
            {
                string imagePath = "../Assets/" + image;
                FlowerHandler.InsertFlower(name, imagePath, desc, fType, resultPrice);
            }

            return msg;
        }

        public static string flowerValidation(int id, string name, string image, string desc, string fType, string price)
        {
            string msg = "";
            if (name.Equals(""))
            {
                msg += "Name must be filled! ";
            }
            else
            {
                if (name.Length < 5)
                {
                    msg += "Name minimal length is 5 characters! ";
                }
            }
            if (!image.EndsWith(".jpg"))
            {
                msg += "Image extension must end with '.jpg'! ";
            }
            if (desc.Length <= 50)
            {
                msg += "Description must be longer than 50 characters! ";
            }
            if (!fType.Equals("Daisies") && !fType.Equals("Lilies") && !fType.Equals("Roses"))
            {
                msg += "Flower type must be either 'Daisies', 'Lilies' or 'Roses'! ";
            }
            if (int.TryParse(price, out int resultPrice) == false)
            {
                msg += "Price must be numeric! ";
            }
            else
            {
                if (resultPrice < 20 || resultPrice > 100)
                {
                    msg += "Price must be between 20 and 100 inclusively! ";
                }
            }

            if (msg.Equals(""))
            {
                string imagePath = "../Assets/" + image;
                FlowerHandler.UpdateFlower(id, name, imagePath, desc, fType, resultPrice);
            }

            return msg;
        }

        public static MsFlower getFlowerById(int id)
        {
            return FlowerHandler.getFlowerById(id);
        }
    }
}