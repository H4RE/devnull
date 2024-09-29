#include <iostream>

class Base1
{
public:
    void wo_vi_ov(){std::cout << "wo vi ov @base" <<std::endl;}
};

class Sub1: public Base1
{
public:
    void wo_vi_ov(){std::cout << "wo vi ov @sub" <<std::endl;}
};

class Base2
{
public:
    void wo_vi_ov(){std::cout << "wo vi ov @base" <<std::endl;}

};

class Sub2: public Base2
{
public:
    // これはコンパイルエラー
    // void wo_vi_ov()override{std::cout << "wo vi ov @sub" <<std::endl;}
};

class Base3
{
public:
    virtual void wo_vi_ov(){std::cout << "wo vi ov @base" <<std::endl;}

};

class Sub3: public Base3
{
public:
    void wo_vi_ov(){std::cout << "wo vi ov @sub" <<std::endl;}
};

class Base4
{
public:
    virtual void wo_vi_ov(){std::cout << "wo vi ov @base" <<std::endl;}

};

class Sub4: public Base4
{
public:
    void wo_vi_ov()override{std::cout << "wo vi ov @sub" <<std::endl;}
};
int main(int argc, char** argv)
{
    // 1: virtualなし overrideなし
    {
        Sub1 sub;
        sub.wo_vi_ov();//subが呼ばれる

        Base1* base = &sub;
        // 再定義なので、baseのポインタ経由ではbaseが呼ばれる
        base->wo_vi_ov();
    }

    // 2: virtualなし overrideあり
    {
    }

    // 3: virtualあり overrideなし
    {
        Sub3 sub;
        sub.wo_vi_ov();//subが呼ばれる

        Base3* base = &sub;
        // baseにvirtualがついているのでsubが呼ばれる
        base->wo_vi_ov();//subが呼ばれる
    }
    // 4: virtualあり overrideなし
    {
        Sub4 sub;
        sub.wo_vi_ov();//subが呼ばれる

        Base4* base = &sub;
        // baseにvirtualがついているのでsubが呼ばれる
        base->wo_vi_ov();//subが呼ばれる
    }
    return 0;
}

/*
 *
 * Base Class
 * virtual あり　なし
 * Sub　Class
 * override　あり　なし
 *
 * 1. virtual なし and override なし
 * 関数の再定義になる
 * Subでインスタンスして呼び出すとSubの関数が呼ばれるが、
 * Baseのポインタ経由で呼び出すとbaseの関数が呼ばれる
 *
 * 2. virtual なし and override あり
 * overrideするものがないのでコンパイルエラー
 *
 * 3. virtual あり and override なし
 * 4. virtual あり and override あり
 * どちらもSubが呼ばれる
 * baseのポインタ経由でもvirtualが付いているのでsubが呼ばれる
 *
 * */
