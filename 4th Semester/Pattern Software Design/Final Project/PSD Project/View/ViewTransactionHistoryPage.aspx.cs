using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using PSD_Project.Controller;

namespace PSD_Project.View
{
    public partial class ViewTransactionHistoryPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Session["member"] == null)
            {
                Response.Redirect("./HomePage.aspx");
            }
            else
            {
                if (!IsPostBack)
                {
                    trHistReport.ReportSource = TransactionController.trHistoryReport();
                }
            }
        }
    }
}