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
    public partial class ManageEmployeePage : System.Web.UI.Page
    {
        List<MsEmployee> employees;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["admin"] == null)
            {
                Response.Redirect("./HomePage.aspx");
            }
            else
            {
                employees = EmployeeController.GetAllEmployees();
                gvEmployee.DataSource = employees;
                gvEmployee.DataBind();
            }
        }

        protected void gvEmployee_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            int idx = int.Parse(e.RowIndex.ToString());
            MsEmployee msEmployee = employees.ElementAt(idx);
            Response.Redirect("./UpdateEmployeePage.aspx?id=" + msEmployee.EmployeeID);
        }

        protected void gvEmployee_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            int idx = int.Parse(e.RowIndex.ToString());
            MsEmployee msEmployee = employees.ElementAt(idx);
            EmployeeController.DeleteEmployee(msEmployee.EmployeeID);
            Response.Redirect("./ManageEmployeePage.aspx");
        }
    }
}