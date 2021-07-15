-- Kelompok 11
-- Glenn Karjadidjaja (2301850645)
-- Andre Setiawan Wijaya (2301852695)
-- Philip Indra Prayitno (2301856125)
-- Sendiawan (2301862733)

CREATE DATABASE cateringDelViaDB;
USE cateringDelViaDB;

INSERT INTO Customer VALUES	('CU001','Glenn Karjadidjaja','081234567898','Jalan Hiburan No.10','Male','glenn.karjadidjaja@yahoo.com'),
							('CU002','Philip Indra','084578451369','Jalan Impian No.1','Male','philip@gmail.com'),
							('CU003','Sendiawan','084575231954','Jalan Mangga No.4','Male','sendiawan@yahoo.co.id'),
							('CU004','Andre Setiawan','083324517530','Jalan Anggur No.55','Male','andre.setiawan@yahoo.com'),
							('CU005','Jurike Monic','084412501212','Jalan Apel No.30','Female','monic.jurike@gmail.com'),
							('CU006','Siti Badriah','085698324519','Jalan Belimbing No.7','Female','sitidriah@yahoo.com'),
							('CU007','Edi Purnama','085216478536','Jalan Kenangan No.13','Male','purnam.edi@gmail.com'),
							('CU008','Gisella Anastasia','084512369874','Jalan Pisang No.19','Female','gisel.la@yahoo.co.id'),
							('CU009','Eko Cahyadi','083214570032','Jalan Kinclong No.22','Male','cahya.eko@yahoo.com'),
							('CU010','Felicia Christian','083215003445','Jalan Bunga No.27','Female','feli.cia@gmail.com');
--SELECT * FROM Customer;

INSERT INTO StaffPosition VALUES	('SP001','CEO'),
							('SP002','Secretary'),
							('SP003','Treasurer'),
							('SP004','Promotion'),
							('SP005','Marketing'),
							('SP006','Inventory Manager'),
							('SP007','Head Chef'),
							('SP008','Chef'),
							('SP009','Supervisor'),
							('SP010','Cashier');
--SELECT * FROM StaffPosition;

INSERT INTO Staff VALUES	('ST001','SP010','Bimo Mobi','Male','bimo@yahoo.com','0845124787319','Jalan Kembang No.5',1000000),
							('ST002','SP001','Harianto Prabowo','Male','hari.prabowo@yahoo.co.id','081456984123','Jalan Manggis No.15',5000000),
							('ST003','SP002','Yulianti Tian','Female','yuli.anti@gmail.com','081245324178','Jalan Sepatu No.54',2500000),
							('ST004','SP003','Sri Mulyani','Female','srimul@yahoo.com','084201654503','Jalan Kuning No.20',3500000),
							('ST005','SP004','Karin Novilda','Female','awkarin@gmail.com','081247875036','Jalan Bambu No.25',1500000),
							('ST006','SP006','Prabowo Sabianto','Male','prabowoS@yahoo.co.id','081425680412','Jalan Pertahanan No.12',4000000),
							('ST007','SP005','Nadim Makaram','Male','nadim.makaram@yahoo.com','085214784230','Jalan Pendidikan No.43',3500000),
							('ST008','SP008','Arnold Purnama','Male','chef.arnold@gmail.com','082147851300','Jalan Kemuning No.28',1000000),
							('ST009','SP009','Renatta Moeloek','Female','renatta.moel@yahoo.co.id','087512470023','Jalan Kemangi No.31',1500000),
							('ST010','SP007','Juna Rorimpandey','Male','chef.juna@yahoo.com','081241030405','Jalan Bunga No.41',2000000),
							('ST011','SP010','Maudy Ayunda','Female','ayunda.maudy@gmail.com','081547894563','Jalan Banyu Biru No.37', 1500000);
--SELECT * FROM Staff;

INSERT INTO Vendor VALUES	('VE001','PT.Farmer Market','081245697412','Jalan Kelapa Gading No.1'),
							('VE002','PT.Ternak Ayam','081512470120','Jalan Peternakan No.13'),
							('VE003','PT.Cabai Merah','085741023641','Jalan Keriting No.10'),
							('VE004','PT.Kerupuk Merah','085912451102','Jalan Kaleng No.15'),
							('VE005','PT.Pasar Mandiri','081742365411','Jalan Sumagung No.3'),
							('VE006','PT.Pasar Inpres','081871235474','Jalan Dalam No.11'),
							('VE007','PT.Akua','085474126985','Jalan Pegunungan No.19'),
							('VE008','PT.Moonlight','08147586521','Jalan Lemon No.12'),
							('VE009','PT.Diamond','081147544512','Jalan Artha Gading No.50'),
							('VE010','PT.Carrefour','085410360025','Jalan Pramuka No.34');
--SELECT * FROM Vendor;

INSERT INTO Menu VALUES	('ME001','Nasi Goreng','Nasi digoreng dengan isi ayam, sayur, dan telur.',25000),
						('ME002','Mie Goreng','Mie digoreng dengan isi ayam, sayur, dan telur.',25000),
						('ME003','Mie Kuah','Mie direbus dengan isi ayam, sayur, dan telur.',20000),
						('ME004','Ayam Bakar','Ayam dibakar dengan bumbu kecap.',15000),
						('ME005','Soto Betawi','Soto dengan kuah santan dan daging sapi.',30000),
						('ME006','Soto Mie','Soto dengan mie kuning ato bihun, risoles, dan daging sapi.',7500),
						('ME007','Sop Iga Sapi','Sop iga sapi dengan sayur.',60000),
						('ME008','Iga Sapi Sambal Matah','Iga sapi dibakar dengan bumbu sambal matah.',65000),
						('ME009','Bubur Ayam','Bubur dengan ayam,cakue,kacang,bawang goreng, dan kerupuk',30000),
						('ME010','Ayam Goreng Sambal Ijo','Ayam digoreng disajikan dengan sambal ijo',25000),
						('ME011','Nasi Kucing Peda','Nasi kucing isi ikan peda dan sambal',12000),
						('ME012','Nasi Kucing Ayam','Nasi kucing isi ayam dan sambal',12000),
						('ME013','Nasi Kucing Kerang','Nasi kucing isi kerang dan sambal',12000),
						('ME014','Martabak Telur 1','Martabak isi daging sapi dan 1 telur bebek',30000),
						('ME015','Martabak Telur 2','Martabak isi daging sapi dan 2 telur bebek',40000),
						('ME016','Martabak Telur 3','Martabak isi daging sapi dan 3 telur bebek',50000),
						('ME017','Martabak Telur 4','Martabak isi daging sapi dan 4 telur bebek',60000),
						('ME018','Es Jeruk Murni','Jeruk peras tanpa gula',15000),
						('ME019','Teh Tawar','Teh hangat tawar',5000),
						('ME020','Es Teh Tawar','Teh tawar dengan es',5500),
						('ME021','Teh Manis','Teh hangat manis',6000),
						('ME022','Es Teh Manis','Teh manis dengan es',6500),
						('ME023','Kopi Susu','Kopi hitam dengan susu',10000),
						('ME024','Es Kopi Susu','Kopi hitam dengan susu menggunakan es',10500),
						('ME025','Kopi Hitam','Kopi hitam panas',7000);
--SELECT * FROM Menu;

INSERT INTO Ingredient VALUES	('ID001','Telur',100,26000),
								('ID002','Daging Sapi',60,80000),
								('ID003','Sayur Kol',200,15000),
								('ID004','Daging Ayam',150,60000),
								('ID005','Mie Kuning',300,20000),
								('ID006','Bihun',300,20000),
								('ID007','Garam',500,30000),
								('ID008','Bawang',200,40000),
								('ID009','MSG',500,50000),
								('ID010','Cabai',1000,90000);
--SELECT * FROM Ingredient;

INSERT INTO ServicesTransaction VALUES	('TR001','ST001','CU002','2020-06-13','Guaranteed','Jalan Gitar No.32'),
									('TR002','ST011','CU003','2020-07-10','Guaranteed','Jalan Gitar No.32'),
									('TR003','ST001','CU001','2020-07-25','Non-Guaranteed','Jalan Gitar No.32'),
									('TR004','ST011','CU005','2020-08-01','Guaranteed','Jalan Musik No.16'),
									('TR005','ST011','CU004','2020-08-15','Guaranteed','Jalan Musik No.16'),
									('TR006','ST001','CU006','2020-08-13','Non-Guaranteed','Jalan Musik No.16'),
									('TR007','ST001','CU008','2020-09-22','Non-Guaranteed','Jalan Baru No.19'),
									('TR008','ST011','CU007','2020-09-28','Non-Guaranteed','Jalan Baru No.19'),
									('TR009','ST001','CU009','2020-10-10','Guaranteed','Jalan Baru No.19'),
									('TR010','ST011','CU010','2020-11-21','Guaranteed','Jalan Baru No.19'),
									('TR011','ST001','CU001','2020-11-22','Non-Guaranteed','Jalan Musik No.16'),
									('TR012','ST011','CU003','2020-11-23','Non-Guaranteed','Jalan Musik No.16'),
									('TR013','ST001','CU005','2020-11-27','Guaranteed','Jalan Gitar No.32'),
									('TR014','ST011','CU002','2020-11-28','Non-Guaranteed','Jalan Baru No.19'),
									('TR015','ST011','CU007','2020-11-29','Guaranteed','Jalan Gitar No.32');
--SELECT * FROM ServicesTransaction;

INSERT INTO TransactionDetail VALUES	('TR001','ME001',19),
										('TR001','ME002',28),
										('TR001','ME003',24),
										('TR002','ME004',1000),
										('TR002','ME015',24),
										('TR002','ME020',36),
										('TR003','ME007',25),
										('TR003','ME008',25),
										('TR004','ME014',55),
										('TR004','ME005',13),
										('TR004','ME007',300),
										('TR005','ME012',17),
										('TR005','ME004',44),
										('TR006','ME001',14),
										('TR006','ME015',23),
										('TR007','ME008',35),
										('TR007','ME001',22),
										('TR007','ME019',70),
										('TR008','ME015',3),
										('TR008','ME020',28),
										('TR009','ME011',102),
										('TR010','ME016',29),
										('TR010','ME013',14),
										('TR011','ME017',25),
										('TR011','ME025',51),
										('TR012','ME002',31),
										('TR012','ME005',12),
										('TR013','ME010',504),
										('TR013','ME025',28),
										('TR014','ME007',15),
										('TR014','ME008',19),
										('TR015','ME011',47);
--SELECT * FROM TransactionDetail;

INSERT INTO Purchase VALUES	('PU001','ST006','VE001','2020-05-30'),
							('PU002','ST006','VE002','2020-05-30'),
							('PU003','ST006','VE003','2020-05-30'),
							('PU004','ST006','VE004','2020-05-30'),
							('PU005','ST006','VE005','2020-05-31'),
							('PU006','ST006','VE006','2020-05-31'),
							('PU007','ST006','VE007','2020-05-31'),
							('PU008','ST006','VE008','2020-06-01'),
							('PU009','ST006','VE009','2020-06-01'),
							('PU010','ST006','VE010','2020-06-02');
--SELECT * FROM Purchase;

INSERT INTO PurchaseDetail VALUES	('PU001','ID001',100),
									('PU001','ID002',60),
									('PU001','ID003',76),
									('PU002','ID002',160),
									('PU002','ID004',210),
									('PU002','ID005',390),
									('PU003','ID003',200),
									('PU003','ID005',240),
									('PU003','ID007',490),
									('PU004','ID004',170),
									('PU004','ID008',280),
									('PU004','ID010',110),
									('PU005','ID005',300),
									('PU005','ID001',90),
									('PU006','ID006',300),
									('PU006','ID010',250),
									('PU006','ID007',500),
									('PU007','ID001',220),
									('PU007','ID004',270),
									('PU007','ID006',430),
									('PU007','ID009',680),
									('PU008','ID008',700),
									('PU008','ID002',620),
									('PU008','ID005',260),
									('PU009','ID003',3500),
									('PU009','ID008',250),
									('PU010','ID006',1500),
									('PU010','ID010',1000);
--SELECT * FROM PurchaseDetail;
