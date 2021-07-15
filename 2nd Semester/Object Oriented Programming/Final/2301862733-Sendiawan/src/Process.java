import java.util.Random;
import java.util.UUID;
import java.util.Vector;

public class Process extends Thread{
	Random rand = new Random();
	Vector<Menu> menu = new Vector<>();
	Vector<Menu> queueMenu = new Vector<>();
	Vector<People> chef = new Vector<>(); 
	Vector<People> customer = new Vector<>(); 
	Vector<People> custHistory = new Vector<>(); 
	
	private int gold = 10000;
	private boolean run = true;

	int getGold() {
		return gold;
	}

	void setGold(int gold) {
		this.gold = gold;
	}

	public Process() {
		// TODO Auto-generated constructor stub
	}
	
	public void gas(int choose) {
		Thread t1 = new Thread(new Runnable() {
			
			@Override
			public void run() {
				while(run) {
					if(choose == 4) {
						run = false;
					}
					for (int i = 0; i < chef.size(); i++) {
						int cookMenu = rand.nextInt(10);
						if(((Chef)chef.get(i)).isProfessional()) {
							try {
								Thread.sleep(1000);
							} catch (InterruptedException e) {
								
							}
							chef.get(i).setCurrTime(1);
							queueMenu.add(menu.get(cookMenu));
						}
						else {
							try {
								Thread.sleep(2000);
							} catch (InterruptedException e) {
								
							}
							chef.get(i).setCurrTime(2);
							queueMenu.add(menu.get(cookMenu));
						}
						if(chef.get(i).getCurrTime() % 120 == 0) {//2 menit
							setGold(getGold()-((Chef)chef.get(i)).getSalary());
						}
					}
				}
			}
		});
		
		Thread t2 = new Thread(new Runnable() {
			
			@Override
			public void run() {
				int pay,num=0;
				while(run) {
					if(choose == 4) {
						run = false;
					}
					pay = 0;
					if(customer.size()<5) {
						Customer cust = new Customer();
						num++;
						String ID = UUID.randomUUID().toString();
						cust.setName("Customer "+ num);
						cust.setAge(rand.nextInt(36)+15);//umur 15-50
						int gender = rand.nextInt(2);
						if(gender == 1) {
							cust.setGender("Male");
						}
						else {
							cust.setGender("Female");
						}
						customer.add(new Customer(ID, cust.getName(), cust.getAge(), cust.getGender()));
					}
					if(!queueMenu.isEmpty()) {
						for (int i = 0; i < customer.size(); i++) {
							int indexMenu = rand.nextInt(queueMenu.size());
							try {
								Thread.sleep(4000);
							} catch (InterruptedException e) {
								
							}
							Menu a = queueMenu.get(indexMenu);
							((Customer)customer.get(i)).listOrder.add(new Menu(a.getMenuId(), a.getMenuName(), a.getMenuPrice()));
							queueMenu.remove(indexMenu);
							int leave = rand.nextInt(10);
							if(leave == 1) {//10% chance
								for (int j = 0; j < ((Customer)customer.get(i)).listOrder.size(); j++) {
									pay+=((Customer)customer.get(i)).listOrder.get(j).getMenuPrice();
								}
								custHistory.add(customer.get(i));
								setGold(getGold()+pay);
								customer.remove(i);
							}
						}
					}
				}
			}
		});
		t1.start();
		t2.start();
	}
}
