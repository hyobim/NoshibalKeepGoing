package org.kpu.atm.helpdesk;

import java.util.Scanner;

import org.kpu.atm.bank.Account;

public class CustomerSvc {
	private Account[] acctArray;
	private int nCurrentAcctNum;
	
	public CustomerSvc(Account[] acctArray, int nCurrentAcctNum) { // ������
		this.acctArray=acctArray;
		this.nCurrentAcctNum=nCurrentAcctNum;
	} 
	Scanner scan = new Scanner(System.in);
	
	public void updatePasswdReq() { // ��й�ȣ ����
		String accountNum;
		String oPass;
		String nPass;
		
		System.out.println("���¹�ȣ �Է�:");
		accountNum = scan.nextLine();
		
		System.out.println("���� ��й�ȣ �Է� : ");
		oPass = scan.nextLine();
		
		System.out.println("�ű� ��й�ȣ �Է� : ");
		nPass = scan.nextLine();
		

		for(int i=0; i<acctArray.length; i++) {
			if(acctArray[i] != null) {
				Integer Ano = acctArray[i].getnID();
				String passw = acctArray[i].getStrPassword();
				if(Ano.toString().equals(accountNum) && passw.equals(oPass)) {
					acctArray[i].updatePasswd(oPass,nPass);
					System.out.println("��й�ȣ�� �����Ͽ����ϴ�.");
					break;
				}
			}
			else {
				System.out.println("���� ������ �߸��Ǿ����ϴ�.");
				break;
			}
		}
	}
}
