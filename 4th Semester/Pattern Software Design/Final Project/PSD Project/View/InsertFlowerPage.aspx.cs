using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using PSD_Project.Controller;

namespace PSD_Project.View
{
    public partial class InsertFlowerPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["employee"] == null)
            {
                Response.Redirect("./HomePage.aspx");
            }
        }

        protected void btnInsert_Click(object sender, EventArgs e)
        {
            string name = txtName.Text;
            string image = imgFlower.FileName;
            string desc = txtDescription.Text;
            string fType = txtFlowerType.Text;
            string price = txtPrice.Text;
            lblError.Text = FlowerController.flowerValidation(name, image, desc, fType, price);
            if (lblError.Text.Equals(""))
            {
                var path = HttpContext.Current.Server.MapPath("../Assets/" + image);
                imgFlower.SaveAs(path);
                Response.Redirect("./ManageFlowerPage.aspx");
            }
        }
    }
}