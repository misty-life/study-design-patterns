/*
    Strategy Pattern
    실행 중에 알고리즘을 선택 가능하게 하는 디자인 패턴
*/

// Strategy

class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;
    virtual void pay(int amount) = 0;
};

class CashPaymentStrategy : public PaymentStrategy {
public:
    void pay(int amounut) {
        // Pay with cash Logic ...
    }
};

class CardPaymentStrategy : public PaymentStrategy {
public:
    void pay(int amount) {
        // Pay with credit card Logic ...
    }
};

// Context

class PaymentContext {
private:
    PaymentStrategy *paymentStrategy;
public:
    void setStrategy(PaymentStrategy *newStrategy) {
        paymentStrategy = newStrategy;
    }

    void pay(int amount) {
        paymentStrategy->pay(amount);
    }
};

int main(void)
{
    PaymentContext paymentContext = PaymentContext();
    
    CashPaymentStrategy cashPaymentStrategy;
    paymentContext.setStrategy(&cashPaymentStrategy);
    paymentContext.pay(100);

    CardPaymentStrategy cradPaymentStrategy;
    paymentContext.setStrategy(&cradPaymentStrategy);
    paymentContext.pay(200);

    return 0;
}