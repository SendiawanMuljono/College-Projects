<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="UpdateFlowerPage.aspx.cs" Inherits="PSD_Project.View.UpdateFlowerPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Name:<br />
            <asp:TextBox ID="txtName" runat="server"></asp:TextBox><br />
            Image:<br />
            <asp:Image ID="currImg" ImageUrl="" Width="150px" Height="150px" runat="server" /><br />
            <asp:FileUpload ID="imgFlower" runat="server" AllowMultiple="false"/><br />
            Description:<br />
            <asp:TextBox ID="txtDescription" runat="server"></asp:TextBox><br />
            Flower Type:<br />
            <asp:TextBox ID="txtFlowerType" runat="server"></asp:TextBox> <br />
            Price:<br />
            <asp:TextBox ID="txtPrice" runat="server"></asp:TextBox><br />
            <asp:Label ID="lblError" runat="server" Text="" ForeColor="Red"></asp:Label><br />
            <asp:Button ID="btnUpdate" runat="server" Text="Update Flower" OnClick="btnUpdate_Click"/>
        </div>
    </form>
</body>
</html>
