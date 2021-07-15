<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ManageEmployeePage.aspx.cs" Inherits="PSD_Project.View.ManageEmployeePage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <a href="./InsertEmployeePage.aspx">Insert Employee</a>
            <asp:GridView ID="gvEmployee" runat="server" AutoGenerateColumns="false" OnRowDeleting="gvEmployee_RowDeleting" OnRowUpdating="gvEmployee_RowUpdating" >
                <Columns>
                    <asp:BoundField DataField="EmployeeID" HeaderText="Employee ID" />
                    <asp:BoundField DataField="EmployeeName" HeaderText="Employee Name" />
                    <asp:BoundField DataField="EmployeeDOB" HeaderText="Employee DOB" />
                    <asp:BoundField DataField="EmployeeGender" HeaderText="Employee Gender" />
                    <asp:BoundField DataField="EmployeeAddress" HeaderText="Employee Address" />
                    <asp:BoundField DataField="EmployeePhone" HeaderText="Employee Phone" />
                    <asp:BoundField DataField="EmployeeEmail" HeaderText="Employee Email" />
                    <asp:BoundField DataField="EmployeeSalary" HeaderText="Employee Salary" />
                    <asp:BoundField DataField="EmployeePassword" HeaderText="Employee Password" />
                    <asp:ButtonField ButtonType="Button" Text="Update" CommandName="Update" />
                    <asp:ButtonField ButtonType="Button" Text="Delete" CommandName="Delete" />
                </Columns>
            </asp:GridView>
        </div>
    </form>
</body>
</html>
