//
// Created by 姚文锋 on 2018/11/6.
//
#include <iostream>

using namespace std;

class TaxStrategy {
public:
    virtual int Calculate(int context) = 0;

    virtual ~TaxStrategy() {};
};

class CNTax : public TaxStrategy {

public:
    int Calculate(int context) override {
        return context+1;
    }

    CNTax *NewStrategy() {
        return new CNTax();
    }
};

class SalesOrder {
private:
    TaxStrategy *strategy;

public:
    SalesOrder(StrategyFactory *strategyFactory) {
        this->strategy = strategyFactory->NewStrategy();
    }

    ~SalesOrder() {
        delete this->strategy;
    }

public:
    double CalculateTax() {
        int context = 1;
        int val = strategy->Calculate(context);
        cout << val << endl;
    }
};