#include "artery/traci/Cast.h"
#include "artery/traci/VehicleMobility.h"
#include <omnetpp/cwatch.h>
#include <fstream>
#include "artery/plugins/InterfaceConnection.h"
using namespace traci;
//std::ofstream myfile;
namespace artery
{
VehicleMobility::~VehicleMobility()  {
   InterfaceConnection::closeFile();
}
void VehicleMobility::initializeSink(std::shared_ptr<API> api, std::shared_ptr<VehicleCache> cache, const Boundary& boundary)
{
    ASSERT(api);
    ASSERT(cache);
    mTraci = api;
    mVehicleId = cache->getId();
    mNetBoundary = boundary;
    mController.reset(new VehicleController(api, cache));
    //myfile.open("/home/vagrant/Test.txt");
    InterfaceConnection::openFile();

}

void VehicleMobility::initializeVehicle(const TraCIPosition& traci_pos, TraCIAngle traci_heading, double traci_speed)
{
    const auto opp_pos = position_cast(mNetBoundary, traci_pos);
    const auto opp_angle = angle_cast(traci_heading);
    initialize(opp_pos, opp_angle, traci_speed);
}

void VehicleMobility::updateVehicle(const TraCIPosition& traci_pos, TraCIAngle traci_heading, double traci_speed)
{
    const auto opp_pos = position_cast(mNetBoundary, traci_pos);
    const auto opp_angle = angle_cast(traci_heading);
    update(opp_pos, opp_angle, traci_speed);


    //std::cout << "JOJ ist ein idiot " << traci_speed;
   // myfile << traci_speed <<"\n" << getVehicleController()->getVehicleId()<< "\n";
    InterfaceConnection::writeToFile(getVehicleController()->getVehicleId(), "Traci Speed", std::to_string( traci_speed));
    InterfaceConnection::writeToFile(getVehicleController()->getVehicleId(), "traci_pos.x", std::to_string( traci_pos.x));
    InterfaceConnection::writeToFile(getVehicleController()->getVehicleId(), "traci_pos.y", std::to_string( traci_pos.y));
    InterfaceConnection::writeToFile(getVehicleController()->getVehicleId(), "traci_pos.z", std::to_string( traci_pos.z));
    InterfaceConnection::writeToFile(getVehicleController()->getVehicleId(), "Heading degree", std::to_string( traci_heading.degree));

}

VehicleController* VehicleMobility::getVehicleController()
{
    ASSERT(mController);
    return mController.get();
}

} // namespace artery
