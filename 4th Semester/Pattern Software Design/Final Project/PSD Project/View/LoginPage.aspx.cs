using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using PSD_Project.Controller;
using PSD_Project.Handler;
using PSD_Project.Model;

namespace PSD_Project.View
{
    public partial class LoginPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                if(Request.Cookies["login"] != null)
                {
                    guestEmail.Text = Request.Cookies["login"]["email"].ToString();
                    guestPassword.Text = Request.Cookies["login"]["password"].ToString();
                }
                if(Session["member"] != null || Session["employee"] != null || Session["admin"] != null)
                {
                    Response.Redirect("./HomePage.aspx");
                }
            }
        }

        protected void btnLogin_Click(object sender, EventArgs e)
        {
            string email = guestEmail.Text;
            string password = guestPassword.Text;
            bool isChecked = rememberMe.Checked;

            errorMsg.Text = GuestController.login(email, password, isChecked);
            if(errorMsg.Text.Equals(""))
            {
                Response.Redirect("./Homepage.aspx");
            }
        }
    }
}