#include <functional>
#include <dlfcn.h>
#include <unistd.h>
#include <dirent.h>
#include <utility>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DECLARE_FUNCTION_PTR(func_name) \
    std::function<decltype(func_name)> func_name##_ptr = nullptr

DECLARE_FUNCTION_PTR(chdir);
DECLARE_FUNCTION_PTR(chmod);
DECLARE_FUNCTION_PTR(chown);
DECLARE_FUNCTION_PTR(creat);
DECLARE_FUNCTION_PTR(fopen);
DECLARE_FUNCTION_PTR(link);
DECLARE_FUNCTION_PTR(mkdir);
// DECLARE_FUNCTION_PTR(open);
// DECLARE_FUNCTION_PTR(openat);
DECLARE_FUNCTION_PTR(opendir);
DECLARE_FUNCTION_PTR(readlink);
DECLARE_FUNCTION_PTR(remove);
DECLARE_FUNCTION_PTR(rename);
DECLARE_FUNCTION_PTR(rmdir);
DECLARE_FUNCTION_PTR(stat);
DECLARE_FUNCTION_PTR(symlink);

extern "C"{
    // int chdir(const char*);
    // int chmod(const char*, mode_t);
    // int chown(const char*, uid_t, gid_t);
    // int creat(const char*, mode_t);
    // FILE *_fopen(const char *,const char* );
    // int link(const char* oldpath, const char*);
    // int mkdir(const char*, mode_t);
    // int open(const char*, int);
    // int openat(int, const char*,int);
    // struct __dirstream *_opendir(const char*);
}