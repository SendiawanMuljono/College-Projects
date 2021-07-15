-- Kelompok 11
-- Glenn Karjadidjaja (2301850645)
-- Andre Setiawan Wijaya (2301852695)
-- Philip Indra Prayitno (2301856125)
-- Sendiawan (2301862733)

CREATE DATABASE cateringDelViaDB;
USE cateringDelViaDB;

-- 1
SELECT StaffName, 
	   'StaffPositionName' = PositionName,
	   [Total Activity] = COUNT(Purchase.StaffID) + COUNT(ServicesTransaction.StaffID)
FROM Staff
JOIN StaffPosition ON Staff.PositionID = StaffPosition.PositionID
FULL JOIN Purchase ON Staff.StaffID = Purchase.StaffID
FULL JOIN ServicesTransaction ON Staff.StaffID = ServicesTransaction.StaffID
WHERE (StaffSalary BETWEEN 1000000 AND 4000000)
GROUP BY Staff.StaffID, StaffName, PositionName
HAVING (COUNT(Purchase.StaffID) + COUNT(ServicesTransaction.StaffID)) > 2;

-- 2
SELECT Customer.CustomerID,
	   CustomerName,
	   'Pax Bought' = SUM(MenuPax)
FROM Customer 
JOIN ServicesTransaction ON Customer.CustomerID = ServicesTransaction.CustomerID
JOIN TransactionDetail ON ServicesTransaction.TransactionID = TransactionDetail.TransactionID
WHERE (Customer.CustomerGender = 'Male') 
	  AND (MONTH(TransactionDate) BETWEEN 1 AND 6)
GROUP BY ServicesTransaction.TransactionID, Customer.CustomerID, Customer.CustomerName;

-- 3
SELECT IngredientName,
	   [Ingredient Bought] = SUM(IngredientQuantity),
	   [Purchase Count] = COUNT(Purchase.PurchaseID),
	   [Total Expenses] = SUM(IngredientQuantity * IngredientPrice)
FROM Ingredient
JOIN PurchaseDetail ON Ingredient.IngredientID = PurchaseDetail.IngredientID
JOIN Purchase ON PurchaseDetail.PurchaseID = Purchase.PurchaseID
WHERE (MONTH(PurchaseDate) % 2 = 0)
	  AND (DATENAME(WEEKDAY, PurchaseDate) IN ('Tuesday', 'Wednesday', 'Thursday', 'Friday'))
GROUP BY Ingredient.IngredientID, IngredientName;

-- 4
SELECT [Staff First Name] = LEFT(StaffName, CHARINDEX(' ', StaffName, 1)-1),
	   [Transaction Count] = COUNT(DISTINCT TransactionDetail.TransactionID),
	   [Pax Sold] = SUM(MenuPax)
FROM TransactionDetail
JOIN ServicesTransaction ON ServicesTransaction.TransactionID = TransactionDetail.TransactionID
JOIN Staff ON ServicesTransaction.StaffID = Staff.StaffID
WHERE CAST(RIGHT(Staff.StaffID, 1) AS INT) % 2 = 1 
	  AND CAST(RIGHT(CustomerID, 1) AS INT) % 2 = 0
GROUP BY Staff.StaffID, StaffName;

-- 5
SELECT [Vendor Name] = REPLACE(VendorName, 'PT.', ''),
	   IngredientName,
	   [Ingredient Price] = 'Rp. ' + CAST(IngredientPrice AS VARCHAR)
FROM Vendor 
JOIN Purchase ON Vendor.VendorID = Purchase.VendorID
JOIN PurchaseDetail ON Purchase.PurchaseID = PurchaseDetail.PurchaseID
JOIN Ingredient ON PurchaseDetail.IngredientID = Ingredient.IngredientID
JOIN (
	 SELECT Average = AVG(IngredientPrice) 
	 FROM Ingredient
	 ) AS Ingrdnt ON Ingredient.IngredientID = Ingredient.IngredientID
WHERE IngredientPrice >= Ingrdnt.Average 
	  AND IngredientStock < 250;

-- 6
SELECT CustomerName,
	   TransactionDate = CONVERT(VARCHAR, TransactionDate, 100),
	   MenuName,
	   MenuPrice,
	   [Brief Description] = LEFT(MenuDescription, CHARINDEX(' ', MenuDescription, CHARINDEX(' ', MenuDescription, 1)+1)-1),
	   MenuPax,
	   [Total Price] = MenuPrice * MenuPax
FROM Customer
JOIN ServicesTransaction ON Customer.CustomerID = ServicesTransaction.CustomerID
JOIN TransactionDetail ON ServicesTransaction.TransactionID = TransactionDetail.TransactionID
JOIN Menu ON TransactionDetail.MenuID = Menu.MenuID
JOIN (
	 SELECT Average = AVG(MenuPrice) 
	 FROM Menu) AS price ON Menu.MenuID = Menu.MenuID
WHERE MenuPrice >= price.Average 
AND TransactionDetail.TransactionID IN (
		SELECT TransactionID FROM TransactionDetail
		GROUP BY TransactionID
		HAVING SUM(MenuPax) > 100);

-- 7
SELECT [Staff Name] = UPPER(StaffName),
	   [Purchase Date] = CONVERT(VARCHAR, PurchaseDate, 100),
	   [Quantity Bought] = CAST(SUM(IngredientQuantity) AS VARCHAR) + ' pcs'
FROM Staff
JOIN Purchase ON Staff.StaffID = Purchase.StaffID
JOIN PurchaseDetail ON Purchase.PurchaseID = PurchaseDetail.PurchaseID
JOIN Ingredient ON PurchaseDetail.IngredientID = Ingredient.IngredientID
JOIN (
	 SELECT Maksimum = MAX(IngredientPrice) 
	 FROM Ingredient) AS price ON Ingredient.IngredientID = Ingredient.IngredientID
WHERE MONTH(PurchaseDate) % 2 = 0 
	  AND IngredientPrice < price.Maksimum
GROUP BY PurchaseDetail.PurchaseID, StaffName, PurchaseDate;

-- 8
SELECT CustomerName,
	   Email = LEFT(CustomerEmail, CHARINDEX('@', CustomerEmail, 1)-1),
	   [Menu Name] = LOWER(MenuName),
	   [Pax Bought] = SUM(MenuPax)
FROM Customer
JOIN ServicesTransaction ON Customer.CustomerID = ServicesTransaction.CustomerID
JOIN TransactionDetail ON ServicesTransaction.TransactionID = TransactionDetail.TransactionID
JOIN Menu ON TransactionDetail.MenuID = Menu.MenuID
JOIN (
	 SELECT Average = AVG(MenuPax) 
	 FROM TransactionDetail) AS pax ON TransactionDetail.MenuID = TransactionDetail.MenuID
WHERE CustomerGender = 'Male' 
	  AND MenuPax >= pax.Average
GROUP BY TransactionDetail.TransactionID, CustomerName, CustomerEmail, MenuName;

-- 9
CREATE VIEW LoyalCustomerView AS
SELECT CustomerName,
	   [Total Transaction] = COUNT(Customer.CustomerID),
	   [Total Pax Purchased] = SUM(MenuPax),
	   [Total Price] = SUM(MenuPax * MenuPrice)
FROM Customer
JOIN ServicesTransaction ON Customer.CustomerID = ServicesTransaction.CustomerID
JOIN TransactionDetail ON ServicesTransaction.TransactionID = TransactionDetail.TransactionID
JOIN Menu ON TransactionDetail.MenuID = Menu.MenuID
WHERE CustomerGender = 'Female'
GROUP BY Customer.CustomerID, CustomerName
HAVING COUNT(Customer.CustomerID) > 2;

-- 10
CREATE VIEW VendorRecapView AS
SELECT VendorName, 
	   [Purchases Made] = COUNT(Vendor.VendorID),
	   [Ingredients Purchased] = SUM(IngredientQuantity)
FROM Vendor
JOIN Purchase ON Vendor.VendorID = Purchase.VendorID
JOIN PurchaseDetail ON Purchase.PurchaseID = PurchaseDetail.PurchaseID
JOIN Ingredient ON PurchaseDetail.IngredientID = Ingredient.IngredientID
WHERE IngredientStock > 150
GROUP BY Vendor.VendorID, VendorName
HAVING COUNT(Purchase.PurchaseID) > 1;