import java.util.Random;
import java.util.Vector;

public class Customer extends People {
	Random rand = new Random();
	Vector<Menu> listOrder = new Vector<>();

	public Customer(String id, String name, int age, String gender) {
		super(id, name, age, gender);
	}
	
	public Customer() {
		// TODO Auto-generated constructor stub
	}

	@Override
	public void print() {
		int price = 0;
		System.out.println("Name    : " + getName());
		System.out.println("Age     : " + getAge());
		System.out.println("Gender  : " + getGender());
		System.out.println();
		System.out.println("Menu details");
		System.out.println("=====================================");
		for (int i = 0; i < this.listOrder.size(); i++) {
			System.out.println(listOrder.get(i).getMenuId());
			System.out.println("- "+listOrder.get(i).getMenuName());
			price+=listOrder.get(i).getMenuPrice();
		}
		System.out.println();
		System.out.println("Total Price: " + price);
		System.out.println();
		System.out.println("-------------------------------------");
	}

}
