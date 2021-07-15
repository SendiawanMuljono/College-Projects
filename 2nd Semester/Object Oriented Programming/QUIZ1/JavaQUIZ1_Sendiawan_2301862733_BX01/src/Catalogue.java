
public class Catalogue {
	private Integer clothID;
	private String clothName;
	private String clothMat;
	private Integer stock;
	private Integer clothPrice;
	
	public Catalogue(Integer clothID, String clothName, String clothMat, Integer stock, Integer clothPrice) {
		super();
		this.clothID = clothID;
		this.clothName = clothName;
		this.clothMat = clothMat;
		this.stock = stock;
		this.clothPrice = clothPrice;
	}
	
	public Integer getClothID() {
		return clothID;
	}

	public void setClothID(Integer clothID) {
		this.clothID = clothID;
	}

	public String getClothName() {
		return clothName;
	}

	public void setClothName(String clothName) {
		this.clothName = clothName;
	}

	public String getClothMat() {
		return clothMat;
	}

	public void setClothMat(String clothMat) {
		this.clothMat = clothMat;
	}

	public Integer getStock() {
		return stock;
	}

	public void setStock(Integer stock) {
		this.stock = stock;
	}

	public Integer getClothPrice() {
		return clothPrice;
	}

	public void setClothPrice(Integer clothPrice) {
		this.clothPrice = clothPrice;
	}

	
	public Catalogue() {
	}

}
