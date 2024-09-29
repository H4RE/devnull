#include <iostream>

class Hoge
{
public:
    void pub(){std::cout <<"public" <<std::endl;}
protected:
    void pro(){std::cout <<"private" <<std::endl;}
private:
    void pri(){std::cout <<"private" <<std::endl;}
};
class Fuga: public Hoge
{
public:
    void fn()
    {
        this->pub();//ok
        this->pro();//ok
        // this->pri();//ng
    }
};
class FugaPro: protected Hoge
{
    // Hogeのpublicがprotectedに変わる
public:
    void func()
    {
        this->pub();//ok
        this->pro();//ok
        // this->pri();//ng
    }
};
class FugaPri: private Hoge
{
    // Hogeのpublic, protectedがprivateに変わる
public:
    void func()
    {
        this->pub();//ok
        this->pro();//ok
        // this->pri();//ng
    }
};

class FugaProSub: public FugaPro
{
public:
    FugaProSub()
    {
        this->pro();
    }
};

class FugaPriSub: public FugaPri
{
public:
    FugaPriSub()
    {
        //FugaPriでprivate継承してprivateになっているのでアクセス不可
        // this->pro();
    }
};
int main(int argc, char** argv)
{
    Fuga fuga;
    fuga.pub();

    FugaPro fugapro;
    //protected継承なのでHogeのpublicがprotectedになる
    //-->pubにアクセスできない
    // fugapro.pub();
    
    FugaPri fugapri;
    // fugapri.pub();

    return 0;
}
/*
 * public
 *      クラス内、継承先、クラス外からアクセス可能
 * protected
 *      クラス内、継承先からアクセス可能
 * private
 *      クラス内からアクセス可能
 *
 * public継承
 *      アクセス権の変更なし
 *
 * protected継承
 *      public-->protectedになる
 *      なので、baseクラスのpublicにクラス外からアクセスできなくなる
 *
 * private継承
 *      public-->privateになる
 *      なので、baseクラスのpublicにクラス外からアクセスできなくなる
 *      一方でprivate継承でもsubクラスのメソッドから親クラスのpublic、protectedメソッドへはアクセスできる点に注意が必要
 *
 *
 * */
