package org.kpu.atm.helpdesk;

import java.util.Scanner;

import org.kpu.atm.bank.Account;

public class CustomerSvc {
	private Account[] acctArray;
	private int nCurrentAcctNum;
	
	public CustomerSvc(Account[] acctArray, int nCurrentAcctNum) { // 생성자
		this.acctArray=acctArray;
		this.nCurrentAcctNum=nCurrentAcctNum;
	} 
	Scanner scan = new Scanner(System.in);
	
	public void updatePasswdReq() { // 비밀번호 변경
		String accountNum;
		String oPass;
		String nPass;
		
		System.out.println("계좌번호 입력:");
		accountNum = scan.nextLine();
		
		System.out.println("기존 비밀번호 입력 : ");
		oPass = scan.nextLine();
		
		System.out.println("신규 비밀번호 입력 : ");
		nPass = scan.nextLine();
		

		for(int i=0; i<acctArray.length; i++) {
			if(acctArray[i] != null) {
				Integer Ano = acctArray[i].getnID();
				String passw = acctArray[i].getStrPassword();
				if(Ano.toString().equals(accountNum) && passw.equals(oPass)) {
					acctArray[i].updatePasswd(oPass,nPass);
					System.out.println("비밀번호를 수정하였습니다.");
					break;
				}
			}
			else {
				System.out.println("계좌 정보가 잘못되었습니다.");
				break;
			}
		}
	}
}
