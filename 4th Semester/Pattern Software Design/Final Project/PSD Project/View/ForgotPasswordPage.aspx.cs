using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using PSD_Project.Controller;

namespace PSD_Project.View
{
    public partial class ForgotPasswordPage : System.Web.UI.Page
    {
        private static string captcha;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["member"] != null || Session["employee"] != null || Session["admin"] != null)
            {
                Response.Redirect("./HomePage.aspx");
            }
            else
            {
                if (!IsPostBack)
                {
                    captcha = GuestController.GetCaptcha();
                    lblCaptcha.Text = captcha;

                }
            }
        }

        protected void btnForgot_Click(object sender, EventArgs e)
        {
            var validation = GuestController
            .forgotPass(
                txtEmail.Value.ToString(),
                txtNewPassword.Value.ToString(),
                txtCaptcha.Value.ToString(),
                captcha
            );
            lblMessage.Text = validation;
            captcha = GuestController.GetCaptcha();
            lblCaptcha.Text = captcha;
            if (lblMessage.Text.Equals("Success"))
            {
                Response.Redirect("./LoginPage.aspx");
            }
        }
    }
}