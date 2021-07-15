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
    public partial class ManageFlowerPage : System.Web.UI.Page
    {
        List<MsFlower> flowers;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["employee"] == null)
            {
                Response.Redirect("./HomePage.aspx");
            }
            else
            {
                flowers = FlowerController.GetAllFlowers();
                gvFlower.DataSource = flowers;
                gvFlower.DataBind();
            }
        }

        protected void gvFlower_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            int idx = int.Parse(e.RowIndex.ToString());
            MsFlower msFlower = flowers.ElementAt(idx);
            FlowerController.DeleteFlower(msFlower.FlowerID);
            Response.Redirect("./ManageFlowerPage.aspx");
        }

        protected void gvFlower_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            int idx = int.Parse(e.RowIndex.ToString());
            MsFlower msFlower = flowers.ElementAt(idx);
            Response.Redirect("./UpdateFlowerPage.aspx?id=" + msFlower.FlowerID);
        }
    }
}