 ///
 /// Config.cpp
 /// Created by stabey(stabeyzhou@gmail.com).
 /// 2018-07-11 21:25:14
 /// @Brief: 
 ///
 

#include "Config.h"

Config* Config::_Instance = NULL;

Config::Config(const string& path){
    
    ifstream is(path);
    string section;
    string content;
    while(is >> section >> content){
        _configMap.insert(make_pair(section, content));
    }
    is.close();
}
