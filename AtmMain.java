package org.kpu.atm.main;

import java.util.InputMismatchException;
import java.util.Scanner;

import org.kpu.atm.bank.ATMachine;

public class AtmMain {
	public static void main(String[] args) {
		// 초기 설정 - 개설가능한 최대계좌수(1000계좌),
		// ATM 잔금(50만원), 관리자 암호
		ATMachine atm = new ATMachine(1000, 500000, "admin");
		Scanner scan = new Scanner(System.in);
		while(true) {
			atm.displayMenu();
			System.out.println(" 메뉴를 선택하세요 >> " );
			try {
				int select = scan.nextInt();
				switch(select) {
					case 1: // 계좌 개설
						atm.createAccount();
						break;
					case 2: // 계좌 조회
						atm.checkMoney();
						break;
					case 3: // 계좌 조회
						atm.checkMoney();
						break;
					case 4: // 계좌 조회
						atm.checkMoney();
						break;
					case 9: // 업무 종료
						System.out.println("안녕히 가세요 !");
						break;
				}
				} catch (InputMismatchException e) {
					System.out.println(" 정확하게 입력해주세요.");
					continue;
				}
			}
	}
}
