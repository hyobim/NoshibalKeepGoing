package org.kpu.atm.bank;
import java.util.Scanner;

public class ATMachine {
	private Account[] accountArray = new Account[1000];		//고객계좌배열 참조변수
	private int nMachineBalance;			//atm 잔고
	private int nMaxAccountNum;				//고객계좌 참조변수 배열크기
	private static int nCurrentAccountNum;	//개설된 고객계좌 수
	private String strManagerPassword;		//관리자 비밀번호
	private String name;
	private String passwd;
	static int idx=100;
	
	Scanner scan = new Scanner(System.in);
	public static final int BASE_ACCOUNT_ID = 100;
	
	public ATMachine(int size, int balance, String password) {
		nMachineBalance=balance;
		nMaxAccountNum=size;
		strManagerPassword=password;
		
	}
	public void createAccount() {
		
		System.out.println("----------개설----------");
		System.out.println("이름 입력 : ");
		name = scan.nextLine();
		System.out.println("암호 입력 : ");
		passwd = scan.nextLine();
	
		for (int i = 0; i < accountArray.length; i++) {
			if (accountArray[i] == null) {
				accountArray[i] = new Account(idx, 0, name, passwd);
				break;
			}
		}
		
		System.out.println(name+"님"+ idx++ +"번 계좌번호가 정상적으로 개설됐습니다.");
	}
	public void checkMoney() {
		String accountNum;
		String pass;
		
		System.out.println("계좌번호 입력:");
		accountNum = scan.nextLine();
		
		System.out.println("암호 입력 : ");
		pass = scan.nextLine();
		
		
			for(int i=0; i<accountArray.length; i++) {
				if(accountArray[i] != null) {
					Integer Ano = accountArray[i].getnID();
					String passw = accountArray[i].getStrPassword();
					if(Ano.toString().equals(accountNum) && passw.equals(pass)) {
						System.out.println("계좌 잔액:"+ accountArray[i].getnBalance() );
						break;
					}
					else {
						System.out.println("계좌 정보가 잘못되었습니다.");
						break;
					}
				}
			}
	}
	
	public void displayMenu() {
		System.out.println("-----------------------");
		System.out.println("-       KPU bank      -");
		System.out.println("-----------------------");
		System.out.println(" 1. 계좌 개설");
		System.out.println(" 2. 계좌 조회");
		System.out.println(" 3. 계좌 입금");
		System.out.println(" 4. 계좌 출금");
		System.out.println(" 9. 업무 종료");
		
	}
}
