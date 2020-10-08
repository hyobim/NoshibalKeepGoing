package org.kpu.atm.bank;
import java.util.Scanner;

import org.kpu.atm.helpdesk.CustomerSvc;
import org.kpu.atm.util.Statistics;

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
		nMaxAccountNum=size;
		nMachineBalance=balance;
		strManagerPassword=password;
		
	}
	public void createAccount() {
		
		System.out.println("----------개설----------");
		System.out.println("이름 입력 : ");
		name = scan.nextLine();
		System.out.println("비밀번호 입력 : ");
		passwd = scan.nextLine();
	
		for (int i = 0; i < accountArray.length; i++) {
			if (accountArray[i] == null) {
				accountArray[i] = new Account(idx, 0, name, passwd);
				break;
			}
		}
		
		nCurrentAccountNum+=1;
		
		System.out.println(name+"님 "+ idx++ +"번 계좌번호가 정상적으로 개설됐습니다.");
	}
	public void checkMoney() { // 계좌조회
		String accountNum;
		String pass;
		
		System.out.println("계좌번호 입력:");
		accountNum = scan.nextLine();
		
		System.out.println("비밀번호 입력 : ");
		pass = scan.nextLine();
		
		
			for(int i=0; i<accountArray.length; i++) {
				if(accountArray[i] != null) {
					Integer Ano = accountArray[i].getnID();
					String passw = accountArray[i].getStrPassword();
					if(Ano.toString().equals(accountNum) && passw.equals(pass)) {
						System.out.println("계좌 잔액:"+ accountArray[i].getnBalance() );
						break;
					}
				}
				else {
					System.out.println("계좌 정보가 잘못되었습니다.");
					break;
				}
			}
	}
	
	public void depositMoney() {  // 계좌입금
		String accountNum;
		String pass;
		Integer money;
		
		System.out.println("계좌번호 입력:");
		accountNum = scan.nextLine();
		
		System.out.println("비밀번호 입력 : ");
		pass = scan.nextLine();
		
		System.out.println("입금 액 입력 : ");
		money = Integer.parseInt(scan.nextLine());

		
			for(int i=0; i<accountArray.length; i++) {
				if(accountArray[i] != null) {
					Integer Ano = accountArray[i].getnID();
					String passw = accountArray[i].getStrPassword();
					if(Ano.toString().equals(accountNum) && passw.equals(pass)) {
						accountArray[i].deposit(money);
						System.out.println("입금 후 잔액:"+ accountArray[i].getnBalance() );
						break;
					}
				}
				else {
					System.out.println("계좌 정보가 잘못되었습니다.");
					break;
				}
			}
	}
	
	public void widrawMoney() { // 계좌 출금
		String accountNum;
		String pass;
		Integer money;
		
		System.out.println("계좌번호 입력:");
		accountNum = scan.nextLine();
		
		System.out.println("비밀번호 입력 : ");
		pass = scan.nextLine();
		
		System.out.println("출금 액 입력 : ");
		money = Integer.parseInt(scan.nextLine());

		
			for(int i=0; i<accountArray.length; i++) {
				if(accountArray[i] != null) {
					Integer Ano = accountArray[i].getnID();
					String passw = accountArray[i].getStrPassword();
					if(Ano.toString().equals(accountNum) && passw.equals(pass)) {
						accountArray[i].widraw(money);
						System.out.println("출금 후 잔액:"+ accountArray[i].getnBalance() );
						break;
					}
				}
				else {
					System.out.println("계좌 정보가 잘못되었습니다.");
					break;
				}
			}
	}
	
	public void transfer() { // 계좌 이체
		String accountNum;
		String pass;
		String tAccountNum;
		Integer tMoney;
		boolean f = false;
		boolean f2 = false;
		
		System.out.println("계좌번호 입력:");
		accountNum = scan.nextLine();
		
		System.out.println("비밀번호 입력 : ");
		pass = scan.nextLine();
		
		System.out.println("이체계좌 입력 : ");
		tAccountNum = scan.nextLine();

		System.out.println("이체금액 입력 : ");
		tMoney = Integer.parseInt(scan.nextLine());
		
			for(int i=0; i<accountArray.length; i++) {
				if(accountArray[i] != null) {
					Integer Ano = accountArray[i].getnID();
					String passw = accountArray[i].getStrPassword();
					
					if(Ano.toString().equals(accountNum) && passw.equals(pass)) {
						f2=true;
						for(int j=0; j<accountArray.length; j++) {
							Integer tAno = accountArray[j].getnID();
							if(tAno.toString().equals(tAccountNum)) {
								accountArray[i].widraw(tMoney);
								System.out.println("현재 잔액:"+ accountArray[i].getnBalance());
								System.out.println("계좌 이체를 완료했습니다");
								f=true;
								break;
							}
						}
					}
					if(f==false) {
						System.out.println("이체 계좌를 다시 확인하세요.");
						break;
					}
				}
				if(f2==false) {
					System.out.println("계좌 정보가 잘못되었습니다.");
					break;
				}
			}
	}
	
	public void requestSvc() { // 비밀번호 변경요청
		
		CustomerSvc cSv=new CustomerSvc(accountArray, nCurrentAccountNum);
		cSv.updatePasswdReq();
		
	}
	public void managerMode() { // 고객 관리
		String admin;
		Statistics stat=new Statistics();
		
		System.out.println("관리자 비밀번호 입력:");
		admin = scan.nextLine();
		
		if(admin.equals(strManagerPassword)) {
			System.out.println("ATM 현금잔고:\t"+ (nMachineBalance+ stat.sum(accountArray, nCurrentAccountNum)));
			System.out.println("고객 잔고 총액:\t"+ (stat.sum(accountArray, nCurrentAccountNum))+"원("+ nCurrentAccountNum +"명)");
			System.out.println("고객 잔고 평균:\t"+ (stat.average(accountArray, nCurrentAccountNum))+"원");
			System.out.println("고객 잔고 최고:\t"+ (stat.max(accountArray, nCurrentAccountNum))+"원");
			System.out.println("고객 계좌 현황(고객 잔고 내림차순 정렬)"); // 이름 계좌번호 금액 원
			
			Account[] srt=stat.sort(accountArray, nCurrentAccountNum);
			
			for(int i=0;i<nCurrentAccountNum;i++) {
				System.out.println(srt[i].getAccountName()+"\t"+srt[i].getnID()+"\t"+srt[i].getnBalance()+"원");
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
		System.out.println(" 5. 계좌 이체");
		System.out.println(" 6. 고객 센터");
		System.out.println(" 7. 고객 관리");
		System.out.println(" 9. 업무 종료");
		
	}
}
