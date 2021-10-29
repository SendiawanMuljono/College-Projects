<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ManageFlowerPage.aspx.cs" Inherits="PSD_Project.View.ManageFlowerPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <a href="./InsertFlowerPage.aspx">Insert Flower</a> <br />
            <asp:GridView ID="gvFlower" runat="server" AutoGenerateColumns="false" OnRowDeleting="gvFlower_RowDeleting" OnRowUpdating="gvFlower_RowUpdating" >
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
                    <asp:ButtonField ButtonType="Button" Text="Update" CommandName="Update" />
                    <asp:ButtonField ButtonType="Button" Text="Delete" CommandName="Delete" />
                </Columns>
            </asp:GridView>
        </div>
    </form>
</body>
</html>
