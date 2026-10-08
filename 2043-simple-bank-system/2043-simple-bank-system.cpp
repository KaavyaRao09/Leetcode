#include <vector>
using namespace std;

class Bank {
private:
    vector<long long> bal; // 1-indexed: bal[1] is account 1

    bool valid(int acc) const {
        return acc >= 1 && acc < (int)bal.size();
    }

public:
    Bank(vector<long long>& balance) {
        // store balances 1-indexed: pad index 0
        bal.resize(balance.size() + 1);
        for (size_t i = 0; i < balance.size(); ++i) {
            bal[i + 1] = balance[i];
        }
    }

    bool transfer(int account1, int account2, long long money) {
        if (!valid(account1) || !valid(account2)) return false;
        if (bal[account1] < money) return false;
        bal[account1] -= money;
        bal[account2] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!valid(account)) return false;
        bal[account] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!valid(account)) return false;
        if (bal[account] < money) return false;
        bal[account] -= money;
        return true;
    }
};