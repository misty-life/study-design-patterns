/*
    Template Method
    알고리즘이 동일한 단계를 준수하면서 실행되도록 강제하지만 각 서브 모듈에서의 동작이 변경될 수 있는 디자인 패턴
*/

class DataProcessor {
public:
    void process() {
        loadData();
        processData();
        analyze();
        saveData();
    }

    virtual void loadData() = 0;
    virtual void processData() = 0;
    virtual void analyze() = 0;
    virtual void saveData() = 0;
};

class TextDataProcessor : public DataProcessor {
    void loadData() {
        // Load Data Logic ...
    }

    void processData() {
        // Process Data Logic ...
    }

    void analyze() {
        // Analyze Data Logic ...
    }

    void saveData() {
        // Save Data Logic ...
    }
};

int main(void)
{
    TextDataProcessor textDataProcessor = TextDataProcessor();
    textDataProcessor.process();

    return 0;
}