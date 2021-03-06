#ifndef Fireworks_Core_FW3DViewBase_h
#define Fireworks_Core_FW3DViewBase_h
// -*- C++ -*-
//
// Package:     Core
// Class  :     FW3DViewBase
//
/**\class FW3DViewBase FW3DViewBase.h Fireworks/Core/interface/FW3DViewBase.h

   Description: <one line class summary>

   Usage:
    <usage>

 */
//
// Original Author:  Chris Jones
//         Created:  Thu Feb 21 11:22:37 EST 2008
//

// system include files

// user include files
#include "Rtypes.h"
#include "Fireworks/Core/interface/FWEveView.h"
#include "Fireworks/Core/interface/FWLongParameter.h"
#include "Fireworks/Core/interface/FWBoolParameter.h"
// forward declarations
class TEveElementList;
class TEveGeoShape;
class TEveWindowSlot;

class FW3DViewGeometry;
class FWColorManager;
class TGLClip;
class TEveLine;

class FW3DViewDistanceMeasureTool;

class FW3DViewBase : public FWEveView
{
public:
   FW3DViewBase(TEveWindowSlot*, FWViewType::EType);
   virtual ~FW3DViewBase();

   // ---------- const member functions ---------------------

   virtual void addTo(FWConfiguration&) const;
   virtual void populateController(ViewerParameterGUI&) const;

   // ---------- static member functions --------------------

   // ---------- member functions ---------------------------
   virtual void setContext(const fireworks::Context&);
   virtual void setFrom(const FWConfiguration&);

   // To be fixed.
   void updateGlobalSceneScaleParameters();

   FW3DViewDistanceMeasureTool* getDMT() { return m_DMT;}
   virtual bool requestGLHandlerPick() const;
   void setCurrentDMTVertex(double x, double y, double z);

private:
   FW3DViewBase(const FW3DViewBase&);    // stop default

   const FW3DViewBase& operator=(const FW3DViewBase&);    // stop default

   // ---------- member data --------------------------------
   FW3DViewGeometry*  m_geometry;
   TGLClip*           m_glClip;

   // parameters
   FWEnumParameter m_showMuonBarrel;
   FWBoolParameter m_showMuonEndcap;
   FWBoolParameter m_showPixelBarrel;
   FWBoolParameter m_showPixelEndcap;
   FWBoolParameter m_showTrackerBarrel;
   FWBoolParameter m_showTrackerEndcap;

   FWEnumParameter m_rnrStyle;
   FWBoolParameter m_clipParam;
   FWBoolParameter m_selectable;

   FWEnumParameter m_cameraType;

   FW3DViewDistanceMeasureTool* m_DMT;
   TEveLine* m_DMTline;

   void selectable( bool );
   void sceneClip( bool );
   void rnrStyle(long);
   void showMuonBarrel( long );
   void setCameraType(long);
};


#endif
