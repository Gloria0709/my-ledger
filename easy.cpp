#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    int choice;

    while (true) {

        cout << "\n=== 簡單記帳系統 ===" << endl;
        cout << "1. 新增紀錄" << endl;
        cout << "2. 查看紀錄" << endl;
        cout << "3. 離開" << endl;
        cout << "請選擇: ";
        cin >> choice;

        // =====================
        // 新增紀錄
        // =====================
        if (choice == 1) {

            string date;
            string item;
            int amount;

            cout << "輸入日期: ";
            cin >> date;

            cout << "輸入項目: ";
            cin >> item;

            cout << "輸入金額: ";
            cin >> amount;

            ofstream file("records.txt", ios::app);

            file << date << " "
                 << item << " "
                 << amount << endl;

            file.close();

            cout << "已存檔!" << endl;
        }

        // =====================
        // 查看紀錄
        // =====================
        else if (choice == 2) {

            ifstream file("records.txt");

            string date;
            string item;
            int amount;

            int total = 0;

            cout << "\n--- 所有紀錄 ---" << endl;

            while (file >> date >> item >> amount) {

                cout << date << " "
                     << item << " "
                     << amount << " 元" << endl;

                total += amount;
            }

            cout << "總花費: " << total << " 元" << endl;

            file.close();
        }

        // =====================
        // 離開
        // =====================
        else if (choice == 3) {

            cout << "程式結束" << endl;
            break;
        }

        else {
            cout << "輸入錯誤" << endl;
        }
    }

    return 0;
}
