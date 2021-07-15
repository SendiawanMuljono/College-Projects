<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="LoginPage.aspx.cs" Inherits="PSD_Project.View.LoginPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Email: <asp:TextBox ID="guestEmail" runat="server" TextMode="Email"></asp:TextBox><br />
            Password: <asp:TextBox ID="guestPassword" runat="server"></asp:TextBox><br />
            <asp:CheckBox ID="rememberMe" runat="server" /> Remember me<br />
            <asp:Label ID="errorMsg" runat="server" Text="" ForeColor="Red"></asp:Label><br />
            <asp:Button ID="btnLogin" runat="server" Text="Login" OnClick="btnLogin_Click"/><br />
            <a href="./RegisterPage.aspx">Register</a>
            <a href="./ForgotPasswordPage.aspx">Forgot Password</a>
        </div>
    </form>
</body>
</html>
