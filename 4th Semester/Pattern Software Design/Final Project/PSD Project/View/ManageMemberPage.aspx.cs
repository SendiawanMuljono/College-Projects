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
    public partial class ManageMemberPage : System.Web.UI.Page
    {
        List<MsMember> members;
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Session["admin"] == null)
            {
                Response.Redirect("./HomePage.aspx");
            }
            else
            {
                members = MemberController.GetAllMembers();
                gvMember.DataSource = members;
                gvMember.DataBind();
            }
        }

        protected void gvMember_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            int idx = int.Parse(e.RowIndex.ToString());
            MsMember msMember = members.ElementAt(idx);
            Response.Redirect("./UpdateMemberPage.aspx?id=" + msMember.MemberID);
        }

        protected void gvMember_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            int idx = int.Parse(e.RowIndex.ToString());
            MsMember msMember = members.ElementAt(idx);
            MemberController.DeleteMember(msMember.MemberID);
            Response.Redirect("./ManageMemberPage.aspx");
        }
    }
}