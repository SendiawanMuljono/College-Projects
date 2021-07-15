import java.util.Random;
import java.util.Scanner;
import java.util.UUID;
import java.util.Vector;


public class Main {
	Vector<Integer> adwa = new Vector<>();
	Scanner sc = new Scanner(System.in);
	Random rand = new Random();
	Process process = new Process();
	public Main() {
		Menu menu = new Menu();
		//initial process - start (1 chef, 10 menu)
		for (int i = 0; i < 10; i++) {
			String a = UUID.randomUUID().toString();
			String b = menu.name[i];
			int price = rand.nextInt(501) + 500;
			process.menu.add(new Menu(a, b, price));
		}
		String a = UUID.randomUUID().toString();
		process.chef.add(new Chef(a, "Park Sae royi", 33, "Male", "saeroyi", 3000, true));
		//initial process - end
		process.gas(0);
		
		menu();
	}

	public static void main(String[] args) {
		new Main();
	}
	
	public void menu() {
		int choose = 0;
		do {
			System.out.println("Danbam");
			System.out.println("Total money: "+process.getGold());
			System.out.println("1. Add danbam's chef");
			System.out.println("2. View danbam's information");
			System.out.println("3. View customers in danbam");
			System.out.println("4. Quit");
			do {
				System.out.print(">> ");
				try {
					choose = sc.nextInt();
				} catch (Exception e) {
				
				}
				sc.nextLine();
			}while(choose<1||choose>4);
			if(choose == 1) {
				String name, username, gender;
				int age=0;
				do {
					System.out.print("Chef's name [must contain 3 words] >> ");
					name = sc.nextLine();
				}while(name.split(" ").length<3||name.split(" ").length>3);
				int invalid;
				do {
					invalid = 0;
					System.out.print("Chef's username [must be unique] >> ");
					username = sc.nextLine();
					for (int i = 0; i < process.chef.size(); i++) {
						if(process.chef.get(i) instanceof Chef) {
							if(((Chef)process.chef.get(i)).getUsername().equalsIgnoreCase(username)) {
								invalid = 1;
								break;
							}
						}
					}
				}while(invalid == 1);
				do {
					System.out.print("Chef's gender [Female | Male] (Case Sensitive) >> ");
					gender = sc.nextLine();
				}while(!gender.equals("Female") && !gender.equals("Male"));
				do {
					System.out.print("Chef's age [17-40] >> ");
					try {
						age = sc.nextInt();
					} catch (Exception e) {

					}
					sc.nextLine();
				}while(age<17||age>40);
				String ID = UUID.randomUUID().toString();
				int random = rand.nextInt(2);
				boolean pro = false;
				if(random == 1) {
					pro = true;
				}
				process.chef.add(new Chef(ID, name, age, gender, username, 3000, pro));
				System.out.println("\nChef has been successfully added!\n");
				choose = 0;
			}
			else if(choose == 2) {
				int choose2=0;
				do {
					System.out.println("1. View all chefs");
					System.out.println("2. View customer with history order");
					System.out.println("3. Exit");
					do {
						System.out.print(">> ");
						try {
							choose2 = sc.nextInt();
						} catch (Exception e) {
							
						}
						sc.nextLine();
					}while(choose2<1||choose2>3);
					if(choose2 == 1) {
						System.out.println();
						for (int j = 0; j < process.chef.size(); j++) {
							process.chef.get(j).print();
							System.out.println();
						}
						sc.nextLine();
					}
					else if(choose2 == 2) {
						System.out.println();
						if(process.custHistory.isEmpty()) {
							System.out.println("There are no customers with order yet! :(");
							System.out.println();
						}
						else {
							for (int i = 0; i < process.custHistory.size(); i++) {
								process.custHistory.get(i).print();
								System.out.println();
							}
							sc.nextLine();
						}
					}
				}while(choose2<1||choose2>3);
				choose = 0;
			}
			else if (choose == 3) {
				System.out.println();
				System.out.println("Customer in DanBam now");
				System.out.println("======================");
				for (int i = 0; i < process.customer.size(); i++) {
					System.out.println("- "+process.customer.get(i).getName());
				}
				System.out.println();
				choose = 0;
			}
			else if(choose == 4) {
				process.gas(4);
			}
		}while(choose<1||choose>4);
	}

}
