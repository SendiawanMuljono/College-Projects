using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using PSD_Project.Controller;

namespace PSD_Project.View
{
    public partial class InsertMemberPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Session["admin"] == null)
            {
                Response.Redirect("./HomePage.aspx");
            }
        }

        protected void btnInsert_Click(object sender, EventArgs e)
        {
            string gender = rbMale.Checked ? "Male" : (rbFemale.Checked ? "Female" : null);
            CultureInfo culture = new CultureInfo("es-ES");
            DateTime date = DateTime.Parse(txtDOB.Text.ToString(), culture);
            var status = MemberController.validationMember(
                txtEmail.Value.ToString(),
                txtPassword.Text,
                txtName.Value.ToString(),
                date,
                txtPhone.Value.ToString(),
                gender,
                txtStreet.Value.ToString()
            );
            lblMessage.Text = status;
            if (status.Equals("Success"))
            {
                Response.Redirect("./ManageMemberPage.aspx");
            }
        }
    }
}