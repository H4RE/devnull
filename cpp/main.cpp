#include <iostream>
#include <unistd.h>

int main(int argc, char** argv)
{
    // すぐ出力
    std::cout << "test" << std::endl;
    // すぐ出力
    std::cout << "test\n" << std::flush;


    // 3秒後に出力
    std::cout << "test";
    sleep(3);
    return 0;
}
