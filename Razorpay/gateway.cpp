#include <bits/stdc++.h>
using namespace std;

class Transaction {
public:
    string type;  // "DEPOSIT", "TRANSFER"
    int amount;
    int fromId, toId;
    string timestamp;

    Transaction(string type, int amount, int fromId, int toId) {
        this->type = type;
        this->amount = amount;
        this->fromId = fromId;
        this->toId = toId;

        time_t now = time(0);
        timestamp = ctime(&now);
        timestamp.pop_back(); // remove newline
    }
};

class User {
public:
    int id;
    string name;
    string email;
    int balance;
    vector<Transaction> history;

    User(int id, string name, string email, int balance) {
        this->id = id;
        this->name = name;
        this->email = email;
        this->balance = balance;
    }

    void addTransaction(Transaction t) {
        history.push_back(t);
    }
};

class Gateway {
private:
    map<int, User*> users;  // store users by id

public:
    void addUser(int id, string name, string email, int balance) {
        if(users.count(id)) {
            cout << "User already exists!\n";
            return;
        }
        users[id] = new User(id, name, email, balance);
    }

    void deposit(int userId, int amount) {
        if(!users.count(userId)) { cout << "User not found!\n"; return; }
        User* u = users[userId];
        u->balance += amount;
        u->addTransaction(Transaction("DEPOSIT", amount, userId, userId));
        cout << "Deposited " << amount << " to " << u->name << endl;
    }

    void transfer(int fromId, int toId, int amount) {
        if(!users.count(fromId) || !users.count(toId)) {
            cout << "User not found!\n"; return;
        }
        User* from = users[fromId];
        User* to = users[toId];

        if(from->balance < amount) {
            cout << "Insufficient balance!\n"; return;
        }

        from->balance -= amount;
        to->balance += amount;

        Transaction t("TRANSFER", amount, fromId, toId);
        from->addTransaction(t);
        to->addTransaction(t);

        cout << "Transferred " << amount << " from " << from->name 
             << " to " << to->name << endl;
    }

    void printHistory(int userId) {
        if(!users.count(userId)) { cout << "User not found!\n"; return; }
        User* u = users[userId];
        cout << "Transaction history for " << u->name << ":\n";
        for(auto &t : u->history) {
            cout << "[" << t.timestamp << "] " 
                 << t.type << " " << t.amount;
            if(t.type == "TRANSFER") cout << " (from " << t.fromId << " to " << t.toId << ")";
            cout << endl;
        }
    }
};

int main() {
    Gateway g;
    g.addUser(1, "Alankrit", "alankritsingh778", 1000);
    g.addUser(2, "Aman", "amansingh778", 15000);
    g.addUser(3, "Raj", "raj123", 7000);

    g.deposit(1, 500);
    g.transfer(1, 2, 800);
    g.printHistory(2);
}
