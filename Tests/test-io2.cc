// test-io2.cc
#include <libxmz/io.hpp>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <cerrno>

static int fails = 0;
#define CHECK(cond,msg)						\
do {										\
	if(!(cond)) {							\
		fprintf(stderr,"[FAIL] %s\n",msg);	\
		fails++;							\
	} else									\
		fprintf(stderr,"[PASS] %s\n",msg);	\
} while(0)

static void t_nonblock()
{
    fprintf(stderr, "t_nonblock\n");
    int b = fcntl(1, F_GETFL, 0) & O_NONBLOCK;
    xmz::println("probe");
    int a = fcntl(1, F_GETFL, 0) & O_NONBLOCK;
    CHECK(b == a, "println must not modify stdout O_NONBLOCK");
}

static void t_no_hang()
{
    fprintf(stderr, "t_no_hang\n");
    int fds[2];
    if (::pipe(fds) != 0) { fprintf(stderr, "  skip: pipe\n"); return; }
    fcntl(fds[0], F_SETFL, O_NONBLOCK); /* the reading end does not read, so the writing end is full */
    int before = fcntl(fds[1], F_GETFL, 0) & O_NONBLOCK;
    std::string big(300000, 'X');
    auto buf = xmz::io::get_buffer(fds[1]);
    bool ok = buf->write_all(big.data(), big.size(), 100); /* the timeout is 100 milliseconds. The test is whether it will get stuck. */
    int after = fcntl(fds[1], F_GETFL, 0) & O_NONBLOCK;
    CHECK(true, "write_all returned (did not hang)");
    CHECK(before == after, "write_all must restore fd O_NONBLOCK flag");
    CHECK(ok == false, "write_all into full pipe should report failure");
    fprintf(stderr, "  (ok=%d bytes_written=%zu/300000)\n", ok, buf->bytes_written());
    ::close(fds[0]); ::close(fds[1]);
}

int main()
{
    t_nonblock();
    t_no_hang();
    fprintf(stderr, "%s (failures=%d)\n", fails ? "[FAIL]" : "[PASS]", fails);
    return fails ? 1 : 0;
}

