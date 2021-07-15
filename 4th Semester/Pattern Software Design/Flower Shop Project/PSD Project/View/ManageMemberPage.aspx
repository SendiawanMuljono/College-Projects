<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ManageMemberPage.aspx.cs" Inherits="PSD_Project.View.ManageMemberPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <a href="./InsertMemberPage.aspx">Insert Member</a>
            <asp:GridView ID="gvMember" runat="server" AutoGenerateColumns="false" OnRowDeleting="gvMember_RowDeleting" OnRowUpdating="gvMember_RowUpdating" >
                <Columns>
                    <asp:BoundField DataField="MemberID" HeaderText="Member ID" />
                    <asp:BoundField DataField="MemberName" HeaderText="Member Name" />
                    <asp:BoundField DataField="MemberDOB" HeaderText="Member DOB" />
                    <asp:BoundField DataField="MemberGender" HeaderText="Member Gender" />
                    <asp:BoundField DataField="MemberAddress" HeaderText="Member Address" />
                    <asp:BoundField DataField="MemberPhone" HeaderText="Member Phone" />
                    <asp:BoundField DataField="MemberEmail" HeaderText="Member Email" />
                    <asp:BoundField DataField="MemberPassword" HeaderText="Member Password" />
                    <asp:ButtonField ButtonType="Button" Text="Update" CommandName="Update" />
                    <asp:ButtonField ButtonType="Button" Text="Delete" CommandName="Delete" />
                </Columns>
            </asp:GridView>
        </div>
    </form>
</body>
</html>
