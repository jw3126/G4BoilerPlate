#ifndef APPNAME_APPPREFIXSTEPPINGACTION_H
#define APPNAME_APPPREFIXSTEPPINGACTION_H

#include <G4UserSteppingAction.hh>
#include <G4ios.hh>
#include "G4Step.hh"
#include "G4StepPoint.hh"


class APPPREFIXSteppingAction : public G4UserSteppingAction {

public:
    APPPREFIXSteppingAction();
    ~APPPREFIXSteppingAction();
    virtual void UserSteppingAction(const G4Step*);
};


#endif //APPNAME_APPPREFIXSTEPPINGACTION_H
