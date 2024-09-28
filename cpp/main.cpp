#include <iostream>
class Hoge
{
public:
    // クラスに属する関数
    static void static_method1()
    {
        std::cout << "static_method" <<std::endl;
        return;
    }
    static void static_method2()
    {
        // メンバにアクセスできない
        // 以下はエラー
        // data1;
        // data2;
        // this->data1;
        // this->data2;
    }
    static void static_method3(Hoge hoge)
    {
        //引数で渡せばアクセスできる
        std::cout << hoge.data1 << std::endl;
        //プライベート変数にもアクセスできる
        std::cout << hoge.data2 << std::endl;

    }
    void method(){}
    int data1{1};
private:
    int data2{2};


};
class Fuga
{
public:
    void func(Hoge hoge)
    {
        // アクセスできる
        std::cout << hoge.data1 << std::endl;
        // 通常はプライベートなのでアクセスできない
        // std::cout << hoge.data2 << std::endl;
    }
};

int main(int argc, char** argv)
{
    // インスタンス無しで呼べる
    Hoge::static_method1();
    // 非staticなので呼べない
    // Hoge::method();

    Hoge hoge;
    Hoge::static_method3(hoge);


    return 0;
}
