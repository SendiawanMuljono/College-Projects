using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using PSD_Project.Controller;
using PSD_Project.Model;

namespace PSD_Project.View
{
    public partial class UpdateFlowerPage : System.Web.UI.Page
    {
        static int id;
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Session["employee"] == null)
            {
                Response.Redirect("./HomePage.aspx");
            }
            else
            {
                if (!IsPostBack)
                {
                    id = int.Parse(Request.QueryString["id"]);
                    MsFlower msFlower = FlowerController.getFlowerById(id);
                    txtName.Text = msFlower.FlowerName;
                    currImg.ImageUrl = msFlower.FlowerImage;
                    txtDescription.Text = msFlower.FlowerDescription;
                    txtFlowerType.Text = msFlower.MsFlowerType.FlowerTypeName;
                    txtPrice.Text = msFlower.FlowerPrice.ToString();
                }
            }
        }

        protected void btnUpdate_Click(object sender, EventArgs e)
        {
            string name = txtName.Text;
            string image = imgFlower.FileName;
            string desc = txtDescription.Text;
            string fType = txtFlowerType.Text;
            string price = txtPrice.Text;
            lblError.Text = FlowerController.flowerValidation(id, name, image, desc, fType, price);
            if (lblError.Text.Equals(""))
            {
                var path = HttpContext.Current.Server.MapPath("../Assets/" + image);
                imgFlower.SaveAs(path);
                Response.Redirect("./ManageFlowerPage.aspx");
            }
        }
    }
}