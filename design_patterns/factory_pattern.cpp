#include<iostream>
#include<memory>

class DiagnosticRequest{
    public:
        virtual void process() = 0;
        virtual ~DiagnosticRequest() = default;
};

class ReadDiagRequest: public DiagnosticRequest{
    public:
        void process() override{
            std::cout<< "Read request:\n";
        }
};

class WriteDiagRequest: public DiagnosticRequest{
    public:
        void process(){
            std::cout<< "Write request:\n";
        }
};

class RequestFactory{

    public:
        static std::unique_ptr<DiagnosticRequest> 
        create(int action){
            switch (action)
            {
            case 1:
                return std::make_unique<ReadDiagRequest>();
                break;
            case 2:
                return std::make_unique<WriteDiagRequest>();
                break;
            default:
                return nullptr;
                break;
            }
        }
};

int main(){

    int type;
    std::cin >> type;

    std::unique_ptr<DiagnosticRequest> d = 
    RequestFactory::create(type);
 
    d->process();
}