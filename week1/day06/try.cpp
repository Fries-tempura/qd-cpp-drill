#include <iostream>
class SimpleCounter{
    public:
    SimpleCounter():count_(0){
        std::cout<<"Counter created, count = 0"<<std::endl;
    }
    ~SimpleCounter(){
        std::cout<<"Counter destroyed, final count = "<< count_ <<std::endl;
    }
    void increment(){
        count_+=1;
    }
    int get_count() const{
        return count_;
    }
    private:
        int count_;
};
int main(){
    SimpleCounter m;
    m.increment();
    m.increment();
    m.increment();
    std::cout << "current count = " << m.get_count() << std::endl;
    return 0;
}