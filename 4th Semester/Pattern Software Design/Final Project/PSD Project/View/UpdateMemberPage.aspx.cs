using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using PSD_Project.Controller;
using PSD_Project.Model;

namespace PSD_Project.View
{
    public partial class UpdateMemberPage : System.Web.UI.Page
    {
        private static int Id;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["admin"] == null)
            {
                Response.Redirect("./HomePage.aspx");
            }
            else
            {
                if (!IsPostBack)
                {
                    Id = int.Parse(Request.QueryString["id"]);
                    MsMember member = MemberController.getMemberById(Id);
                    txtEmail.Value = member.MemberEmail;
                    txtPassword.Text = member.MemberPassword;
                    txtName.Value = member.MemberName;
                    txtDOB.Text = member.MemberDOB;
                    txtPhone.Value = member.MemberPhone;
                    _ = member.MemberGender == "Male" ? rbMale.Checked = true : rbFemale.Checked = true;
                    txtStreet.Value = member.MemberAddress;
                }
            }
        }

        protected void btnUpdate_Click(object sender, EventArgs e)
        {
            string gender = rbMale.Checked ? "Male" : (rbFemale.Checked ? "Female" : null);
            CultureInfo culture = new CultureInfo("es-ES");
            DateTime date = DateTime.Parse(txtDOB.Text.ToString(), culture);
            var status = MemberController.validationUpdateMember(
                Id,
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