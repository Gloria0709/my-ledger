#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// 定義資料結構：一筆消費紀錄
struct Expense {
    string date;
    string item;
    int amount;
};

// 顯示所有紀錄的函式
void displayAll(const string& filename) {
    ifstream inFile(filename);
    string d, i;
    int a;
    int total = 0;

    cout << "\n--- 歷史消費清單 ---" << endl;
    while (inFile >> d >> i >> a) {
        cout << "[" << d << "] " << i << ": " << a << " 元" << endl;
        total += a;
    }
    cout << "--------------------" << endl;
    cout << "累計支出合計: " << total << " 元" << endl;
    inFile.close();
}

int main() {
    string filename = "records.txt";
    int choice;

    while (true) {
        cout << "\n=== 簡易 C++ 記帳系統 ===" << endl;
        cout << "1. 新增支出\n2. 查看所有紀錄\n3. 離開\n請選擇: ";
        if (!(cin >> choice)) break;

        if (choice == 1) {
            Expense e;
            cout << "日期 (YYYYMMDD): "; cin >> e.date;
            cout << "項目名稱: "; cin >> e.item;
            cout << "金額: "; cin >> e.amount;

            ofstream outFile(filename, ios::app);
            outFile << e.date << " " << e.item << " " << e.amount << endl;
            outFile.close();
            cout << ">> 已成功存檔！" << endl;
        } 
        else if (choice == 2) {
            displayAll(filename);
        } 
        else if (choice == 3) {
            break;
        }
    }
    return 0;
}