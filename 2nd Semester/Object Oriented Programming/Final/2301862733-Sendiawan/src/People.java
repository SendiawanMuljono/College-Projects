
public abstract class People {
	private String id;
	private String name;
	private int age;
	private String gender;
	private int currTime;
	
	int getCurrTime() {
		return currTime;
	}

	void setCurrTime(int currTime) {
		this.currTime += currTime;
	}

	String getId() {
		return id;
	}

	String getName() {
		return name;
	}

	void setName(String name) {
		this.name = name;
	}

	int getAge() {
		return age;
	}

	void setAge(int age) {
		this.age = age;
	}

	String getGender() {
		return gender;
	}

	void setGender(String gender) {
		this.gender = gender;
	}

	public People(String id, String name, int age, String gender) {
		super();
		this.id = id;
		this.name = name;
		this.age = age;
		this.gender = gender;
		this.currTime = 0;
	}

	public People() {
		// TODO Auto-generated constructor stub
	}
	
	public abstract void print();

}
