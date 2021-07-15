
public class Menu {
	String[] name = new String[] {"Kimchi Jjigae","Jjinmandu","Daeji Bulgogi","Gogigui","Haejangguk","Sundubu Jjigae","Saengseon Jjigae","Nakji Bokkeum", "Seolleongtang", "Dolsot Bibimbap"};
	private String menuId;
	private String menuName;
	private int menuPrice;
	
	String getMenuId() {
		return menuId;
	}

	String getMenuName() {
		return menuName;
	}

	int getMenuPrice() {
		return menuPrice;
	}

	public Menu(String menuId, String menuName, int menuPrice) {
		super();
		this.menuId = menuId;
		this.menuName = menuName;
		this.menuPrice = menuPrice;
	}

	public Menu() {
		// TODO Auto-generated constructor stub
	}

}
