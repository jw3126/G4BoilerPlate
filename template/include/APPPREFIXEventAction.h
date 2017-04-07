#ifndef APPNAME_APPPREFIXEVENTACTION_H
#define APPNAME_APPPREFIXEVENTACTION_H


#include <G4UserEventAction.hh>
#include "APPPREFIXRunAction.h"

class APPPREFIXEventAction : public G4UserEventAction{

public:
    APPPREFIXEventAction();
    ~APPPREFIXEventAction();
    virtual void BeginOfEventAction(const G4Event* );
    virtual void EndOfEventAction(const G4Event* );
};


#endif //APPNAME_APPPREFIXEVENTACTION_H
