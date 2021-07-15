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
    public partial class HomePage : System.Web.UI.Page
    {
        List<MsFlower> flowers;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["member"] != null)
            {
                btnViewTransactionHistory.Visible = true;
                gvFlower.Visible = true;
                flowers = FlowerController.GetAllFlowers();
                gvFlower.DataSource = flowers;
                gvFlower.DataBind();
                welcomeMsg.Text = "Welcome, " + ((MsMember)Session["member"]).MemberName;
            }
            else if(Session["employee"] != null)
            {
                btnManageFlower.Visible = true;
                welcomeMsg.Text = "Welcome, " + ((MsEmployee)Session["employee"]).EmployeeName;
            }
            else if(Session["admin"] != null)
            {
                btnManageMember.Visible = true;
                btnManageEmployee.Visible = true;
                welcomeMsg.Text = "Welcome, " + ((MsEmployee)Session["admin"]).EmployeeName;
            }
            else
            {
                Response.Redirect("./LoginPage.aspx");
            }
        }

        protected void btnHome_Click(object sender, EventArgs e)
        {
            Response.Redirect("./HomePage.aspx");
        }

        protected void btnLogout_Click(object sender, EventArgs e)
        {
            if (Request.Cookies["login"] != null)
            {
                Response.Cookies["login"].Expires = DateTime.Now.AddDays(-1);
            }
            Session.Clear();
            Response.Redirect("./LoginPage.aspx");
        }

        protected void btnViewTransactionHistory_Click(object sender, EventArgs e)
        {
            Response.Redirect("./ViewTransactionHistoryPage.aspx");
        }

        protected void gvFlower_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            int idx = int.Parse(e.CommandArgument.ToString());
            MsFlower msFlower = flowers.ElementAt(idx);
            Response.Redirect("./PreorderPage.aspx?id=" + msFlower.FlowerID);
        }

        protected void btnManageFlower_Click(object sender, EventArgs e)
        {
            Response.Redirect("./ManageFlowerPage.aspx");
        }

        protected void btnManageMember_Click(object sender, EventArgs e)
        {
            Response.Redirect("./ManageMemberPage.aspx");
        }

        protected void btnManageEmployee_Click(object sender, EventArgs e)
        {
            Response.Redirect("./ManageEmployeePage.aspx");
        }
    }
}