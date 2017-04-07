#ifndef APPNAME_APPPREFIXRUNACTION_H
#define APPNAME_APPPREFIXRUNACTION_H


#include <G4UserRunAction.hh>
#include <G4ios.hh>

class APPPREFIXRunAction : public G4UserRunAction{

public:
    APPPREFIXRunAction();
    ~APPPREFIXRunAction();
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
};


#endif //APPNAME_APPPREFIXRUNACTION_H
