//
// Created by reut on 16/12/18.
//

#ifndef FLIGHT_MAPS_H
#define FLIGHT_MAPS_H

#include <map>
#include <string>
#include "Command.h"
using namespace std;


class Maps {
private:
    map<string,double > symbolTable;
    map<string, Command*> commandMap;
    DataReaderServer* server1 = new DataReaderServer();
public:
    void setSymbel(string var, double value);
    double getSymbol(string var);
    Command* getCommand(string comamnd);
    map<string,double >* getSymbolMap();
    void initMapCom();

};


#endif //FLIGHT_MAPS_H
