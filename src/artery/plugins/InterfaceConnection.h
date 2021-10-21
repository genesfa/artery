//
// Created by vagrant on 10/21/21.
//

#ifndef ARTERY_INTERFACECONNECTION_H
#define ARTERY_INTERFACECONNECTION_H
#include <fstream>
#include <iostream>


class InterfaceConnection {
public:
    ~InterfaceConnection();
    InterfaceConnection();
    static void writeToFile(const std::string&, const std::string&, const std::string&);
    static void closeFile();
    static void openFile();
};


#endif //ARTERY_INTERFACECONNECTION_H
