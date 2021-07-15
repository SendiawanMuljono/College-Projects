import java.util.Random;
import java.util.Vector;

public class Player {
	Random rand = new Random();
	Vector<Player> data = new Vector<>();
	
	private int dadu;
	private int stepAwal;
	private int step;
	private String name;
	

	public Player(int step, String name) {
		super();
		this.step = step;
		this.name = name;
	}

	public Player(int dadu, int stepAwal, int step) {
		super();
		this.dadu = dadu;
		this.stepAwal = stepAwal;
		this.step = step;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}

	public int rollDice() {
		int dice = 0;
		dice = rand.nextInt(6) + 1;
		
		return dice;
	}

	public int getStepAwal() {
		return stepAwal;
	}
	
	public void setStepAwal(int stepAwal) {
		this.stepAwal = stepAwal;
	}

	public int getDadu() {
		return dadu;
	}

	public void setDadu(int dadu) {
		this.dadu = dadu;
	}

	public int getStep() {
		return step;
	}

	public void setStep(int step) {
		this.step = step;
	}

	
	public Player() {
		// TODO Auto-generated constructor stub
	}

}
