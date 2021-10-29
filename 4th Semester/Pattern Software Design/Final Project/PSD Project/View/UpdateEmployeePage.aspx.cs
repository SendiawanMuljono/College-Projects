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
    public partial class UpdateEmployeePAGE : System.Web.UI.Page
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
                    MsEmployee employee = EmployeeController.getEmployeeById(Id);
                    txtEmail.Value = employee.EmployeeEmail;
                    txtPassword.Text = employee.EmployeePassword;
                    txtName.Value = employee.EmployeeName;
                    txtDOB.Text = employee.EmployeeDOB;
                    txtPhone.Value = employee.EmployeePhone;
                    _ = employee.EmployeeGender == "Male" ? rbMale.Checked = true : rbFemale.Checked = true;
                    txtStreet.Value = employee.EmployeeAddress;
                    txtSalary.Text = employee.EmployeeSalary.ToString();
                }
            }
        }

        protected void btnUpdate_Click(object sender, EventArgs e)
        {
            string gender = rbMale.Checked ? "Male" : (rbFemale.Checked ? "Female" : null);
            CultureInfo culture = new CultureInfo("es-ES");
            DateTime date = DateTime.Parse(txtDOB.Text.ToString(), culture);
            var status = EmployeeController.validationUpdateEmployee(
                Id,
                txtEmail.Value.ToString(),
                txtPassword.Text,
                txtName.Value.ToString(),
                date,
                txtPhone.Value.ToString(),
                gender,
                txtStreet.Value.ToString(),
                int.Parse(txtSalary.Text)
            );
            lblMessage.Text = status;
            if (status.Equals("Success"))
            {
                Response.Redirect("./ManageEmployeePage.aspx");
            }
        }
    }
}