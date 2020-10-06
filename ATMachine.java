package org.kpu.atm.bank;
import java.util.Scanner;

public class ATMachine {
	private Account[] accountArray = new Account[1000];		//�����¹迭 ��������
	private int nMachineBalance;			//atm �ܰ�
	private int nMaxAccountNum;				//������ �������� �迭ũ��
	private static int nCurrentAccountNum;	//������ ������ ��
	private String strManagerPassword;		//������ ��й�ȣ
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
		
		System.out.println("----------����----------");
		System.out.println("�̸� �Է� : ");
		name = scan.nextLine();
		System.out.println("��ȣ �Է� : ");
		passwd = scan.nextLine();
	
		for (int i = 0; i < accountArray.length; i++) {
			if (accountArray[i] == null) {
				accountArray[i] = new Account(idx, 0, name, passwd);
				break;
			}
		}
		
		System.out.println(name+"��"+ idx++ +"�� ���¹�ȣ�� ���������� �����ƽ��ϴ�.");
	}
	public void checkMoney() {
		String accountNum;
		String pass;
		
		System.out.println("���¹�ȣ �Է�:");
		accountNum = scan.nextLine();
		
		System.out.println("��ȣ �Է� : ");
		pass = scan.nextLine();
		
		
			for(int i=0; i<accountArray.length; i++) {
				if(accountArray[i] != null) {
					Integer Ano = accountArray[i].getnID();
					String passw = accountArray[i].getStrPassword();
					if(Ano.toString().equals(accountNum) && passw.equals(pass)) {
						System.out.println("���� �ܾ�:"+ accountArray[i].getnBalance() );
						break;
					}
					else {
						System.out.println("���� ������ �߸��Ǿ����ϴ�.");
						break;
					}
				}
			}
	}
	
	public void displayMenu() {
		System.out.println("-----------------------");
		System.out.println("-       KPU bank      -");
		System.out.println("-----------------------");
		System.out.println(" 1. ���� ����");
		System.out.println(" 2. ���� ��ȸ");
		System.out.println(" 3. ���� �Ա�");
		System.out.println(" 4. ���� ���");
		System.out.println(" 9. ���� ����");
		
	}
}
