-- Kelompok 11
-- Glenn Karjadidjaja (2301850645)
-- Andre Setiawan Wijaya (2301852695)
-- Philip Indra Prayitno (2301856125)
-- Sendiawan (2301862733)

CREATE DATABASE cateringDelViaDB;
USE cateringDelViaDB;

--Services
--Customer bernama Yanto Suryono berjenis kelamin laki-laki
--Dengan customer ID CU011 dan nomor telepon 081222223333
--Alamat di Jalan Pisang Kuning No.2, dengan email yanto.suryono@gmail.com
--Melakukan transaksi pembelian makanan dengan ID Transaksi TR016 untuk pesta ulang tahun anaknya
INSERT INTO Customer VALUES	('CU011', 'Yanto Suryono', '081222223333', 'Jalan Pisang Kuning No.2', 'Male', 'yanto.suryono@gmail.com')

--Transaksi tersebut ditangani oleh staff bernama Maudy Ayunda
--Berjenis kelamin perempuan, dengan staff ID ST011,
--Dengan posisi Cashier, dengan nomor telepon 081547894563,
--Alamat di Jalan Banyu Biru No.37, dengan email ayunda.maudy@gmail.com
SELECT * FROM Staff
WHERE StaffID = 'ST011'

--Dalam transaksi tersebut, Yanto Suryono membeli 100pcs Martabak Telur, dengan MenuID ME015,
--Transaksi tersebut terjadi pada tanggal 2 bulan Desember tahun 2020
INSERT INTO ServicesTransaction VALUES ('TR016', 'ST011', 'CU011', '2020-12-2', 'Guaranteed', 'Jalan Gitar No.32')
INSERT INTO TransactionDetail VALUES ('TR016', 'ME015', 100)

--Karena Yanto Suryono khawatir akan banyaknya orang yang akan datang, jadi ia menambah pesanan martabak telurnya menjadi 125
UPDATE TransactionDetail
SET MenuPax = 3
WHERE TransactionID = 'TR016'
	  AND MenuID = 'ME015'

--Purchase
--Pembelian bahan baku dengan vendor bernama PT. Ortu yang memiliki VendorID VE011, 
--Dengan nomor telepon 083444445555 dan beralamat di Jalan Buah Delima No.2
INSERT INTO Vendor VALUES ('VE011', 'PT.Ortu', '083444445555', 'Jalan Buah Delima No.2')

--Pembelian tersebut ditangani oleh staff bernama Prabowo Subianto
--Berjenis kelamin laki-laki, yang memiliki staff ID ST006,
--Dengan posisi Inventory Manager, nomor telepon 081425680412, dan email prabowoS@yahoo.co.id,
--Serta beralamat di Jalan Pertahanan No.12
SELECT * FROM Staff
WHERE StaffID = 'ST006'

--Transaksi tersebut memiliki id PurchaseID PU011,
--Pembelian tersebut terjadi pada tanggal 3 bulan Desember tahun 2020
--Catering delVia membeli bahan baku Anggur, dengan ingredientID ID011,
--Dengan pembelian sebanyak 500
INSERT INTO Ingredient VALUES ('ID011', 'Anggur', 500, 30000)
INSERT INTO Purchase VALUES	('PU011', 'ST006', 'VE011', '2020-12-3')
INSERT INTO PurchaseDetail VALUES ('PU011', 'ID011', 500)

--Karena sekarang cuaca sedang tidak menentu jadi PT.Ortu 
--Menaikan harga anggur menjadi 50000
UPDATE Ingredient
SET IngredientPrice = 50000
WHERE IngredientID = 'ID011'

--Karena terjadi ketidak sepakatan harga dipertengahan jalan
--Maka terjadi pembatalan 
DELETE FROM PurchaseDetail
WHERE PurchaseID = 'PU011'

DELETE FROM Purchase
WHERE PurchaseID = 'PU011'