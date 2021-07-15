-- Kelompok 11
-- Glenn Karjadidjaja (2301850645)
-- Andre Setiawan Wijaya (2301852695)
-- Philip Indra Prayitno (2301856125)
-- Sendiawan (2301862733)

CREATE DATABASE cateringDelViaDB;
USE cateringDelViaDB;

CREATE TABLE Customer(
CustomerID CHAR(5) PRIMARY KEY NOT NULL,
CustomerName VARCHAR(255) NOT NULL,
CustomerPhoneNumber VARCHAR(20) NOT NULL,
CustomerAddress VARCHAR(255) NOT NULL,
CustomerGender CHAR(6) NOT NULL,
CustomerEmail VARCHAR(75) NOT NULL,
CHECK (CustomerID LIKE 'CU[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
CHECK (CustomerEmail LIKE '%@gmail.com' OR CustomerEmail LIKE '%@yahoo.com' OR CustomerEmail LIKE '%@yahoo.co.id'),
CHECK (TRIM(CustomerEmail) NOT LIKE '@%'),
CHECK (ISNUMERIC(CustomerPhoneNumber) = 1 AND CustomerPhoneNumber LIKE '08%')
);

CREATE TABLE StaffPosition(
PositionID CHAR(5) PRIMARY KEY NOT NULL,
PositionName VARCHAR(255) NOT NULL,
CHECK (PositionID LIKE 'SP[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS)
);

CREATE TABLE Staff(
StaffID CHAR(5) PRIMARY KEY NOT NULL,
PositionID CHAR(5) FOREIGN KEY REFERENCES StaffPosition(PositionID) NOT NULL,
StaffName VARCHAR(255) NOT NULL,
StaffGender CHAR(6) NOT NULL,
StaffEmail VARCHAR(75) NOT NULL,
StaffPhoneNumber VARCHAR(20) NOT NULL,
StaffAddress VARCHAR(255) NOT NULL,
StaffSalary BIGINT NOT NULL,
CHECK (StaffID LIKE 'ST[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
CHECK (PositionID LIKE 'SP[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
CHECK (StaffEmail LIKE '%@gmail.com' OR StaffEmail LIKE '%@yahoo.com' OR StaffEmail LIKE '%@yahoo.co.id'),
CHECK (TRIM(StaffEmail) NOT LIKE '@%'),
CHECK (ISNUMERIC(StaffPhoneNumber) = 1 AND StaffPhoneNumber LIKE '08%'),
CHECK (StaffSalary BETWEEN 500000 AND 5000000)
);

CREATE TABLE Vendor(
VendorID CHAR(5) PRIMARY KEY NOT NULL,
VendorName VARCHAR(255) NOT NULL,
VendorPhoneNumber VARCHAR(20) NOT NULL,
VendorAddress VARCHAR(255) NOT NULL,
CHECK (VendorID LIKE 'VE[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
CHECK (VendorName LIKE 'PT.%' COLLATE Latin1_General_CS_AS)
);

CREATE TABLE Menu(
MenuID CHAR(5) PRIMARY KEY NOT NULL,
MenuName VARCHAR(255) NOT NULL,
MenuDescription VARCHAR(255) NOT NULL,
MenuPrice BIGINT NOT NULL,
CHECK (MenuID LIKE 'ME[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
CHECK(LEN(MenuName) > 5)
);

CREATE TABLE Ingredient(
IngredientID CHAR(5) PRIMARY KEY NOT NULL,
IngredientName VARCHAR(255) NOT NULL,
IngredientStock BIGINT NOT NULL,
IngredientPrice BIGINT NOT NULL,
CHECK (IngredientID LIKE 'ID[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS)
);

CREATE TABLE ServicesTransaction(
TransactionID CHAR(5) PRIMARY KEY NOT NULL,
StaffID CHAR(5) FOREIGN KEY REFERENCES Staff(StaffID) NOT NULL,
CustomerID CHAR(5) FOREIGN KEY REFERENCES Customer(CustomerID) NOT NULL,
TransactionDate DATE NOT NULL,
ReservationType VARCHAR(255) NOT NULL,
ReservationAddress VARCHAR(255) NOT NULL,
CHECK (TransactionID LIKE 'TR[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
CHECK (CustomerID LIKE 'CU[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
CHECK (StaffID LIKE 'ST[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
);

CREATE TABLE TransactionDetail( 
TransactionID CHAR(5) FOREIGN KEY REFERENCES ServicesTransaction(TransactionID) NOT NULL,
MenuID CHAR(5) FOREIGN KEY REFERENCES Menu(MenuID) NOT NULL,
MenuPax BIGINT NOT NULL,
PRIMARY KEY(TransactionID, MenuID),
CHECK (TransactionID LIKE 'TR[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
CHECK (MenuID LIKE 'ME[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
);

CREATE TABLE Purchase(
PurchaseID CHAR(5) PRIMARY KEY NOT NULL,
StaffID CHAR(5) FOREIGN KEY REFERENCES Staff(StaffID) NOT NULL,
VendorID CHAR(5) FOREIGN KEY REFERENCES Vendor(VendorID) NOT NULL,
PurchaseDate DATE NOT NULL,
CHECK (PurchaseID LIKE 'PU[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
CHECK (StaffID LIKE 'ST[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
CHECK (VendorID LIKE 'VE[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
);

CREATE TABLE PurchaseDetail( 
PurchaseID CHAR(5) FOREIGN KEY REFERENCES [Purchase](PurchaseID) NOT NULL,
IngredientID CHAR(5) FOREIGN KEY REFERENCES Ingredient(IngredientID) NOT NULL,
IngredientQuantity BIGINT NOT NULL,
PRIMARY KEY(PurchaseID, IngredientID),
CHECK (PurchaseID LIKE 'PU[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
CHECK (IngredientID LIKE 'ID[0-9][0-9][0-9]' COLLATE Latin1_General_CS_AS),
);