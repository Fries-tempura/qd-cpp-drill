#include<iostream>
class Rectangle{
    public:
        Rectangle(int w, int h, const std::string& color, const std::string& name):width_(w),height_(h),color_(color),name_(name){}
        Rectangle(int w, int h, const std::string& color): Rectangle(w, h, color, "unnamed"){}
        Rectangle(int w, int h):Rectangle(w, h, "white", "unnamed"){}
        Rectangle(int side):Rectangle(side, side, "white", "unnamed"){}
        Rectangle():Rectangle(1, 1, "white", "unnamed"){}
        void print()const{
            std::cout<<"Rect ["<<name_<<"]: "<<width_<<"x"<<height_<<", color="<<color_<<std::endl;
        }
    private:
        int width_;
        int height_;
        std::string color_;
        std::string name_;
};
int main() {
    Rectangle r1;                              // 默认
    Rectangle r2(5);                           // 正方形
    Rectangle r3(3, 4);                        // 长方形
    Rectangle r4(3, 4, "red");                 // 加颜色
    Rectangle r5(3, 4, "blue", "myRect");      // 全指定

    r1.print();
    r2.print();
    r3.print();
    r4.print();
    r5.print();
    return 0;
  }
