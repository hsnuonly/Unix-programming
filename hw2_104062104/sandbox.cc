#include <dlfcn.h>
#include <iostream>
#include <sys/types.h>
#include "sandbox_shared.h"
#include <functional>
using namespace std;

int main(int argc, char* argv[])
{
    void *dl_handle = dlopen("./sandbox.so", RTLD_LAZY);
    if(!dl_handle){
        std::cerr << "Unable to open sandbox.so\n";
        return -1;
    }

    string func_name = argv[1];
    if(func_name=="chdir"){
        std::function<decltype(chdir)> func = reinterpret_cast<decltype(chdir)*>(dlsym(dl_handle, func_name.c_str()));
        // func("/");
    }
    else if(func_name=="chmod"){
        std::function<decltype(chmod)> func = reinterpret_cast<decltype(chmod)*>(dlsym(dl_handle, func_name.c_str()));
        // func("/");
    }
    
    return 0;
}