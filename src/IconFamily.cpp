#include "IconFamily.hpp"
#include <cstdio>
#include <fstream>
#include <stdexcept>
#include <string>
#include "3rd_party/json.hpp"
using json = nlohmann::json;

IconFamily::IconFamily(const std::string &ConfFile)
{
    if(ConfFile.empty()){
        icon[InternalIcon] = " ";
        icon[LeafIcon] = " ";
        return;
    }

    std::fstream ConfFileStream(ConfFile);
    // 在处理命令行参数时保证了文件的存在
    json ConfFileJson;
    std::string IconString;

    try{
        ConfFileStream >> ConfFileJson;

        IconString = ConfFileJson["InternalIcon"].dump();
        if(IconString[0] != '"')
            throw std::logic_error("Loading InternalIcon: except string but read " + IconString);
        icon[InternalIcon] = IconString.substr(1, IconString.length() - 2);

        IconString = ConfFileJson["LeafIcon"].dump();
        if(IconString[0] != '"')
            throw std::logic_error("Loading LeafIcon: except string but read " + IconString);
        icon[LeafIcon] = IconString.substr(1, IconString.length() - 2);
    }catch(const std::exception &e){
        printf("Error when parsing icon family configuration file %s:\n", ConfFile.c_str());
        puts(e.what());
        exit(1);
    }
}
