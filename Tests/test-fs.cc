#include <libxmz/io.hpp>
#include <libxmz/fs.hpp>
#include <libxmz/aux.hpp>
#include <string>

int main() {
	std::string filename	= "libxmz-test-fs.txt";
	std::string writetext	= "hello";
	xmz::println("libxmz fs test 1");
	xmz::println("test writefile");
	xmz::fs::touch(filename);
	if (xmz::aux::is_file(filename))
		xmz::println("file:", filename, "created successfully");
	else {
		xmz::println("file:", filename, "created failed");
		return 1;
	}
	std::string readtext = xmz::fs::readfile_str(filename);
	xmz::fs::writefile(writetext, filename);
	if (readtext == writetext)
		xmz::println("write successfully");
	else {
		xmz::println("write failed");
		return 1;
	}
	xmz::fs::rmfile(filename);
	if (!xmz::aux::is_file(filename))
		xmz::println("remove successfully");
	else {
		xmz::println("remove failed");
		return 1;
	}
	return 0;
}
