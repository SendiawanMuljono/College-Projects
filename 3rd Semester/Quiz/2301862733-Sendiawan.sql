USE [D'Jewelry Shop]

-- Nama : Sendiawan
-- NIM : 2301862733

-- 1
CREATE TABLE Vendor(
	VendorID CHAR(5) PRIMARY KEY CHECK(VendorID LIKE 'VE[0-9][0-9][0-9]'),
	VendorName VARCHAR(50) CHECK(LEN(VendorName) > 5) NOT NULL,
	VendorVolume VARCHAR(50) NOT NULL
);

-- 2
ALTER TABLE Customer
ADD CustomerEmail VARCHAR(50);

ALTER TABLE Customer
ADD CONSTRAINT CustEmailCons CHECK(CustomerEmail LIKE '%@%');

-- 3
INSERT INTO Customer
VALUES ('CU011', 'Priocesa', 'Female', 'Kaloa Street', '085678123876');

-- 4
SELECT CustomerName = LOWER(CustomerName), CustomerPhoneNumber, CustomerAddress FROM Customer
WHERE CustomerGender = 'Male';

-- 5
DELETE Staff
WHERE StaffID IN(
	SELECT Staff.StaffID FROM Staff
	JOIN HeaderSalesTransaction
	ON Staff.StaffID = HeaderSalesTransaction.StaffID
	WHERE CustomerID LIKE 'CU006'
);