<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ForgotPasswordPage.aspx.cs" Inherits="PSD_Project.View.ForgotPasswordPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Email" runat="server" Text="Email"></asp:Label><br />
            <input id="txtEmail" runat="server" type="email" /><br />
            <asp:Label ID="Captcha" runat="server" Text="Captcha"></asp:Label><br />
            <asp:Label ID="lblCaptcha" runat="server" Text="" ></asp:Label><br />
            <input id="txtCaptcha" type="text" runat="server"/><br />
            <asp:Label ID="lblNewPs" runat="server" Text="New Password"></asp:Label><br />
            <input id="txtNewPassword" type="password" runat="server" /><br />            
            <asp:Label ID="lblMessage" runat="server" Text="" ForeColor="Red"></asp:Label><br />
            <asp:Button ID="btnForgot" OnClick="btnForgot_Click" runat="server" Text="Re-new Password" /><br />
        </div>
    </form>
</body>
</html>
