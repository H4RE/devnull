#include <iostream>

void func();
int main(int argc, char** argv)
{
    func();
    return 0;
}
/*
- 宣言だけだと、コンパイルはできてその後undefined symbolsでリンクエラー

- a.cppにfuncの定義がある場合、コンパイルできてa.cppのfuncが実行される。

- a.cppとb.cppにfuncの定義があると、duplicate symbolsでリンクエラー

    - b.cppの関数がvoid func(int a);であればコンパイルできaのfuncが実行される
        int func(void)だとダメ。

- a側にstaticをつけると、コンパイルできbのfuncが呼び出される

 */
