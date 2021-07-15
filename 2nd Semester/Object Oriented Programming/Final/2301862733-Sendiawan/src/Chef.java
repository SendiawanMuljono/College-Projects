
public class Chef extends People{
	private String username;
	private int salary;
	private boolean professional;
	
	String getUsername() {
		return username;
	}

	int getSalary() {
		return salary;
	}

	boolean isProfessional() {
		return professional;
	}

	public Chef(String id, String name, int age, String gender, String username, int salary, boolean professional) {
		super(id, name, age, gender);
		this.username = username;
		this.salary = salary;
		this.professional = professional;
	}

	public Chef() {
		// TODO Auto-generated constructor stub
	}

	@Override
	public void print() {
		System.out.println(getId());
		System.out.println("=====================================");
		System.out.println("Name     : "+getName());
		System.out.println("Username : "+getUsername());
		System.out.println("Age      : "+getAge());
		System.out.println("Gender   : "+getGender());
	}

}
