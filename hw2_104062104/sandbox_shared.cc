#include "sandbox_shared.h"
#include <vector>


#define LOAD_FUNCTION_PTR(func_name, handle) \
    func_name##_ptr = reinterpret_cast<decltype(func_name) *>(dlsym(handle, #func_name));


int init_dl(){
    static int inited = 0;
    if(inited) return 1;
    void* dl_handle = dlopen("libc.so.6",RTLD_LAZY);

    LOAD_FUNCTION_PTR(chdir, dl_handle);
    LOAD_FUNCTION_PTR(chmod, dl_handle);
    LOAD_FUNCTION_PTR(chown, dl_handle);
    LOAD_FUNCTION_PTR(creat, dl_handle);
    LOAD_FUNCTION_PTR(fopen, dl_handle);
    LOAD_FUNCTION_PTR(link, dl_handle);
    LOAD_FUNCTION_PTR(mkdir, dl_handle);
    LOAD_FUNCTION_PTR(opendir, dl_handle);
    LOAD_FUNCTION_PTR(readlink, dl_handle);
    LOAD_FUNCTION_PTR(remove, dl_handle);
    LOAD_FUNCTION_PTR(rename, dl_handle);
    LOAD_FUNCTION_PTR(rmdir, dl_handle);
    LOAD_FUNCTION_PTR(stat, dl_handle);
    LOAD_FUNCTION_PTR(symlink, dl_handle);

    inited = 1;
    return inited;
}



int chdir(const char* path){
    init_dl();
    printf("chdir %s\n", path);
    return chdir_ptr(path);
}


int chmod(const char* path, mode_t mode){
    init_dl();
    printf("chmod %s %s\n", path, mode);
    return chmod_ptr(path, mode);
}

int chown(const char* path, uid_t uid, gid_t gid){
    init_dl();
    printf("chown %s %d %d\n", path, uid, gid);
    return chown_ptr(path,uid,gid);
}

int creat(const char* path, mode_t mode){
    init_dl();
    printf("chown %s %d \n", path, mode);
    return creat_ptr(path,mode);
}
FILE* fopen(const char* path, const char* mode){
    init_dl();
    printf("creat %s %s\n", path, mode);
    return fopen_ptr(path, mode);
}
int link(const char* oldpath, const char* path){
    init_dl();
    printf("link %s %s \n", oldpath, path);
    return link_ptr(oldpath, path);
}
int mkdir(const char* path, mode_t mode){
    init_dl();
    printf("mkdir %s %d\n", path, mode);
    return mkdir_ptr(path,mode);
}
DIR *opendir(const char* path){
    init_dl();
    printf("opendir %s\n", path);
    return opendir_ptr(path);
}
ssize_t readlink(const char *__restrict__ path, char *__restrict__ buf, size_t bufsize){
    init_dl();
    printf("readlink %s %ld %d\n", path, (unsigned long)buf, bufsize);
    return readlink(path, buf,bufsize);
}

int remove(const char* path){
    init_dl();
    printf("remove %s\n", path);
    return remove_ptr(path);
}
int rename(const char* old, const char* new_name){
    init_dl();
    printf("rename %s %s\n", old, new_name);
    return rename_ptr(old, new_name);
}

int rmdir(const char* path){
    init_dl();
    printf("rmdir %s\n", path);
    return rmdir_ptr(path);
}


int stat(const char *__restrict__ path, struct stat *__restrict__ buf){
    init_dl();
    printf("stat %s %ld\n", path, (unsigned long)buf);
    return stat_ptr(path, buf);
}


int symlink(const char* old, const char* new_name){
    init_dl();
    printf("symlink %s %s\n", old, new_name);
    return symlink_ptr(old, new_name);
}
