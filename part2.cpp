#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// =======================
// Expense 類別
// =======================
class Expense {
public:
    string date;
    string item;
    string category;
    int amount;

    Expense(string d, string i, string c, int a) {
        date = d;
        item = i;
        category = c;
        amount = a;
    }

    void display() const {
        cout << "[" << date << "] "
             << item << " | "
             << category << " | "
             << amount << " 元" << endl;
    }
};

// =======================
// 讀取檔案
// =======================
vector<Expense> loadExpenses(const string& filename) {

    vector<Expense> list;
    ifstream inFile(filename);

    string d, i, c;
    int a;

    while (inFile >> d >> i >> c >> a) {
        list.push_back(Expense(d, i, c, a));
    }

    inFile.close();
    return list;
}

// =======================
// 顯示所有紀錄
// =======================
void displayAll(const vector<Expense>& list) {

    int total = 0;

    cout << "\n--- 歷史消費清單 ---" << endl;

    for (const Expense& e : list) {
        e.display();
        total += e.amount;
    }

    cout << "--------------------" << endl;
    cout << "累計支出合計: " << total << " 元" << endl;
}

// =======================
// 新增紀錄 (含防呆)
// =======================
void addExpense(const string& filename) {

    string d, i, c;
    int a;

    cout << "日期 (YYYYMMDD): ";
    cin >> d;

    cout << "項目名稱: ";
    cin >> i;

    cout << "分類 (food/traffic/etc): ";
    cin >> c;

    cout << "金額: ";

    while (!(cin >> a)) {
        cout << "輸入錯誤，請輸入數字: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    while (a < 0) {
        cout << "金額不能為負數，請重新輸入: ";
        cin >> a;
    }

    Expense e(d, i, c, a);

    ofstream outFile(filename, ios::app);

    outFile << e.date << " "
            << e.item << " "
            << e.category << " "
            << e.amount << endl;

    outFile.close();

    cout << ">> 已成功存檔！" << endl;
}

// =======================
// 搜尋功能
// =======================
void searchItem(const vector<Expense>& list) {

    string key;
    bool found = false;

    cout << "請輸入搜尋關鍵字: ";
    cin >> key;

    cout << "\n--- 搜尋結果 ---" << endl;

    for (const Expense& e : list) {

        if (e.item.find(key) != string::npos ||
            e.category.find(key) != string::npos) {

            e.display();
            found = true;
        }
    }

    if (!found) {
        cout << "找不到相關紀錄。" << endl;
    }

    cout << "----------------" << endl;
}

// =======================
// 顯示選單
// =======================
void showMenu() {

    cout << "\n=== 簡易 C++ 記帳系統 ===" << endl;
    cout << "1. 新增支出" << endl;
    cout << "2. 查看所有紀錄" << endl;
    cout << "3. 搜尋紀錄" << endl;
    cout << "4. 離開" << endl;
    cout << "請選擇: ";
}

// =======================
// main
// =======================
int main() {

    string filename = "records.txt";
    int choice;

    while (true) {

        showMenu();

        while (!(cin >> choice)) {
            cout << "請輸入數字選項: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (choice == 1) {

            addExpense(filename);

        }
        else if (choice == 2) {

            vector<Expense> list = loadExpenses(filename);
            displayAll(list);

        }
        else if (choice == 3) {

            vector<Expense> list = loadExpenses(filename);
            searchItem(list);

        }
        else if (choice == 4) {

            cout << "程式結束。" << endl;
            break;

        }
        else {

            cout << "請輸入正確選項。" << endl;

        }
    }

    return 0;
}
