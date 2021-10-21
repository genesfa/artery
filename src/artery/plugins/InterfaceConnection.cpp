//
// Created by vagrant on 10/21/21.
//


#include "InterfaceConnection.h"


std::ofstream myfile;

InterfaceConnection::InterfaceConnection()  {

}




InterfaceConnection::~InterfaceConnection() {
    myfile.close();
}

void InterfaceConnection::closeFile(){
    myfile.close();
}
void InterfaceConnection::openFile(){
     myfile.open("/home/vagrant/Test2.csv");
}

void InterfaceConnection::writeToFile(const std::string& vehicleId, const std::string& valueName, const std::string& value) {

    myfile << "Node:" << "  " << vehicleId;
    myfile << "\n";
    myfile << valueName << "  " << value; // << getVehicleController()->getVehicleId();
    myfile << "\n";
    myfile << "\n";



}



/*void InterfaceConnection::writeToFile(std::string vehicleId, std::string valueName, std::string value) {
    std::cout << "Witzig ";

}*/
