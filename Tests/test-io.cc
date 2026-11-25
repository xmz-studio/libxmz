#include <libxmz/io.hpp>
#include <libxmz/log.hpp>
#include <string>

int main(int argc, char* argv[])
{
    (void)argc;
    xmz::println("hello I am", argv[0]);
    xmz::perrln("this is error msg");
    xmz::fprintln(xmz::stdout, "this is a stdout msg from xmz::fprintln output");
    xmz::fprintln(xmz::stderr, "this is a stderr msg form xmz::fprintln output");
    return 0;
}
