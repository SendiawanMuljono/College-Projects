<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="PreorderPage.aspx.cs" Inherits="PSD_Project.View.PreorderPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Quantity:<br />
            <asp:TextBox ID="qty" runat="server" TextMode="Number"></asp:TextBox><br />
            <asp:Label ID="lblError" runat="server" Text="" ForeColor="Red"></asp:Label><br />
            <asp:Button ID="btnPreorder" runat="server" Text="PreOrder" OnClick="btnPreorder_Click"/>
        </div>
    </form>
</body>
</html>
