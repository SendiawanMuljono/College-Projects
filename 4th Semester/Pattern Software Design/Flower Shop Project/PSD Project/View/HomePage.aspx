<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="HomePage.aspx.cs" Inherits="PSD_Project.View.HomePage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="welcomeMsg" runat="server" Text=""></asp:Label><br />
            <asp:Button ID="btnHome" runat="server" Text="Home" OnClick="btnHome_Click"/><br />
            <asp:Button ID="btnLogout" runat="server" Text="Logout" OnClick="btnLogout_Click"/><br />
            <%-- Member --%>
            <asp:Button ID="btnViewTransactionHistory" runat="server" Text="View Transaction History" OnClick="btnViewTransactionHistory_Click" Visible="false"/>
            <asp:GridView ID="gvFlower" runat="server" AutoGenerateColumns="false" OnRowCommand="gvFlower_RowCommand" Visible="false">
                <Columns>
                    <asp:BoundField DataField="FlowerID" HeaderText="Flower ID" />
                    <asp:BoundField DataField="FlowerName" HeaderText="Flower Name" />
                    <asp:BoundField DataField="FlowerTypeID" HeaderText="Flower Type ID" />
                    <asp:BoundField DataField="FlowerDescription" HeaderText="Flower Description" />
                    <asp:BoundField DataField="FlowerPrice" HeaderText="Flower Price" />
                    <asp:TemplateField HeaderText="Flower Image">
                        <ItemTemplate>
                            <asp:Image ID="FlowerImage" ImageUrl='<%# Eval("FlowerImage") %>' runat="server" Height="150px" Width="150px"/>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:ButtonField ButtonType="Button" Text="Preorder" />
                </Columns>
            </asp:GridView>
            <%-- Employee --%>
            <asp:Button ID="btnManageFlower" runat="server" Text="Manage Flower" OnClick="btnManageFlower_Click" Visible="false"/>
            <%-- Admin --%>
            <asp:Button ID="btnManageMember" runat="server" Text="Manage Member" OnClick="btnManageMember_Click" Visible="false"/>
            <asp:Button ID="btnManageEmployee" runat="server" Text="Manage Employee" OnClick="btnManageEmployee_Click" Visible="false"/>
        </div>
    </form>
</body>
</html>
