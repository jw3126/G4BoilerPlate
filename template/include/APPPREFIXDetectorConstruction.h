#ifndef APPNAME_APPPREFIXDETECTORCONSTRUCTION_H
#define APPNAME_APPPREFIXDETECTORCONSTRUCTION_H


#include <G4VUserDetectorConstruction.hh>

class APPPREFIXDetectorConstruction: public G4VUserDetectorConstruction {

public:
    APPPREFIXDetectorConstruction(): G4VUserDetectorConstruction() {};
    ~APPPREFIXDetectorConstruction(){};
    virtual G4VPhysicalVolume* Construct();
};


#endif //APPNAME_APPPREFIXDETECTORCONSTRUCTION_H
