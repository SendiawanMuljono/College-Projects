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
    public partial class PreorderPage : System.Web.UI.Page
    {
        static int floID;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["member"] == null)
            {
                Response.Redirect("./HomePage.aspx");
            }
            else
            {
                floID = int.Parse(Request.QueryString["id"]);
            }
        }

        protected void btnPreorder_Click(object sender, EventArgs e)
        {
            int quantity = int.Parse(qty.Text);
            int memID = ((MsMember)Session["member"]).MemberID;
            DateTime trDate = DateTime.Now;
            lblError.Text = TransactionController.validationTransactionPreorder(quantity, floID, memID, trDate);
            if (lblError.Text.Equals(""))
            {
                Response.Redirect("./HomePage.aspx");
            }
        }
    }
}