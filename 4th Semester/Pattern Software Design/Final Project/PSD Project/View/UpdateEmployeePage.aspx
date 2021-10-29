<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="UpdateEmployeePage.aspx.cs" Inherits="PSD_Project.View.UpdateEmployeePAGE" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <script src="https://code.jquery.com/jquery-1.12.4.js"></script>
    <script src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"></script>
    <link rel="stylesheet" href="//code.jquery.com/ui/1.12.1/themes/base/jquery-ui.css">
    <script>
        $(function () {
            $("#txtDOB").datepicker({
                changeMonth: true,
                changeYear: true,
                dateFormat: 'yy/mm/dd'
            });
        });
    </script>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Text="Email"></asp:Label><br />
            <input id="txtEmail" type="email" runat="server"/><br />
            <asp:Label ID="Label2" runat="server" Text="Password"></asp:Label><br />
            <asp:TextBox ID="txtPassword" runat="server"></asp:TextBox><br />
            <asp:Label ID="Label3" runat="server" Text="Name"></asp:Label><br />
            <input id="txtName" type="text" runat="server"/><br />
            <asp:Label ID="Label4" runat="server" Text="Age"></asp:Label><br />
            <asp:TextBox ID="txtDOB" runat="server" /><br />
            <asp:Label ID="Label5" runat="server" Text="Gender"></asp:Label><br />
            <asp:RadioButton ID="rbMale" runat="server" Text="Male" GroupName="gender"/>
            <asp:RadioButton ID="rbFemale" runat="server" Text="Female" GroupName="gender"/><br />
            <asp:Label ID="Label6" runat="server" Text="Phone Number"></asp:Label><br />
            <input id="txtPhone" type="text" runat="server"/><br />
            <asp:Label ID="Label7" runat="server" Text="Address"></asp:Label><br />
            <input id="txtStreet" type="text" runat="server"/><br />
            <asp:Label ID="Label8" runat="server" Text="Salary"></asp:Label><br />
            <asp:TextBox ID="txtSalary" TextMode="Number" runat="server"></asp:TextBox><br />
            <asp:Button ID="btnUpdate" runat="server" Text="Update" OnClick="btnUpdate_Click" /><br />
            <asp:Label ID="lblMessage" runat="server" Text=""></asp:Label><br />
        </div>
    </form>
</body>
</html>
