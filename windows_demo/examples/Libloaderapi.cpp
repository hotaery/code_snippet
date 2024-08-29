#include <windows.h>
#include <map>
#include <string>
#include <iostream>

typedef void(*TestCase)();

std::map<std::string, TestCase> test_case_map;

void GetModuleFileNameADemo() 
{
    char szapipath[MAX_PATH];
	memset(szapipath,0,MAX_PATH);
	GetModuleFileNameA(NULL,szapipath,MAX_PATH);
    std::cout << szapipath << std::endl;
}

int main(int argc, char* argv[]) 
{
    test_case_map.emplace("GetModuleFileNameA", GetModuleFileNameADemo); 

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            auto iter = test_case_map.find(std::string(argv[i]));
            if (iter == test_case_map.end()) {
                std::cerr << argv[1] << " not found" << std::endl;
            } else {
                iter->second();
            }
        }
    } else {
        for (auto kv : test_case_map) {
            kv.second();
        }
    }
    return 0;
}