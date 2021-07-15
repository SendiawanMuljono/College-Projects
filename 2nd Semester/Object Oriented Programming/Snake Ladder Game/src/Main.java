import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Vector;

public class Main {
	Scanner sc = new Scanner(System.in);
	Player player1 = new Player();
	Player player2 = new Player();
	Player player3 = new Player();

	public Main() {
		int choose = 0;
		do {
			int f = 0;
			menu();
			try {
				choose = sc.nextInt();
			} catch (Exception e) {
				System.out.println("Input must be a number!");
				press();
				f = 1;
				choose = 0;
			}
			sc.nextLine();
			if(choose<1||choose>3) {
				if(f!=1) {
					System.out.println("Please input between [1-3]!");
					press();
				}
			}
			else if(choose == 1) {
				start();
				play(2);
				winningPool();
				choose = 0;
			}
			else if(choose == 2) {
				start();
				play(3);
				winningPool();
				choose = 0;
			}
			else if(choose == 3) {
				System.out.println("See you next time!");
			}
		}while(choose<1||choose>3);
	}
	
	void winningPool() {
		Vector<Player> win = new Vector<>();
		win.add(new Player(player1.getStep(), player1.getName()));
		win.add(new Player(player2.getStep(), player2.getName()));
		win.add(new Player(player3.getStep(), player3.getName()));
		Collections.sort(win, new Comparator<Player>() {
			@Override
			public int compare(Player o1, Player o2) {
				return Integer.valueOf(o1.getStep()).compareTo(o2.getStep());
			}
		});
		System.out.println();
		System.out.println("* * * * * * * * * * * * * *");
		System.out.println("* <<<<< WinningPool >>>>> *");
		System.out.println("*  =====================  *");
		System.out.println("*  |   NAME   |  STEP  |  *");
		System.out.println("*  =====================  *");
		for (int i = win.size()-1; i >= 0; i--) {
			System.out.printf("*  | %s |  %-3d   |  *\n",win.get(i).getName(),win.get(i).getStep());
			System.out.println("*  ---------------------  *");
		}
		System.out.println("* * * * * * * * * * * * * *");
		press();
	}
	void display() {
		System.out.println();
		System.out.println("************************** Current Board **************************");
		System.out.println("==================================================================");
		System.out.println("|       |     Player A     |     Player B     |     Player C     |");
		System.out.println("| Round |------------------|------------------|------------------|");
		System.out.println("|       | Old | Dice | New | Old | Dice | New | Old | Dice | New |");
		System.out.println("==================================================================");
		for (int i = 0; i < player1.data.size(); i++) {
			Player data1 = player1.data.get(i);
			Player data2 = player2.data.get(i);
			if(player3.data.isEmpty()) {
				System.out.printf("|  %-2d   | %-3d |  %-2d  | %-3d | %-3d |  %-2d  | %-3d |     |      |     |\n",i+1,data1.getStepAwal(),data1.getDadu(),data1.getStep(),data2.getStepAwal(),data2.getDadu(),data2.getStep());
			}
			else {
				Player data3 = player3.data.get(i);
				System.out.printf("|  %-2d   | %-3d |  %-2d  | %-3d | %-3d |  %-2d  | %-3d | %-3d |  %-2d  | %-3d |\n",i+1,data1.getStepAwal(),data1.getDadu(),data1.getStep(),data2.getStepAwal(),data2.getDadu(),data2.getStep(),data3.getStepAwal(),data3.getDadu(),data3.getStep());
			}
			System.out.println("|----------------------------------------------------------------|");
		}
		System.out.println("==================================================================");
	}
	int bonalty(int total, int turn) {
		char plyr = (char)(turn+64);
		int t = 0;
		if(total == 13 || total == 50 || total == 95) {
			System.out.print("Aww, Player " + plyr + " climb down the snake to ");
		}
		else if(total == 25 || total == 63 || total == 83) {
			System.out.print("Lucky! Player " + plyr + " climb the ladder to " );
		}
		if(total == 13) {
			System.out.printf("7\n");
			t = 7;
		}
		else if(total == 25) {
			System.out.printf("40\n");
			t = 40;
		}
		else if(total == 50) {
			System.out.printf("38\n");
			t = 38;
		}
		else if(total == 63) {
			System.out.printf("78\n");
			t = 78;
		}
		else if(total == 83) {
			System.out.printf("97\n");
			t = 97;
		}
		else if(total == 95) {
			System.out.printf("76\n");
			t = 76;
		}
		return t;
	}
	void playerTurn(Player player, int turn) {
		int kocok = 0;
		int dice = 0;
		int total = 0;
		player.setStepAwal(player.getStep());
		System.out.println();
		System.out.println("[It's "+ player.getName() +" turn!]");
		roll();
		kocok = player.rollDice();
		dice = kocok;
		System.out.println(player.getName() + " rolls " + kocok);
		total = player.getStep() + kocok;
		if(total > 100) {
			total = 100 - total%100;
		}
		System.out.println(player.getName() + " steps to " + total + "!");
		if(total == 13 || total == 25 || total == 50 || total == 63 || total == 83 || total == 95) {
			total = bonalty(total, turn);
		}
		while(kocok == 6 && total!=100) {
			System.out.println();
			System.out.println(player.getName() + " gets additional roll for rolling six!");
			roll();
			kocok = player.rollDice();
			dice += kocok;
			System.out.println(player.getName() + " rolls " + kocok);
			total += kocok;
			if(total>100){
				total = 100-total%100;
			}
			System.out.println(player.getName() +" steps to " + total + "!");
			if(total == 13 || total == 25 || total == 50 || total == 63 || total == 83 || total == 95) {
				total = bonalty(total, 1);
			}
		}
		if(total == 100) {
			player.setStep(100);
			return;
		}
		player.setDadu(dice);
		player.setStep(total);
		player.data.add(new Player(player.getDadu(), player.getStepAwal(), player.getStep()));
	}
	void play(int totalPlyr) {
		int round = 0;
		int turn = 1;
		while(true) {
			round++;
			if (round > 25) {
				break;
			}
			else {
				System.out.println();
				System.out.println("##### ROUND " + round + " #####");
				if(turn == 1) {
					playerTurn(player1, turn);
					if(player1.getStep() == 100) {
						break;
					}
					turn++;
				}
				if(turn == 2) {
					playerTurn(player2, turn);
					if(player2.getStep()==100) {
						break;
					}
					if(totalPlyr == 3) {
						turn++;
					}
					else {
						turn--;
					}
				}
				if(turn == 3) {
					playerTurn(player3, turn);
					if(player3.getStep()==100) {
						break;
					}
					turn-=2;
				}
			}
			press();
			display();
			press();
		}
	}
	void menu() {
		System.out.println();
		System.out.println("Snakes Ladders");
		System.out.println("==============");
		System.out.println();
		System.out.println("How many players do you want to play?");
		System.out.println("1. 2 players");
		System.out.println("2. 3 players");
		System.out.println("3. Exit");
		System.out.print("Choose : ");
	}
	void start() {
		player1.setDadu(0);
		player1.setStep(0);
		player1.setStepAwal(0);
		player1.setName("Player A");
		player1.data.clear();
		player2.setDadu(0);
		player2.setStep(0);
		player2.setStepAwal(0);
		player2.setName("Player B");
		player2.data.clear();
		player3.setDadu(0);
		player3.setStep(0);
		player3.setStepAwal(0);
		player3.setName("Player C");
		player3.data.clear();
	}
	void roll() {
		System.out.print("Press ENTER to roll the dice!");
		sc.nextLine();
	}
	void press() {
		System.out.print("Press ENTER to continue...");
		sc.nextLine();
	}
	
	public static void main(String[] args) {
		new Main();
	}
}
