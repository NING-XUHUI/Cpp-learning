//
// Created by 宁旭晖 on 2020/2/23.
//

#ifndef BANK_ACCOUNT_ACCOUNT_H
#define BANK_ACCOUNT_ACCOUNT_H


class SavingAccount {
public:
    SavingAccount(double rate, double balance);

private:
    int id;//账号
    double  balance;//余额
    double rate;//存款的年利率
    int lastDate;//上次变更余额的时期
    double accumulation;//余额按日累加之和
    static double total;//所有账户的总金额
};


#endif //BANK_ACCOUNT_ACCOUNT_H
