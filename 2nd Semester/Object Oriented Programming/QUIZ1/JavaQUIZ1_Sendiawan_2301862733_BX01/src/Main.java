import java.util.Scanner;
import java.util.Vector;

public class Main {
	Scanner sc = new Scanner(System.in);
	Vector<Catalogue> product = new Vector<>();
	
	public Main() {
		int choose=0;
		do {
			menu();
			try {
				choose = sc.nextInt();
			} catch (Exception e) {
				System.out.println("Input must be numeric");
				choose = 0;
			}
			sc.nextLine();
			if(choose == 1) {
				header(choose);
				if(product.isEmpty()) {
					System.out.println("Nothing to display here");
					pressEnter();
				}
				else {
					pilihan(choose);
				}
				choose = 0;
			}
			else if(choose == 2) {
				header(choose);
				if(product.isEmpty()) {
					System.out.println("No clothes on our store right now");
					pressEnter();
				}
				else {
					pilihan(choose);
				}
				choose = 0;
			}
			else if(choose == 3) {
				pilihan(choose);
				choose = 0;
			}
			else if(choose == 4) {
				pilihan(choose);
			}
		}while(choose<1||choose>4);
	}

	public static void main(String[] args) {
		new Main();
	}
	
	public void menu() {
		System.out.println("~.~.~.~.~.~.~.~.~.~.~.~.~.~.~");
		System.out.println("Welcome to FashionNova Store");
		System.out.println("~.~.~.~.~.~.~.~.~.~.~.~.~.~.~");
		System.out.println("1. View Catalogue");
		System.out.println("2. Sell Product");
		System.out.println("3. Add Product to Catalogue");
		System.out.println("4. Exit");
		System.out.print(">> ");
	}
	
	public void pilihan(int choose) {
		if(choose == 1) {
			for (int i = 0; i < product.size(); i++) {
				Catalogue a = product.get(i);
				System.out.println("Cloth(ID-Name) : "+a.getClothID()+"-"+a.getClothName());
				System.out.println("Details:");
				System.out.println("- Material : "+a.getClothMat());
				System.out.println("- Stock : "+a.getStock());
				System.out.println("- Price(per pcs) : " + a.getClothPrice());
				System.out.println();
				System.out.println();
			}
			pressEnter();
		}
		else if(choose == 2) {
			Catalogue a = null;
			int id = 0,exist = 0,quan=0,index = 0;
			do {
				System.out.print("Cloth to buy (ClothId) : ");
				try {
					id = sc.nextInt();
				} catch (Exception e) {
					System.out.println("ClothId must be numeric");
					exist = 0;
				}
				sc.nextLine();
				for (int i = 0; i < product.size(); i++) {
					a = product.get(i);
					if(a.getClothID().equals(id)) {
						exist = 1;
						index = i;
						break;
					}
				}
			}while(exist!=1);
			do {
				System.out.printf("Quantity[1-%d] : ",a.getStock());
				try {
					quan = sc.nextInt();
				} catch (Exception e) {
					System.out.println("Quantity must be numeric");
					quan = 0;
				}
				sc.nextLine();
			}while(quan<1||quan>a.getStock());
			int price = a.getClothPrice()*quan;
			int tax = (price*10)/100;
			int totalPrice = price + tax;
			a.setStock(a.getStock()-quan);
			System.out.println();
			System.out.println("Price          : " + price);
			System.out.println("tax            : " + tax);
			System.out.println("TotalPrice     : " + totalPrice);
			System.out.println();
			System.out.println(quan+" item(s) of "+a.getClothName()+" sold successfully!");
			//cek kalau stock habis
			if(a.getStock()==0) {
				product.remove(index);
			}
			pressEnter();
		}
		else if(choose == 3) {
			Integer clothID,clothPrice,stock;
			String clothName,clothMat;
			//ClothID
			do {
				System.out.print("input ClothId [must be unique & is numeric(1-100)]: ");
				try {
					clothID = sc.nextInt();
				} catch (Exception e) {
					System.out.println("ClothId must be numeric");
					clothID = 0;
				}
				sc.nextLine();
				//Cek clothID sdh ada atau blm
				for (int i = 0; i < product.size(); i++) {
					Catalogue a = product.get(i);
					if(a.getClothID().equals(clothID)) {
						clothID = 0;
						break;
					}
				}
			}while(clothID<1||clothID>100);
			//ClothName			
			do {
				System.out.print("input ClothName [5-25 characters]: ");
				clothName = sc.nextLine();
			}while(clothName.length()<5||clothName.length()>25);
			//ClothMaterial
			do {
				System.out.print("input ClothMaterial [cotton|silk, case sensitive]: ");
				clothMat = sc.nextLine();
			}while(!clothMat.equals("cotton")&&!clothMat.equals("silk"));
			//Stock
			do {
				System.out.print("input stock [5-50]: ");
				try {
					stock = sc.nextInt();
				} catch (Exception e) {
					System.out.println("Stock must be numeric");
					stock = 0;
				}
				sc.nextLine();
			}while(stock<5||stock>50);
			//Price
			do {
				System.out.print("input price [min. 100000]: ");
				try {
					clothPrice = sc.nextInt();
				} catch (Exception e) {
					System.out.println("Cloth price must be numeric");
					clothPrice = 0;
				}
				sc.nextLine();
			}while(clothPrice<100000);
			product.add(new Catalogue(clothID, clothName, clothMat, stock, clothPrice));
			System.out.println("Cloth successfully added!");
			pressEnter();
		}
		else if(choose == 4) {
			System.out.println("Thank you for using FashionNova program!");
		}
	}
	
	public void header(int choose) {
		if(choose == 1) {			
			System.out.println("~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~");
			System.out.println("FashionNova Catalogue");
			System.out.println("~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~");
		}
		else if(choose == 2) {
			System.out.println("~.~.~.~.~.~.~.~.~.~.~.~.~.~.~");
			System.out.println("Shopping Cart");
			System.out.println("~.~.~.~.~.~.~.~.~.~.~.~.~.~.~");
		}
	}
	
	public void pressEnter() {
		System.out.println("press Enter to continue...");
		sc.nextLine();
	}
}
