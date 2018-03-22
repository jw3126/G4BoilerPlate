#ifndef APPNAME_APPPREFIXTrackingAction_h
#define APPNAME_APPPREFIXTrackingAction_h 1

#include "G4UserTrackingAction.hh"

class APPPREFIXTrackingAction : public G4UserTrackingAction 
{
public:
  APPPREFIXTrackingAction();
  virtual ~APPPREFIXTrackingAction(){};
   
  virtual void PreUserTrackingAction(const G4Track*);
  virtual void PostUserTrackingAction(const G4Track*);
  
};

#endif
